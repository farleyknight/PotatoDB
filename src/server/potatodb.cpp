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
    file_mgr_       (),
    disk_mgr_       (file_mgr_),
    buff_mgr_       (pool_size(), disk_mgr_, log_mgr_),
    log_mgr_        (disk_mgr_),
    checkpoint_mgr_ (txn_mgr_, log_mgr_, buff_mgr_),
    table_mgr_      (disk_mgr_, lock_mgr_, log_mgr_, buff_mgr_),
    txn_mgr_        (lock_mgr_, log_mgr_, table_mgr_),
    catalog_        (),
    exec_eng_       (buff_mgr_, txn_mgr_, catalog_)
{}

void PotatoDB::reset_installation() {
  log_mgr_.disable_logging();

  disk_mgr_.remove_all_files();
  disk_mgr_.setup_db_directory();
  disk_mgr_.setup_log_file();

  build_system_catalog();
}

void PotatoDB::rebuild_system_catalog() {
  disk_mgr_.remove_table_files();
  build_system_catalog();
}

bool PotatoDB::file_exists(fs::path file_path) const {
  return disk_mgr_.file_exists(file_path);
}

fs::path PotatoDB::table_file_for(const string& table_name) {
  return disk_mgr_.table_file_for(table_name);
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

StatementResult PotatoDB::run(const string& statement) {
  try {
    auto plan = sql_to_plan(statement);
    // Create and run the txn
    auto &txn = txn_mgr_.begin();
    ExecCtx exec_ctx(txn,
                     buff_mgr_,
                     lock_mgr_,
                     txn_mgr_,
                     table_mgr_,
                     catalog_);

    if (plan->is_query()) {
      auto result_set = exec_eng_.query(move(plan), txn, exec_ctx);
      txn_mgr_.commit(txn);
      logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
      logger->debug("[PotatoDB] Returning result set");
      return StatementResult(move(result_set));
    } else if (plan->type() == PlanType::CREATE_TABLE) {
      // CREATE TABLE``
      auto create_table_plan = dynamic_cast<CreateTablePlan*>(plan.get());
      auto table_name        = create_table_plan->table_name();
      auto column_list       = create_table_plan->column_list().list();
      auto message           = exec_eng_.execute(move(plan), txn, exec_ctx);
      run_create_table(table_name, column_list, txn, exec_ctx);
      txn_mgr_.commit(txn);
      logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
      return StatementResult(message);
    } else {
      auto message = exec_eng_.execute(move(plan), txn, exec_ctx);
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


// TODO: Move this logic into the SystemCatalog class, likely as a static method
void PotatoDB::run_create_table(const table_name_t table_name,
                                const vector<ColumnDefExpr> column_list,
                                Txn& txn,
                                ExecCtx& exec_ctx)
{
  // TODO:
  // 1) Run the actual CREATE TABLE plan
  // 2) Run additional SQL for inserting the table into the `system_catalog`
  // 3) Run additional SQL for inserting each column from the table into
  //    the `system_catalog`

  // INSERT INTO system_catalog VALUES (table_name...)
  auto insert_table_sql  = SystemCatalog::insert_table_sql_for(table_name);
  auto insert_table_plan = sql_to_plan(insert_table_sql);
  exec_eng_.execute(move(insert_table_plan), txn, exec_ctx);

  logger->debug("[PotatoDB] %%%%%%%%%%%%%%%%%%%%%%");
  logger->debug("[PotatoDB] Inserting the columns");
  logger->debug("[PotatoDB] Column count: " + std::to_string(column_list.size()));
  logger->debug("[PotatoDB] %%%%%%%%%%%%%%%%%%%%%%");

  for (const auto &col : column_list) {
    auto insert_column_sql
      = SystemCatalog::insert_column_sql_for(table_name, col);

    auto insert_column_plan = sql_to_plan(insert_column_sql);
    exec_eng_.execute(move(insert_column_plan), txn, exec_ctx);
  }
}

void PotatoDB::build_system_catalog() {
  logger->debug("[PotatoDB] Checking if system_catalog table exists");
  if (disk_mgr().table_file_exists("system_catalog")) {
    logger->debug("[PotatoDB] Begin loading system catalog");
    SystemCatalog::load(*this);
  } else {
    logger->debug("[PotatoDB] Begin creating system catalog");
    SystemCatalog::create(*this);
    buff_mgr_.flush_all();
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
    logger->debug("[PotatoDB] An error occurred during startup() : " + std::string(e.what()));
  }
}
