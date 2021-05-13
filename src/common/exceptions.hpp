#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "common/types.hpp"

enum class ExceptionType {
  /** Invalid exception type.*/
  INVALID = 0,
  /** Value out of range. */
  OUT_OF_RANGE = 1,
  /** Conversion/casting error. */
  CONVERSION = 2,
  /** Unknown type in the type subsystem. */
  UNKNOWN_TYPE = 3,
  /** Decimal-related errors. */
  DECIMAL = 4,
  /** Type mismatch. */
  MISMATCH_TYPE = 5,
  /** Division by 0. */
  DIVIDE_BY_ZERO = 6,
  /** Incompatible type. */
  INCOMPATIBLE_TYPE = 8,
  /** Method not implemented. */
  NOT_IMPLEMENTED = 11,

  BAD_FILE = 12,

  NO_COLUMNS_NAMED = 13,

  MORE_THAN_ONE_COLUMN = 14
};

class Exception : public std::runtime_error {
public:
  explicit Exception(string message)
  : std::runtime_error(message), type_(ExceptionType::INVALID) {
    const string exception_message = "Message :: " + message + "\n";
    std::cerr << exception_message;
  }

  Exception(ExceptionType exception_type, string message)
  : std::runtime_error(message), type_(exception_type) {
    const string exception_message =
      "\nException Type :: " + to_string(type_) + "\nMessage :: " + message + "\n";
    std::cerr << exception_message;
  }

  string to_string(ExceptionType type) {
    switch (type) {
    case ExceptionType::INVALID:
      return "Invalid";

    case ExceptionType::OUT_OF_RANGE:
      return "Out of Range";

    case ExceptionType::CONVERSION:
      return "Conversion";

    case ExceptionType::UNKNOWN_TYPE:
      return "Unknown Type";

    case ExceptionType::DECIMAL:
      return "Decimal";

    case ExceptionType::MISMATCH_TYPE:
      return "Mismatch Type";

    case ExceptionType::DIVIDE_BY_ZERO:
      return "Divide by Zero";

    case ExceptionType::INCOMPATIBLE_TYPE:
      return "Incompatible type";

    case ExceptionType::NOT_IMPLEMENTED:
      return "Not implemented";

    case ExceptionType::BAD_FILE:
      return "Bad file";

    default:
      return "Unknown";
    }
  }

private:
  ExceptionType type_;
};

class NotImplementedException : public Exception {
public:
  NotImplementedException() = delete;
  explicit NotImplementedException(const string &msg)
    : Exception(ExceptionType::NOT_IMPLEMENTED, msg) {}
};

class NoColumnsNamedException : public Exception {
public:
  NoColumnsNamedException() = delete;
  explicit NoColumnsNamedException(const string &msg)
    : Exception(ExceptionType::NO_COLUMNS_NAMED, msg) {}
};

class MoreThanOneColumnException : public Exception {
public:
  MoreThanOneColumnException() = delete;
  explicit MoreThanOneColumnException(const string &msg)
    : Exception(ExceptionType::MORE_THAN_ONE_COLUMN, msg) {}
};

