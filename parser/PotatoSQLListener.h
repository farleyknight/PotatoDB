
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PotatoSQLParser.h"


namespace potatosql {

/**
 * This interface defines an abstract listener for a parse tree produced by PotatoSQLParser.
 */
class  PotatoSQLListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(PotatoSQLParser::MainContext *ctx) = 0;
  virtual void exitMain(PotatoSQLParser::MainContext *ctx) = 0;

  virtual void enterError(PotatoSQLParser::ErrorContext *ctx) = 0;
  virtual void exitError(PotatoSQLParser::ErrorContext *ctx) = 0;

  virtual void enterSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext *ctx) = 0;
  virtual void exitSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext *ctx) = 0;

  virtual void enterSql_stmt(PotatoSQLParser::Sql_stmtContext *ctx) = 0;
  virtual void exitSql_stmt(PotatoSQLParser::Sql_stmtContext *ctx) = 0;

  virtual void enterAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext *ctx) = 0;
  virtual void exitAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext *ctx) = 0;

  virtual void enterAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext *ctx) = 0;
  virtual void exitAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext *ctx) = 0;

  virtual void enterAttach_stmt(PotatoSQLParser::Attach_stmtContext *ctx) = 0;
  virtual void exitAttach_stmt(PotatoSQLParser::Attach_stmtContext *ctx) = 0;

  virtual void enterBegin_stmt(PotatoSQLParser::Begin_stmtContext *ctx) = 0;
  virtual void exitBegin_stmt(PotatoSQLParser::Begin_stmtContext *ctx) = 0;

  virtual void enterCommit_stmt(PotatoSQLParser::Commit_stmtContext *ctx) = 0;
  virtual void exitCommit_stmt(PotatoSQLParser::Commit_stmtContext *ctx) = 0;

  virtual void enterCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext *ctx) = 0;
  virtual void exitCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext *ctx) = 0;

  virtual void enterCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext *ctx) = 0;
  virtual void exitCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext *ctx) = 0;

  virtual void enterCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext *ctx) = 0;
  virtual void exitCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext *ctx) = 0;

  virtual void enterCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext *ctx) = 0;
  virtual void exitCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext *ctx) = 0;

  virtual void enterCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext *ctx) = 0;
  virtual void exitCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext *ctx) = 0;

  virtual void enterCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext *ctx) = 0;
  virtual void exitCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext *ctx) = 0;

  virtual void enterDelete_stmt(PotatoSQLParser::Delete_stmtContext *ctx) = 0;
  virtual void exitDelete_stmt(PotatoSQLParser::Delete_stmtContext *ctx) = 0;

  virtual void enterDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext *ctx) = 0;
  virtual void exitDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext *ctx) = 0;

  virtual void enterDetach_stmt(PotatoSQLParser::Detach_stmtContext *ctx) = 0;
  virtual void exitDetach_stmt(PotatoSQLParser::Detach_stmtContext *ctx) = 0;

  virtual void enterDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext *ctx) = 0;
  virtual void exitDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext *ctx) = 0;

  virtual void enterDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext *ctx) = 0;
  virtual void exitDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext *ctx) = 0;

  virtual void enterDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext *ctx) = 0;
  virtual void exitDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext *ctx) = 0;

  virtual void enterDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext *ctx) = 0;
  virtual void exitDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext *ctx) = 0;

  virtual void enterFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext *ctx) = 0;
  virtual void exitFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext *ctx) = 0;

  virtual void enterInsert_prefix(PotatoSQLParser::Insert_prefixContext *ctx) = 0;
  virtual void exitInsert_prefix(PotatoSQLParser::Insert_prefixContext *ctx) = 0;

  virtual void enterInsert_tuple(PotatoSQLParser::Insert_tupleContext *ctx) = 0;
  virtual void exitInsert_tuple(PotatoSQLParser::Insert_tupleContext *ctx) = 0;

  virtual void enterInsert_tuples(PotatoSQLParser::Insert_tuplesContext *ctx) = 0;
  virtual void exitInsert_tuples(PotatoSQLParser::Insert_tuplesContext *ctx) = 0;

  virtual void enterInsert_columns(PotatoSQLParser::Insert_columnsContext *ctx) = 0;
  virtual void exitInsert_columns(PotatoSQLParser::Insert_columnsContext *ctx) = 0;

  virtual void enterInsert_stmt(PotatoSQLParser::Insert_stmtContext *ctx) = 0;
  virtual void exitInsert_stmt(PotatoSQLParser::Insert_stmtContext *ctx) = 0;

  virtual void enterPragma_stmt(PotatoSQLParser::Pragma_stmtContext *ctx) = 0;
  virtual void exitPragma_stmt(PotatoSQLParser::Pragma_stmtContext *ctx) = 0;

  virtual void enterReindex_stmt(PotatoSQLParser::Reindex_stmtContext *ctx) = 0;
  virtual void exitReindex_stmt(PotatoSQLParser::Reindex_stmtContext *ctx) = 0;

  virtual void enterRelease_stmt(PotatoSQLParser::Release_stmtContext *ctx) = 0;
  virtual void exitRelease_stmt(PotatoSQLParser::Release_stmtContext *ctx) = 0;

  virtual void enterRollback_stmt(PotatoSQLParser::Rollback_stmtContext *ctx) = 0;
  virtual void exitRollback_stmt(PotatoSQLParser::Rollback_stmtContext *ctx) = 0;

  virtual void enterSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext *ctx) = 0;
  virtual void exitSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext *ctx) = 0;

  virtual void enterSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext *ctx) = 0;
  virtual void exitSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext *ctx) = 0;

  virtual void enterSelect_stmt(PotatoSQLParser::Select_stmtContext *ctx) = 0;
  virtual void exitSelect_stmt(PotatoSQLParser::Select_stmtContext *ctx) = 0;

  virtual void enterSelect_or_values(PotatoSQLParser::Select_or_valuesContext *ctx) = 0;
  virtual void exitSelect_or_values(PotatoSQLParser::Select_or_valuesContext *ctx) = 0;

  virtual void enterUpdate_stmt(PotatoSQLParser::Update_stmtContext *ctx) = 0;
  virtual void exitUpdate_stmt(PotatoSQLParser::Update_stmtContext *ctx) = 0;

  virtual void enterUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext *ctx) = 0;
  virtual void exitUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext *ctx) = 0;

  virtual void enterVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext *ctx) = 0;
  virtual void exitVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext *ctx) = 0;

  virtual void enterColumn_def(PotatoSQLParser::Column_defContext *ctx) = 0;
  virtual void exitColumn_def(PotatoSQLParser::Column_defContext *ctx) = 0;

  virtual void enterType_name(PotatoSQLParser::Type_nameContext *ctx) = 0;
  virtual void exitType_name(PotatoSQLParser::Type_nameContext *ctx) = 0;

  virtual void enterColumn_constraint(PotatoSQLParser::Column_constraintContext *ctx) = 0;
  virtual void exitColumn_constraint(PotatoSQLParser::Column_constraintContext *ctx) = 0;

  virtual void enterConflict_clause(PotatoSQLParser::Conflict_clauseContext *ctx) = 0;
  virtual void exitConflict_clause(PotatoSQLParser::Conflict_clauseContext *ctx) = 0;

  virtual void enterExpr(PotatoSQLParser::ExprContext *ctx) = 0;
  virtual void exitExpr(PotatoSQLParser::ExprContext *ctx) = 0;

  virtual void enterForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext *ctx) = 0;
  virtual void exitForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext *ctx) = 0;

  virtual void enterRaise_function(PotatoSQLParser::Raise_functionContext *ctx) = 0;
  virtual void exitRaise_function(PotatoSQLParser::Raise_functionContext *ctx) = 0;

  virtual void enterIndexed_column(PotatoSQLParser::Indexed_columnContext *ctx) = 0;
  virtual void exitIndexed_column(PotatoSQLParser::Indexed_columnContext *ctx) = 0;

  virtual void enterTable_constraint(PotatoSQLParser::Table_constraintContext *ctx) = 0;
  virtual void exitTable_constraint(PotatoSQLParser::Table_constraintContext *ctx) = 0;

  virtual void enterWith_clause(PotatoSQLParser::With_clauseContext *ctx) = 0;
  virtual void exitWith_clause(PotatoSQLParser::With_clauseContext *ctx) = 0;

  virtual void enterQualified_table_name(PotatoSQLParser::Qualified_table_nameContext *ctx) = 0;
  virtual void exitQualified_table_name(PotatoSQLParser::Qualified_table_nameContext *ctx) = 0;

  virtual void enterOrdering_term(PotatoSQLParser::Ordering_termContext *ctx) = 0;
  virtual void exitOrdering_term(PotatoSQLParser::Ordering_termContext *ctx) = 0;

  virtual void enterPragma_value(PotatoSQLParser::Pragma_valueContext *ctx) = 0;
  virtual void exitPragma_value(PotatoSQLParser::Pragma_valueContext *ctx) = 0;

  virtual void enterCommon_table_expression(PotatoSQLParser::Common_table_expressionContext *ctx) = 0;
  virtual void exitCommon_table_expression(PotatoSQLParser::Common_table_expressionContext *ctx) = 0;

  virtual void enterResult_column(PotatoSQLParser::Result_columnContext *ctx) = 0;
  virtual void exitResult_column(PotatoSQLParser::Result_columnContext *ctx) = 0;

  virtual void enterTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext *ctx) = 0;
  virtual void exitTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext *ctx) = 0;

  virtual void enterJoin_clause(PotatoSQLParser::Join_clauseContext *ctx) = 0;
  virtual void exitJoin_clause(PotatoSQLParser::Join_clauseContext *ctx) = 0;

  virtual void enterJoin_operator(PotatoSQLParser::Join_operatorContext *ctx) = 0;
  virtual void exitJoin_operator(PotatoSQLParser::Join_operatorContext *ctx) = 0;

  virtual void enterJoin_constraint(PotatoSQLParser::Join_constraintContext *ctx) = 0;
  virtual void exitJoin_constraint(PotatoSQLParser::Join_constraintContext *ctx) = 0;

  virtual void enterColumn_list(PotatoSQLParser::Column_listContext *ctx) = 0;
  virtual void exitColumn_list(PotatoSQLParser::Column_listContext *ctx) = 0;

  virtual void enterSelect_core(PotatoSQLParser::Select_coreContext *ctx) = 0;
  virtual void exitSelect_core(PotatoSQLParser::Select_coreContext *ctx) = 0;

  virtual void enterCompound_operator(PotatoSQLParser::Compound_operatorContext *ctx) = 0;
  virtual void exitCompound_operator(PotatoSQLParser::Compound_operatorContext *ctx) = 0;

  virtual void enterSigned_number(PotatoSQLParser::Signed_numberContext *ctx) = 0;
  virtual void exitSigned_number(PotatoSQLParser::Signed_numberContext *ctx) = 0;

  virtual void enterLiteral_value(PotatoSQLParser::Literal_valueContext *ctx) = 0;
  virtual void exitLiteral_value(PotatoSQLParser::Literal_valueContext *ctx) = 0;

  virtual void enterUnary_operator(PotatoSQLParser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(PotatoSQLParser::Unary_operatorContext *ctx) = 0;

  virtual void enterError_message(PotatoSQLParser::Error_messageContext *ctx) = 0;
  virtual void exitError_message(PotatoSQLParser::Error_messageContext *ctx) = 0;

  virtual void enterModule_argument(PotatoSQLParser::Module_argumentContext *ctx) = 0;
  virtual void exitModule_argument(PotatoSQLParser::Module_argumentContext *ctx) = 0;

  virtual void enterColumn_alias(PotatoSQLParser::Column_aliasContext *ctx) = 0;
  virtual void exitColumn_alias(PotatoSQLParser::Column_aliasContext *ctx) = 0;

  virtual void enterKeyword(PotatoSQLParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(PotatoSQLParser::KeywordContext *ctx) = 0;

  virtual void enterName(PotatoSQLParser::NameContext *ctx) = 0;
  virtual void exitName(PotatoSQLParser::NameContext *ctx) = 0;

  virtual void enterFunction_name(PotatoSQLParser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(PotatoSQLParser::Function_nameContext *ctx) = 0;

  virtual void enterDatabase_name(PotatoSQLParser::Database_nameContext *ctx) = 0;
  virtual void exitDatabase_name(PotatoSQLParser::Database_nameContext *ctx) = 0;

  virtual void enterSchema_name(PotatoSQLParser::Schema_nameContext *ctx) = 0;
  virtual void exitSchema_name(PotatoSQLParser::Schema_nameContext *ctx) = 0;

  virtual void enterTable_function_name(PotatoSQLParser::Table_function_nameContext *ctx) = 0;
  virtual void exitTable_function_name(PotatoSQLParser::Table_function_nameContext *ctx) = 0;

  virtual void enterTable_name(PotatoSQLParser::Table_nameContext *ctx) = 0;
  virtual void exitTable_name(PotatoSQLParser::Table_nameContext *ctx) = 0;

  virtual void enterTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext *ctx) = 0;
  virtual void exitTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext *ctx) = 0;

  virtual void enterNew_table_name(PotatoSQLParser::New_table_nameContext *ctx) = 0;
  virtual void exitNew_table_name(PotatoSQLParser::New_table_nameContext *ctx) = 0;

  virtual void enterColumn_name(PotatoSQLParser::Column_nameContext *ctx) = 0;
  virtual void exitColumn_name(PotatoSQLParser::Column_nameContext *ctx) = 0;

  virtual void enterCollation_name(PotatoSQLParser::Collation_nameContext *ctx) = 0;
  virtual void exitCollation_name(PotatoSQLParser::Collation_nameContext *ctx) = 0;

  virtual void enterForeign_table(PotatoSQLParser::Foreign_tableContext *ctx) = 0;
  virtual void exitForeign_table(PotatoSQLParser::Foreign_tableContext *ctx) = 0;

  virtual void enterIndex_name(PotatoSQLParser::Index_nameContext *ctx) = 0;
  virtual void exitIndex_name(PotatoSQLParser::Index_nameContext *ctx) = 0;

  virtual void enterTrigger_name(PotatoSQLParser::Trigger_nameContext *ctx) = 0;
  virtual void exitTrigger_name(PotatoSQLParser::Trigger_nameContext *ctx) = 0;

  virtual void enterView_name(PotatoSQLParser::View_nameContext *ctx) = 0;
  virtual void exitView_name(PotatoSQLParser::View_nameContext *ctx) = 0;

  virtual void enterModule_name(PotatoSQLParser::Module_nameContext *ctx) = 0;
  virtual void exitModule_name(PotatoSQLParser::Module_nameContext *ctx) = 0;

  virtual void enterPragma_name(PotatoSQLParser::Pragma_nameContext *ctx) = 0;
  virtual void exitPragma_name(PotatoSQLParser::Pragma_nameContext *ctx) = 0;

  virtual void enterSavepoint_name(PotatoSQLParser::Savepoint_nameContext *ctx) = 0;
  virtual void exitSavepoint_name(PotatoSQLParser::Savepoint_nameContext *ctx) = 0;

  virtual void enterTable_alias(PotatoSQLParser::Table_aliasContext *ctx) = 0;
  virtual void exitTable_alias(PotatoSQLParser::Table_aliasContext *ctx) = 0;

  virtual void enterTransaction_name(PotatoSQLParser::Transaction_nameContext *ctx) = 0;
  virtual void exitTransaction_name(PotatoSQLParser::Transaction_nameContext *ctx) = 0;

  virtual void enterAny_name(PotatoSQLParser::Any_nameContext *ctx) = 0;
  virtual void exitAny_name(PotatoSQLParser::Any_nameContext *ctx) = 0;


};

}  // namespace potatosql
