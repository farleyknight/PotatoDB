
#include "server/session.hpp"
#include "server/potatodb.hpp"

MutPtr<ResultSet> Session::execute(string query) {
  return db_->execute(query);
}

