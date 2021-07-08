#include "server/session.hpp"
#include "server/potatodb.hpp"

// TODO: Why is this the only statement here?
// Take some time do decide if this is the right abstraction..
StatementResult Session::run_statement(const string& statement) {
  return db_->run(statement);
}

