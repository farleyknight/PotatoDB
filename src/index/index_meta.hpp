#pragma once

#include "common/config.hpp"
#include "catalog/query_schema.hpp"

class IndexMeta {
public:
  IndexMeta(const QuerySchema& key_schema,
            string index_name)
    : key_schema_ (key_schema),
      index_name_ (index_name)
  {}

  const QuerySchema& key_schema() const {
    return key_schema_;
  }

  string index_name() const {
    return index_name_;
  }

private:
  const QuerySchema& key_schema_;
  string index_name_;
};
