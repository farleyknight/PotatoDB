#pragma once

#include "common/config.hpp"

class TablePlan {
public:
  TablePlan(table_oid_t table_oid)
    : table_oid_ (table_oid)
  {}

  table_oid_t table_oid() const { return table_oid_; }

private:
  table_oid_t table_oid_;
};
