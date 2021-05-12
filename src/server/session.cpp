#include "server/session.hpp"
#include "server/potatodb.hpp"

StatementResult Session::run_statement(const string& statement) {
  return db_->run_statement(statement);
}

