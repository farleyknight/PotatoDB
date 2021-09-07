#pragma once

#include "exprs/column_def_list_expr.hpp"

class ColumnMgr {
public:
  ColumnMgr() {}


  column_oid_t
  make_column_oid(const table_name_t& table_name,
                  const column_name_t& column_name)
  {
    auto full_name   = table_name + "." + column_name;
    assert(!column_oids_.contains(full_name));

    column_oid_t column_oid = next_column_oid_;
    next_column_oid_++;
    column_oids_[full_name] = column_oid;

    return column_oid;
  }

  vector<TableColumn> make_columns(table_oid_t table_oid,
                                   table_name_t table_name,
                                   const ColumnDefListExpr& expr)
  {
    vector<TableColumn> columns;

    for (const auto &column_expr : expr.list()) {
      auto column_oid = make_column_oid(table_name, column_expr.name());

      assert(!columns_.contains(column_oid));
      auto col = make_column_from(table_oid, column_oid, column_expr);
      columns_[column_oid] = col;

      columns.push_back(col);
    }

    return columns;
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const
  {
    return column_oids_.contains(table_name + "." + column_name);
  }

  TableColumn
  make_column_from(table_oid_t table_oid,
                   column_oid_t column_oid,
                   const ColumnDefExpr& expr) const
  {
    auto name    = expr.name();
    auto type_id = expr.type_id();
    if (type_id == TypeId::VARCHAR) {
      return TableColumn(name,
                         table_oid,
                         column_oid,
                         type_id,
                         expr.type_length());
    } else {
      return TableColumn(name,
                         table_oid,
                         column_oid,
                         type_id);
    }
  }

  TableColumn&
  column_for(column_oid_t column_oid) {
    return columns_.at(column_oid);
  }

  const TableColumn&
  column_for(column_oid_t column_oid) const {
    return columns_.at(column_oid);
  }

private:

  // TODO: I think we should make a ColumnMgr class
  // I think that is a reasonable answer to: Where do we store these variables?
  // Columns
  map<column_name_t, column_oid_t> column_oids_;
  map<column_oid_t, TableColumn> columns_;
  // TODO: Maybe we should store TableColumns in a `map`?
  atomic<column_oid_t> next_column_oid_ = FIRST_COLUMN_OID;
};
