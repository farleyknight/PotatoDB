
#include "server/session.hpp"

Session::Session(PotatoDB* db)
  : db_        (db),
    disk_mgr_  (db->main_file_name()),
    log_mgr_   (disk_mgr_),
    buff_mgr_  (pool_size, disk_mgr_, log_mgr_),
    txn_mgr_   (lock_mgr_, log_mgr_),
    catalog_   (buff_mgr_, lock_mgr_, log_mgr_),
    table_mgr_ (disk_mgr_, buffer_mgr_),
    exec_eng_  (buff_mgr_, lock_mgr_, txn_mgr_, table_mgr_, catalog_)
{}

ResultSet Session::execute(String query) {
  try {
    // TODO: Rename as_exprs to as_stmts
    auto exprs = SQLParser::as_exprs(query);
    // TODO: Allow for multiple statements
    auto plan = build_plan(exprs[0]);

    // Create and run the txn
    auto &txn = txn_mgr_.begin();
    auto exec_ctx = ExecCtx::make(txn, resources_);

    auto result_set = exec_eng().execute(move(plan),
                                         txn,
                                         *exec_ctx);
    txn_mgr().commit(txn);
    return result_set;
  } catch (std::runtime_exception& e) {
    return ResultSet::empty();
  }
}
