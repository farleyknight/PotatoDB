#pragma once

#include "opers/base_oper.hpp"
#include "opers/table_oper.hpp"
#include "opers/has_child_oper.hpp"

class SeqScanOper : public BaseOper,
                    public TableOper,
                    public HasChildOper
{
public:
  SeqScanOper(ExecCtx& exec_ctx,
              table_oid_t table_oid)
    : TableOper (table_oid)
  {}

  void init() override;
  bool has_next() override;
  Tuple next() override;

  bool is_query() const {
    return true;
  }

  const string message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

}
