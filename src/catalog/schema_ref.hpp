#pragma once

#include "common/types.hpp"

enum class SchemaType {
  TABLE = 0,
  QUERY = 1
};

class SchemaRef {
public:
  SchemaRef(SchemaType schema_type,
            schema_oid_t schema_oid,
            table_oid_t table_oid = INVALID_TABLE_OID)
    : schema_type_ (schema_type),
      schema_oid_  (schema_oid),
      table_oid_   (table_oid)
  {}

  static SchemaRef from_table_oid(table_oid_t table_oid) {
    return SchemaRef(SchemaType::TABLE,
                     // NOTE: See invariant #2 of SchemaMgr
                     table_oid,
                     table_oid);
  }

  static SchemaRef INVALID() {
    return SchemaRef(SchemaType::QUERY, -1, -1);
  }

  bool is_query_schema() const {
    return schema_type_ == SchemaType::QUERY;
  }

  bool is_table_schema() const {
    return schema_type_ == SchemaType::TABLE;
  }

  schema_oid_t oid() const {
    return schema_oid_;
  }

  table_oid_t table_oid() {
    return table_oid_;
  }

private:
  SchemaType schema_type_;
  schema_oid_t schema_oid_;
  table_oid_t table_oid_ = INVALID_TABLE_OID;
};
