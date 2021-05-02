#pragma once

#include "common/config.hpp"

class IndexMeta {
public:
  IndexMeta(CRef<TableSchema> key_schema,
            string index_name)
    : key_schema_ (key_schema),
      index_name_ (index_name)
  {}

  CRef<TableSchema> key_schema() const {
    return key_schema_;
  }

  string index_name() const {
    return index_name_;
  }

private:
  CRef<TableSchema> key_schema_;
  string index_name_;
};
