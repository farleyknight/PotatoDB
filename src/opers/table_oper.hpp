#pragma once

class TableOper {
public:
  TableOper(table_oid_t table_oid)
    : table_oid_ (table_oid)
  {}

  table_oid_t table_oid() const { return table_oid_; }

protected:
  table_oid_t table_oid_;
};
