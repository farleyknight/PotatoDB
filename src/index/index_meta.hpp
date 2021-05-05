#pragma once

#include "common/config.hpp"

class IndexMeta {
public:
  IndexMeta(const TableSchema& key_schema,
            string index_name)
    : key_schema_ (key_schema),
      index_name_ (index_name)
  {}

  const TableSchema& key_schema() const {
    return key_schema_;
  }

  string index_name() const {
    return index_name_;
  }

private:
  const TableSchema& key_schema_;
  string index_name_;
};
