
#include "parser/potato_sql.hpp"

class Resources {
public:
  DiskMgr
  BuffMgr
  LockMgr
  TxnMgr
  ExecCtx
  ExecEngine
}

class PotatoSession {
public:
  PotatoSession(String file_name, const int bp_size = 32)
    : file_name_ (file_name),
      bp_size_   (bp_size)
  {
    // TODO?
  }

  ~PotatoSession();

  CRef<Resources> resources() {
    return resources_;
  }

  ResultSet execute(String message) {
    try {
      auto parse = PotatoSQL::parse(message);
      auto plan = build_plan(parse);
      auto &txn = txn_mgr().begin();
      auto exec_ctx = ExecCtx::make(txn, resources());

      auto result_set = exec_eng().execute(move(plan),
                                           txn,
                                           *exec_ctx);
      txn_mgr().commit(txn);
      return result_set;
    } catch (std::runtime_exception& e) {
      return ResultSet();
    }
  }
}
