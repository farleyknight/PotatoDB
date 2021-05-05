
#include "server/session.hpp"
#include "server/potatodb.hpp"

ptr<ResultSet> Session::execute(string query) {
  return db_->execute(query);
}

