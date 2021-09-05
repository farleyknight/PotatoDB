#include "server/potatodb.hpp"
#include "server/client_socket.hpp"
#include "server/system_catalog.hpp"

#include "parser/sql_parser.hpp"
#include "plans/plan_factory.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

sptr<spdlog::logger> logger =
  spdlog::basic_logger_mt("basic_logger", "logs.txt", true);

PotatoDB potatodb;

PotatoDB::PotatoDB()
  : server_         (this),
    //
    file_mgr_       (), // TODO: We should pass in the DB config here
    buff_mgr_       (pool_size(), file_mgr_, log_mgr_),
    //
    log_mgr_        (file_mgr_),
    checkpoint_mgr_ (txn_mgr_, log_mgr_, buff_mgr_),

    //
    table_mgr_      (file_mgr_, lock_mgr_, log_mgr_, buff_mgr_),
    index_mgr_      (file_mgr_, lock_mgr_, log_mgr_, buff_mgr_),
    // TODO: Need to add model_mgr_ here when I get around to
    // doing CREATE MODEL
    sys_catalog_    (table_mgr_, index_mgr_),
    catalog_        (table_mgr_, index_mgr_, sys_catalog_),

    //
    txn_mgr_        (lock_mgr_, log_mgr_, table_mgr_),
    exec_eng_       (buff_mgr_, txn_mgr_, catalog_)
{}

void PotatoDB::reset_installation() {
  log_mgr_.disable_logging();

  file_mgr_.remove_all_files();
  file_mgr_.setup_db_directory();
  file_mgr_.setup_log_file();

  build_system_catalog();
}

void PotatoDB::rebuild_system_catalog() {
  file_mgr_.remove_table_files();
  build_system_catalog();
}

bool PotatoDB::file_exists(fs::path file_path) const {
  return file_mgr_.file_exists(file_path);
}

fs::path PotatoDB::table_file_for(const string& table_name) {
  return file_mgr_.table_file_for(table_name);
}

ptr<BasePlan> PotatoDB::sql_to_plan(const string& statement) const {
  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  logger->debug(statement);
  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

  // TODO: Rename as_exprs to as_stmts
  auto exprs = SQLParser::as_exprs(statement);
  // TODO: Allow for multiple statements
  if (exprs.size() == 0) {
    logger->debug("[PotatoDB] No exprs for : " + statement);
  }

  assert(exprs.size() > 0);
  return PlanFactory::create(*this, move(exprs[0]));
}

StatementResult
PotatoDB::run(const string& statement) {
  try {
    auto plan     = sql_to_plan(statement);
    // Create and run the txn
    auto &txn     = txn_mgr_.begin();
    auto exec_ctx = make_exec_ctx(txn);
    // TODO: We can remove this `is_query` check if we allow all
    // SQL to return some kind of result set, even if that's just
    // a message that the command was successfully executed.
    if (plan->is_query()) {
      auto result_set = exec_eng_.query(move(plan), exec_ctx);
      txn_mgr_.commit(txn);
      logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
      logger->debug("[PotatoDB] Returning result set");
      return StatementResult(move(result_set));
    } else {
      auto message = exec_eng_.execute(move(plan), exec_ctx);
      txn_mgr_.commit(txn);
      logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
      return StatementResult(message);
    }
  } catch (std::exception& e) {
    logger->debug("[PotatoDB] XXXXXXXXXXXXXXXXXXXXXXXXXXX");
    logger->debug("[PotatoDB] ERROR MESSAGE " + std::string(e.what()));
    logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    return StatementResult(e.what());
  }
}

void PotatoDB::build_system_catalog() {
  for (const auto file_id : file_mgr_.table_file_ids()) {
    auto table_oid    = table_mgr_.table_oid_for(file_id);
    auto table_schema = table_mgr_.read_table_schema(file_id);
    catalog_.load_table(table_oid, table_schema);
  }

  for (const auto file_id : file_mgr_.index_file_ids()) {
    auto index_oid    = index_mgr_.index_oid_for(file_id);
    auto index_schema = index_mgr_.read_index_schema(catalog_, file_id);
    catalog_.load_index(index_oid, index_schema);
  }
}

// TODO: During testing, we sometimes want to delete all database files.
// Write a method here to delete them.

void PotatoDB::start_server() {
  state_ = ServerState::RUNNING;

  // TODO: Add logging for this line
  logger->debug("[PotatoDB] Start PotatoDB Server (0.1.0)");
  server_.set_port(port_);
  server_.on_read([&](WPtr<ClientSocket> socket_ptr) {
    if (auto client = socket_ptr.lock()) {
      auto statement = client->read();
      logger->debug("[PotatoDB] Client Socket got query " + statement);

      try {
        auto result = client->session().run_statement(statement);
        logger->debug("[PotatoDB] Sending Payload " + result.to_payload());
        client->write(result.to_payload());
      } catch (std::exception &e) {
        // TODO: Send better error message
        client->write("Got an error! :(");
      }
    } else {
      // TODO: Logger
      logger->debug("[PotatoDB] Could not get lock!");
    }
  });

  // TODO: Allow port customization
  // TODO: Add logging for this line
  logger->debug("[PotatoDB] Server listening on port " + std::to_string(port_));
  server_.accept_connections();
}

void PotatoDB::verify_system_files() {
  // TODO: During system start up, we should be
  // 1) Looking for all existing tables
  // 2) verifying that each table has it's own file
  // 3) and that every file has it's own table. (or is the log file)
  //
  // Write a method to verify everything is lined up correctly.
  //
  // TODO: This method should also
  // 1) Read the first 4 bytes and confirm that in hexadecimal they spell:
  //    B07A70DB
  //    POTATODB
  // 2) Read the file_name_t off of the file header block
  //    It should be the same as the file's actual name
  // 3) We should have a file dedicated to just holding metadata
  //    about the file_ids for each file.
  //    Call it "files.sys"
  //    Store metadata about files here
  // 4) ???
}

bool PotatoDB::is_logging_enabled() const {
  return log_mgr_.is_logging_enabled();
}

void PotatoDB::run_flush_thread() {
  log_mgr_.run_flush_thread();
}

void PotatoDB::startup() {
  try {
    logger->debug("[PotatoDB] Warming up the PotatoDB server");
    state_ = ServerState::STARTING_UP;

    logger->debug("[PotatoDB] Building system catalog");
    build_system_catalog();
    logger->debug("[PotatoDB] Verifying system files");
    verify_system_files();

  } catch (std::exception &e) {
    logger->debug("[PotatoDB] An error occurred during startup() : "
                  + std::string(e.what()));
  }
}
