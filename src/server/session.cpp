
#include "server/session.hpp"
#include "server/potatodb.hpp"

ptr<ResultSet> Session::query(string statement) {
  return db_->query(statement);
}

void Session::execute(string statement) {
  db_->execute(statement);
}

