#pragma once

class IndexedColumnListExpr : public BaseExpr,
                              public ListExpr<column_name_t>
{
public:
  IndexedColumnListExpr()
    : BaseExpr (ExprType::INDEXED_COLUMN_LIST)
  {}

  IndexedColumnListExpr(vector<column_name_t> list)
    : BaseExpr (ExprType::INDEXED_COLUMN_LIST),
      ListExpr (list)
  {}


  const string to_string() const {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < list_.size(); ++i) {
      stream << list_[i];
      if (i != list_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }
};
