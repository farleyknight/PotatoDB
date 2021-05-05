
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
    // catalog_   (buff_mgr_, lock_mgr_, log_mgr_),
    table_mgr_ (disk_mgr_, buff_mgr_),
    catalog_   (),
    exec_eng_  (buff_mgr_, txn_mgr_, catalog_)
{}


void PotatoDB::build_catalog_table() {
  // TODO: Use some SQL here
  // 1) Write the necessary SQL [DONE?]
  // 2) Feed it to the parser [DONE?]
  // 3) Parser feeds it to the exec eng [DONE?]

  // potatodb.execute(system_table_sql);

  // 4) Need to add operator for creating a table [TODO]

  // 5) DiskMgr should create a TableFile?
  // 6) TableFile creates TableHeap
  // 7) TableHeap creates TablePage
  // 8) TablePage adds tuples to the `system_catalog`
}


ptr<BasePlan> PotatoDB::build_plan(UNUSED const BaseExpr& expr) {
  auto schema_ref = SchemaRef(SchemaType::QUERY, -1);
  return make_unique<SeqScanPlan>(schema_ref);
}

ptr<ResultSet> PotatoDB::execute(string query) {
  try {
    // TODO: Rename as_exprs to as_stmts
    auto exprs = SQLParser::as_exprs(query);
    // TODO: Allow for multiple statements
    assert(exprs.size() > 0);
    auto plan = build_plan(*exprs[0]);

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
    return ResultSet::empty();
  }
}

void PotatoDB::startup() {
  // TODO: Add logging for this line
  std::cout << "Start PotatoDB Server (0.1.0)" << std::endl;
  server_.set_port(port_);
  server_.on_read([&](WPtr<ClientSocket> socket_ptr) {
    if (auto client = socket_ptr.lock()) {
      auto query = client->read();
      std::cout << "Client Socket got query " << query << std::endl;

      try {
        auto result = client->session().execute(query);
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
