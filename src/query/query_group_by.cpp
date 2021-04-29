
#include "exprs/group_by_expr.hpp"
#include "catalog/schema.hpp"

GroupByExpr::GroupByExpr(TypeId type_id,
                         Ref<Schema> source_schema,
                         Ref<String> column_name)
  : BaseExpr       (type_id),
    source_schema_ (source_schema),
    column_name_   (column_name) {}

GroupByExpr::GroupByExpr(Ref<Schema> source_schema,
                         Ref<String> column_name)
  : BaseExpr       (TypeId::INTEGER),
    source_schema_ (source_schema),
    column_name_   (column_name) {}


Ptr<GroupByExpr> GroupByExpr::make(Ref<Schema> source_schema,
                                   Ref<String> column_name)
{
  return make_unique<GroupByExpr>(TypeId::INTEGER,
                                  source_schema,
                                  column_name);
}


Value GroupByExpr::eval_agg(Ref<Vec<Value>> group_bys,
                            Ref<Vec<Value>> aggrs) const
{
  auto index = source_schema_.by_name(column_name_);
  return group_bys[index];
}
