
#include "server/potatodb.hpp"
#include "server/client_socket.hpp"
#include "parser/sql_parser.hpp"

PotatoDB potatodb;

PotatoDB::PotatoDB()
  : server_    (this),
    disk_mgr_  (),
    buff_mgr_  (pool_size(), disk_mgr_, log_mgr_),
    log_mgr_   (disk_mgr_),
    txn_mgr_   (lock_mgr_, log_mgr_, table_mgr_),
    file_mgr_  (disk_mgr_),
    table_mgr_ (disk_mgr_, file_mgr_, buff_mgr_, lock_mgr_, buff_mgr_),
    catalog_   (),
    exec_eng_  (buff_mgr_, txn_mgr_, catalog_)
{}

ptr<BasePlan> PotatoDB::build_plan(const ptr<BaseExpr>& expr) {
  // TODO: Figure out expr type
  // Based on type, create specific plan

  // TODO: CREATE TABLE plan!
  // 1) First check expr.type == CREATE_TABLE
  // 2) Extract out new table name, column defs
  // 3) Extract out primary key
  // 4) Make sure primary key is used (NEEDS BTREE FIRST!)
  if (expr->expr_type() == ExprType::CREATE_TABLE) {
    auto create_table_expr = dynamic_cast<CreateTableExpr*>(expr.get());
    auto table_name = create_table_expr->table().name();
    auto column_def_list = create_table_expr->column_defs();
    return make_unique<CreateTablePlan>(table_name, column_def_list);
  } else {
    return make_unique<SeqScanPlan>(QuerySchema::empty(),
                                    INVALID_TABLE_OID);
  }
}

ptr<ResultSet> PotatoDB::query(string statement) {
  try {
    // TODO: Rename as_exprs to as_stmts
    auto exprs = SQLParser::as_exprs(statement);
    // TODO: Allow for multiple statements
    assert(exprs.size() > 0);
    auto plan = build_plan(exprs[0]);

    // Create and run the txn
    auto &txn = txn_mgr_.begin();
    ExecCtx exec_ctx(txn,
                     buff_mgr_,
                     lock_mgr_,
                     txn_mgr_,
                     table_mgr_,
                     catalog_);

    auto result_set = exec_eng_.query(move(plan),
                                      txn,
                                      exec_ctx);

    txn_mgr_.commit(txn);
    return result_set;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return ResultSet::empty();
  }
}

void PotatoDB::execute(string statement) {
  try {
    // TODO: Rename as_exprs to as_stmts
    auto exprs = SQLParser::as_exprs(statement);
    // TODO: Allow for multiple statements
    assert(exprs.size() > 0);
    auto plan = build_plan(exprs[0]);

    // Create and run the txn
    auto &txn = txn_mgr_.begin();
    ExecCtx exec_ctx(txn,
                     buff_mgr_,
                     lock_mgr_,
                     txn_mgr_,
                     table_mgr_,
                     catalog_);

    exec_eng_.execute(move(plan),
                      txn,
                      exec_ctx);

    txn_mgr_.commit(txn);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

const string system_catalog_sql =
  "CREATE TABLE system_catalog ( " \

  "id         INTEGER PRIMARY KEY, "            \
  "type       INTEGER NOT NULL, "               \
  "name       VARCHAR(32) NOT NULL, "           \
  "table_name VARCHAR(32) NOT NULL, "           \
  "sql        VARCHAR(255) NOT NULL "           \

  ");";

void PotatoDB::build_system_catalog() {
  std::cout << "Begin loading system catalog" << std::endl;

  // TODO: Use some SQL here
  // 1) Write the necessary SQL [DONE?]
  // 2) Feed it to the parser [DONE?]
  // 3) Parser feeds it to the exec eng [DONE?]

  execute(system_catalog_sql);

  // 4) Need to add operator for creating a table [TODO]

  // 5) DiskMgr should create a TableFile?
  // 6) TableFile creates TableHeap
  // 7) TableHeap creates TablePage
  // 8) TablePage adds tuples to the `system_catalog`
}

void PotatoDB::start_server() {
  // TODO: Add logging for this line
  std::cout << "Start PotatoDB Server (0.1.0)" << std::endl;
  server_.set_port(port_);
  server_.on_read([&](WPtr<ClientSocket> socket_ptr) {
    if (auto client = socket_ptr.lock()) {
      auto statement = client->read();
      std::cout << "Client Socket got query " << statement << std::endl;

      try {
        auto result = client->session().query(statement);
        client->write(result->to_string());
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

void PotatoDB::startup() {
  build_system_catalog();
  start_server();
}
