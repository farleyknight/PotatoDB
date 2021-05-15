#include "server/potatodb.hpp"
#include "server/client_socket.hpp"
#include "server/system_catalog.hpp"

#include "parser/sql_parser.hpp"
#include "plans/plan_factory.hpp"

PotatoDB potatodb;

PotatoDB::PotatoDB()
  : server_    (this),
    file_mgr_  (),
    disk_mgr_  (file_mgr_),
    buff_mgr_  (pool_size(), disk_mgr_, log_mgr_),
    log_mgr_   (disk_mgr_),
    table_mgr_ (disk_mgr_, lock_mgr_, log_mgr_, buff_mgr_),
    txn_mgr_   (lock_mgr_, log_mgr_, table_mgr_),
    catalog_   (),
    exec_eng_  (buff_mgr_, txn_mgr_, catalog_)
{}

void PotatoDB::reset_installation() {
  disk_mgr_.remove_all_files();
  disk_mgr_.setup_db_directory();
  disk_mgr_.setup_log_file();

  build_system_catalog();
}

bool PotatoDB::file_exists(fs::path file_path) const {
  return file_mgr_.file_exists(file_path);
}

fs::path PotatoDB::table_file_for(const string& table_name) {
  return disk_mgr_.table_file_for(table_name);
}

StatementResult PotatoDB::run_statement(const string& statement) {
  try {
    // TODO: Rename as_exprs to as_stmts
    auto exprs = SQLParser::as_exprs(statement);
    // TODO: Allow for multiple statements
    assert(exprs.size() > 0);
    auto plan = PlanFactory::create(catalog_, move(exprs[0]));

    // Create and run the txn
    auto &txn = txn_mgr_.begin();
    ExecCtx exec_ctx(txn,
                     buff_mgr_,
                     lock_mgr_,
                     txn_mgr_,
                     table_mgr_,
                     catalog_);

    if (plan->is_query()) {
      auto result_set = exec_eng_.query(move(plan),
                                        txn,
                                        exec_ctx);
      txn_mgr_.commit(txn);
      return StatementResult(move(result_set));
    } else {
      auto message = exec_eng_.execute(move(plan),
                                       txn,
                                       exec_ctx);
      return StatementResult(message);
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return StatementResult(e.what());
  }
}

void PotatoDB::build_system_catalog() {
  // std::cout << "Begin loading system catalog" << std::endl;
  // NOTE: These steps only need to be run if the system_catalog
  // table does not already exist.
  //
  // TODO: Write a conditional here to check for that table.
  //
  // TODO: Wrap this all in a try block and capture any errors
  run_statement(SystemCatalog::create_table_sql);
  run_statement(SystemCatalog::insert_sql);
}

// TODO: During testing, we sometimes want to delete all database files.
// Write a method here to delete them.

void PotatoDB::start_server() {
  // TODO: Add logging for this line
  std::cout << "Start PotatoDB Server (0.1.0)" << std::endl;
  server_.set_port(port_);
  server_.on_read([&](WPtr<ClientSocket> socket_ptr) {
    if (auto client = socket_ptr.lock()) {
      auto statement = client->read();
      // std::cout << "Client Socket got query " << statement << std::endl;

      try {
        auto result = client->session().run_statement(statement);
        client->write(result.to_string());
      } catch (std::exception &e) {
        // TODO: Send better error message
        client->write("Got an error! :(");
      }
    } else {
      // TODO: Logger
      std::cout << "Could not get lock!" << std::endl;
    }
  });

  // TODO: Allow port customization
  // TODO: Add logging for this line
  std::cout << "Server listening on port " << port_ << std::endl;
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

void PotatoDB::startup() {
  state_ = ServerState::STARTING_UP;

  build_system_catalog();
  verify_system_files();

  start_server();
  state_ = ServerState::RUNNING;
}
