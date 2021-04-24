#pragma once

enum class ExprType {
  // Statement fragments/exprs
  COLUMN,
  COLUMN_LIST,
  TABLE,
  TABLE_LIST,
  VALUE,
  TUPLE,
  TUPLE_LIST,

  // Statement types
  SELECT,
  WHERE,
  LIMIT,
  ORDER_BY,
  GROUP_BY,
  HAVING,

  INSERT
};


class Expr {
public:
  Expr(ExprType expr_type)
    : expr_type_ (expr_type)
  {}

  virtual ~Expr() = default;

  virtual MutString to_string() {
    return "BASE EXPR";
  }

protected:
  ExprType expr_type_;
};


class ValueExpr : public Expr {
public:
  ValueExpr(MutString data)
    : Expr  (ExprType::VALUE),
      data_ (data)
  {}

  virtual MutString to_string() {
    return data_;
  }

protected:
  MutString data_;
};



class TupleExpr : public Expr {
public:
  TupleExpr()
    : Expr (ExprType::TUPLE)
  {}

  void push_back(ValueExpr expr) {
    values_.push_back(expr);
  }

  MutString to_string() override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < values_.size(); ++i) {
      stream << values_[i].to_string();
      if (i != values_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<ValueExpr> values_;
};




class TupleListExpr : public Expr {
public:
  TupleListExpr()
    : Expr (ExprType::TUPLE_LIST)
  {}

  void push_back(TupleExpr expr) {
    tuples_.push_back(expr);
  }

  MutString to_string() override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < tuples_.size(); ++i) {
      stream << tuples_[i].to_string();
      if (i != tuples_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<TupleExpr> tuples_;
};


class ColumnExpr : public Expr {
public:
  ColumnExpr(MutString name)
    : Expr   (ExprType::COLUMN),
      name_  (name)
  {}

  ColumnExpr(MutString name, MutString table)
    : Expr   (ExprType::COLUMN),
      name_  (name),
      table_ (table)
  {}

  virtual MutString to_string() {
    return name_;
  }

protected:
  MutString name_, table_;
};



class ColumnListExpr : public Expr {
public:
  ColumnListExpr()
    : Expr (ExprType::COLUMN_LIST)
  {}

  void push_back(ColumnExpr expr) {
    columns_.push_back(expr);
  }

  MutString to_string() override {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < columns_.size(); ++i) {
      stream << columns_[i].to_string();
      if (i != columns_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<ColumnExpr> columns_;
};




class TableExpr : public Expr {
public:
  TableExpr()
    : Expr  (ExprType::TABLE)
  {}

  TableExpr(MutString name)
    : Expr  (ExprType::TABLE),
      name_ (name)
  {}

  void set_name(MutString name) {
    name_ = name;
  }

  virtual MutString to_string() {
    return name_;
  }

protected:
  MutString name_;
};



class TableListExpr : public Expr {
public:
  TableListExpr()
    : Expr (ExprType::TABLE_LIST)
  {}

  void push_back(TableExpr table) {
    tables_.push_back(table);
  }

  MutString to_string() override {
    std::stringstream stream;
    stream << "[";
    for (size_t i = 0; i < tables_.size(); ++i) {
      stream << tables_[i].to_string();
      if (i != tables_.size() - 1) {
        stream << ", ";
      }
    }
    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  MutVec<TableExpr> tables_;
};




class SelectExpr : public Expr {
public:
  SelectExpr()
    : Expr (ExprType::SELECT)
  {}

  void set_columns(ColumnListExpr columns) {
    columns_ = columns;
  }

  void set_tables(TableListExpr tables) {
    tables_ = tables;
  }

  virtual MutString to_string() {
    return "SELECT " + columns_.to_string() +
      "FROM " + tables_.to_string();
  }

protected:
  TableListExpr tables_;
  ColumnListExpr columns_;
};




class InsertExpr : public Expr {
public:
  InsertExpr()
    : Expr (ExprType::INSERT)
  {}

  void set_table(TableExpr table) {
    table_ = table;
  }

  void set_columns(ColumnListExpr columns) {
    columns_ = columns;
  }

  void set_tuples(TupleListExpr tuples) {
    tuples_ = tuples;
  }

  virtual MutString to_string() {
    return "INSERT INTO " + table_.to_string() +
      columns_.to_string() +
      "VALUES " + tuples_.to_string();
  }

protected:
  TableExpr table_;
  ColumnListExpr columns_;
  TupleListExpr tuples_;
};
