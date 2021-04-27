#pragma once

#include <cfloat>
#include <stdio.h>
#include <limits>

static constexpr double DBL_LOWEST = std::numeric_limits<double>::lowest();
static constexpr double FLT_LOWEST = std::numeric_limits<float>::lowest();

class Int8 {
public:
  static constexpr int8_t   MIN          = (SCHAR_MIN + 1);
  static constexpr int8_t   MAX          = SCHAR_MAX;
  static constexpr int8_t   NIL          = SCHAR_MIN;
};

class Int16 {
public:
  static constexpr int16_t  MIN          = (SHRT_MIN + 1);
  static constexpr int16_t  MAX          = SHRT_MAX;
  static constexpr int16_t  NIL          = SHRT_MIN;
};


class Int32 {
public:
  static constexpr int32_t  MIN          = (INT_MIN + 1);
  static constexpr int32_t  MAX          = INT_MAX;
  static constexpr int32_t  NIL          = INT_MIN;
};

class Int64 {
public:
  static constexpr int64_t  MIN          = (LLONG_MIN + 1);
  static constexpr int64_t  MAX          = LLONG_MAX;
  static constexpr int64_t  NIL          = LLONG_MIN;
};

class UInt64 {
public:
  static constexpr uint64_t MAX          = ULLONG_MAX - 1;
};

class Decimal {
public:
  static constexpr double   MAX          = DBL_MAX;
  static constexpr double   MIN          = FLT_LOWEST;
  static constexpr double   NIL          = DBL_LOWEST;
};


class Timestamp {
public:
  static constexpr uint64_t MIN          = 0;
  static constexpr uint64_t MAX          = 11231999986399999999U; // WTF?
  static constexpr uint64_t NIL          = ULLONG_MAX;
};

class Date {
public:
  static constexpr uint32_t MIN          = 0;
  static constexpr uint64_t MAX          = INT_MAX;
  static constexpr uint64_t NIL          = 0;
};

class Double {
public:
  static constexpr double   MAX          = DBL_MAX;
};

class Boolean {
public:
  static constexpr int8_t   MIN          = 0;
  static constexpr int8_t   MAX          = 1;
  static constexpr int8_t   NIL          = SCHAR_MIN;

};


static constexpr uint32_t VALUE_NULL         = UINT_MAX;
static constexpr uint32_t VARCHAR_MAX_LEN    = UINT_MAX;

// Use to make TEXT type as the alias of VARCHAR(TEXT_MAX_LENGTH)
static constexpr uint32_t TEXT_MAX_LEN       = 1000000000;

// Objects (i.e., VARCHAR) with length prefix of -1 are NULL
static constexpr int      OBJECT_LENGTH_NULL = -1;
