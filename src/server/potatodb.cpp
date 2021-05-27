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

ptr<BasePlan> PotatoDB::sql_to_plan(const string& statement) const {
  std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
  std::cout << statement << std::endl;

  // TODO: Rename as_exprs to as_stmts
  auto exprs = SQLParser::as_exprs(statement);
  // TODO: Allow for multiple statements
  if (exprs.size() == 0) {
    std::cout << "No exprs for : " << statement << std::endl;
  }

  assert(exprs.size() > 0);
  return PlanFactory::create(catalog_, move(exprs[0]));
}

StatementResult PotatoDB::run_statement(const string& statement) {
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
      return StatementResult(move(result_set));
    } else if (plan->type() == PlanType::CREATE_TABLE) {
      return run_create_table(move(plan), txn, exec_ctx);
    } else {
      auto message = exec_eng_.execute(move(plan), txn, exec_ctx);
      return StatementResult(message);
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return StatementResult(e.what());
  }
}


// TODO: Move this logic into the SystemCatalog class, likely as a static method
StatementResult PotatoDB::run_create_table(ptr<BasePlan>&& plan,
                                           Txn& txn,
                                           ExecCtx& exec_ctx)
{
  auto create_table_plan = dynamic_cast<CreateTablePlan*>(plan.get());

  // TODO:
  // 1) Run the actual CREATE TABLE plan
  // 2) Run additional SQL for inserting the table into the `system_catalog`
  // 3) Run additional SQL for inserting each column from the table into
  //    the `system_catalog`

  auto table_name  = create_table_plan->table_name();
  auto column_list = create_table_plan->column_list().list();

  // CREATE TABLE
  auto message = exec_eng_.execute(move(plan), txn, exec_ctx);

  // INSERT INTO system_catalog VALUES (table_name...)
  auto insert_table_sql
    = SystemCatalog::create_table_sql_for(table_name);
  auto insert_table_plan = sql_to_plan(insert_table_sql);
  exec_eng_.execute(move(insert_table_plan), txn, exec_ctx);

  for (const auto &col : column_list) {
    // INSERT INTO system_catalog VALUES (column_name...)
    auto insert_column_sql
      = SystemCatalog::create_column_sql_for(table_name,
                                             col.name());
    // TODO: The line above does not include the column type.
    // Eventually we will want to include that information in the system catalog
    // so that the tables and their columns can be loaded from the proper table
    // file.

    auto insert_column_plan = sql_to_plan(insert_column_sql);
    exec_eng_.execute(move(insert_column_plan), txn, exec_ctx);
  }

  txn_mgr_.commit(txn);
  return StatementResult(message);
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

  run_statement(SystemCatalog::create_column_sql_for("system_catalog", "id"));
  run_statement(SystemCatalog::create_column_sql_for("system_catalog", "type"));
  run_statement(SystemCatalog::create_column_sql_for("system_catalog", "name"));
  run_statement(SystemCatalog::create_column_sql_for("system_catalog", "table_name"));
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
        client->write(result.to_payload());
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
