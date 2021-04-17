#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

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

  BAD_FILE = 12
};

class Exception : public std::runtime_error {
public:
  explicit Exception(Ref<String> message)
  : std::runtime_error(message), type_(ExceptionType::INVALID) {
    String exception_message = "Message :: " + message + "\n";
    std::cerr << exception_message;
  }

  Exception(ExceptionType exception_type, Ref<String> message)
  : std::runtime_error(message), type_(exception_type) {
    String exception_message =
    "\nException Type :: " + to_string(type_) + "\nMessage :: " + message + "\n";
    std::cerr << exception_message;
  }

  String to_string(ExceptionType type) {
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
  explicit NotImplementedException(const std::string &msg)
  : Exception(ExceptionType::NOT_IMPLEMENTED, msg) {}
};
