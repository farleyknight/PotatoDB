#pragma once

#include "tuple/result_set.hpp"

class StatementResult {
public:
  StatementResult(const string message) 
    : message_ (message)
  {}

  StatementResult(ptr<ResultSet>&& result_set)
    : result_set_ (move(result_set))
  {}

  const string to_payload() {
    if (result_set_ == nullptr) {
      return message_;
    } else {
      return result_set_->to_payload();
    }
  }

  const ptr<ResultSet>& set() const {
    return result_set_;
  }

private:
  string message_ = "";
  ptr<ResultSet> result_set_;
};


