#pragma once

#include "common/config.hpp"

enum class SchemaType {
  TABLE = 0,
  QUERY = 1
};

class SchemaRef {
public:
  SchemaRef(SchemaType schema_type,
            table_oid_t table_oid = INVALID_TABLE_OID)
    : schema_type_ (schema_type),
      table_oid_   (table_oid)
  {}

  static SchemaRef from_table_oid(table_oid_t table_oid) {
    return SchemaRef(SchemaType::TABLE, table_oid);
  }

  static SchemaRef INVALID() {
    return SchemaRef(SchemaType::QUERY, INVALID_TABLE_OID);
  }

  bool is_query_schema() const {
    return schema_type_ == SchemaType::QUERY;
  }

  bool is_table_schema() const {
    return schema_type_ == SchemaType::TABLE;
  }

  table_oid_t table_oid() {
    return table_oid_;
  }

private:
  SchemaType schema_type_;
  table_oid_t table_oid_ = INVALID_TABLE_OID;
};
