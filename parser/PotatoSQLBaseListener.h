
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PotatoSQLListener.h"


namespace potatosql {

/**
 * This class provides an empty implementation of PotatoSQLListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PotatoSQLBaseListener : public PotatoSQLListener {
public:

  virtual void enterMain(PotatoSQLParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(PotatoSQLParser::MainContext * /*ctx*/) override { }

  virtual void enterError(PotatoSQLParser::ErrorContext * /*ctx*/) override { }
  virtual void exitError(PotatoSQLParser::ErrorContext * /*ctx*/) override { }

  virtual void enterSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext * /*ctx*/) override { }
  virtual void exitSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext * /*ctx*/) override { }

  virtual void enterSql_stmt(PotatoSQLParser::Sql_stmtContext * /*ctx*/) override { }
  virtual void exitSql_stmt(PotatoSQLParser::Sql_stmtContext * /*ctx*/) override { }

  virtual void enterAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext * /*ctx*/) override { }
  virtual void exitAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext * /*ctx*/) override { }

  virtual void enterAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext * /*ctx*/) override { }
  virtual void exitAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext * /*ctx*/) override { }

  virtual void enterAttach_stmt(PotatoSQLParser::Attach_stmtContext * /*ctx*/) override { }
  virtual void exitAttach_stmt(PotatoSQLParser::Attach_stmtContext * /*ctx*/) override { }

  virtual void enterBegin_stmt(PotatoSQLParser::Begin_stmtContext * /*ctx*/) override { }
  virtual void exitBegin_stmt(PotatoSQLParser::Begin_stmtContext * /*ctx*/) override { }

  virtual void enterCommit_stmt(PotatoSQLParser::Commit_stmtContext * /*ctx*/) override { }
  virtual void exitCommit_stmt(PotatoSQLParser::Commit_stmtContext * /*ctx*/) override { }

  virtual void enterCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext * /*ctx*/) override { }
  virtual void exitCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext * /*ctx*/) override { }

  virtual void enterDelete_stmt(PotatoSQLParser::Delete_stmtContext * /*ctx*/) override { }
  virtual void exitDelete_stmt(PotatoSQLParser::Delete_stmtContext * /*ctx*/) override { }

  virtual void enterDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterDetach_stmt(PotatoSQLParser::Detach_stmtContext * /*ctx*/) override { }
  virtual void exitDetach_stmt(PotatoSQLParser::Detach_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext * /*ctx*/) override { }

  virtual void enterFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext * /*ctx*/) override { }
  virtual void exitFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext * /*ctx*/) override { }

  virtual void enterInsert_stmt(PotatoSQLParser::Insert_stmtContext * /*ctx*/) override { }
  virtual void exitInsert_stmt(PotatoSQLParser::Insert_stmtContext * /*ctx*/) override { }

  virtual void enterPragma_stmt(PotatoSQLParser::Pragma_stmtContext * /*ctx*/) override { }
  virtual void exitPragma_stmt(PotatoSQLParser::Pragma_stmtContext * /*ctx*/) override { }

  virtual void enterReindex_stmt(PotatoSQLParser::Reindex_stmtContext * /*ctx*/) override { }
  virtual void exitReindex_stmt(PotatoSQLParser::Reindex_stmtContext * /*ctx*/) override { }

  virtual void enterRelease_stmt(PotatoSQLParser::Release_stmtContext * /*ctx*/) override { }
  virtual void exitRelease_stmt(PotatoSQLParser::Release_stmtContext * /*ctx*/) override { }

  virtual void enterRollback_stmt(PotatoSQLParser::Rollback_stmtContext * /*ctx*/) override { }
  virtual void exitRollback_stmt(PotatoSQLParser::Rollback_stmtContext * /*ctx*/) override { }

  virtual void enterSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext * /*ctx*/) override { }
  virtual void exitSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext * /*ctx*/) override { }

  virtual void enterSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext * /*ctx*/) override { }
  virtual void exitSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_stmt(PotatoSQLParser::Select_stmtContext * /*ctx*/) override { }
  virtual void exitSelect_stmt(PotatoSQLParser::Select_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_or_values(PotatoSQLParser::Select_or_valuesContext * /*ctx*/) override { }
  virtual void exitSelect_or_values(PotatoSQLParser::Select_or_valuesContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt(PotatoSQLParser::Update_stmtContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt(PotatoSQLParser::Update_stmtContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext * /*ctx*/) override { }
  virtual void exitVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext * /*ctx*/) override { }

  virtual void enterColumn_def(PotatoSQLParser::Column_defContext * /*ctx*/) override { }
  virtual void exitColumn_def(PotatoSQLParser::Column_defContext * /*ctx*/) override { }

  virtual void enterType_name(PotatoSQLParser::Type_nameContext * /*ctx*/) override { }
  virtual void exitType_name(PotatoSQLParser::Type_nameContext * /*ctx*/) override { }

  virtual void enterColumn_constraint(PotatoSQLParser::Column_constraintContext * /*ctx*/) override { }
  virtual void exitColumn_constraint(PotatoSQLParser::Column_constraintContext * /*ctx*/) override { }

  virtual void enterConflict_clause(PotatoSQLParser::Conflict_clauseContext * /*ctx*/) override { }
  virtual void exitConflict_clause(PotatoSQLParser::Conflict_clauseContext * /*ctx*/) override { }

  virtual void enterExpr(PotatoSQLParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(PotatoSQLParser::ExprContext * /*ctx*/) override { }

  virtual void enterForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext * /*ctx*/) override { }
  virtual void exitForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext * /*ctx*/) override { }

  virtual void enterRaise_function(PotatoSQLParser::Raise_functionContext * /*ctx*/) override { }
  virtual void exitRaise_function(PotatoSQLParser::Raise_functionContext * /*ctx*/) override { }

  virtual void enterIndexed_column(PotatoSQLParser::Indexed_columnContext * /*ctx*/) override { }
  virtual void exitIndexed_column(PotatoSQLParser::Indexed_columnContext * /*ctx*/) override { }

  virtual void enterTable_constraint(PotatoSQLParser::Table_constraintContext * /*ctx*/) override { }
  virtual void exitTable_constraint(PotatoSQLParser::Table_constraintContext * /*ctx*/) override { }

  virtual void enterWith_clause(PotatoSQLParser::With_clauseContext * /*ctx*/) override { }
  virtual void exitWith_clause(PotatoSQLParser::With_clauseContext * /*ctx*/) override { }

  virtual void enterQualified_table_name(PotatoSQLParser::Qualified_table_nameContext * /*ctx*/) override { }
  virtual void exitQualified_table_name(PotatoSQLParser::Qualified_table_nameContext * /*ctx*/) override { }

  virtual void enterOrdering_term(PotatoSQLParser::Ordering_termContext * /*ctx*/) override { }
  virtual void exitOrdering_term(PotatoSQLParser::Ordering_termContext * /*ctx*/) override { }

  virtual void enterPragma_value(PotatoSQLParser::Pragma_valueContext * /*ctx*/) override { }
  virtual void exitPragma_value(PotatoSQLParser::Pragma_valueContext * /*ctx*/) override { }

  virtual void enterCommon_table_expression(PotatoSQLParser::Common_table_expressionContext * /*ctx*/) override { }
  virtual void exitCommon_table_expression(PotatoSQLParser::Common_table_expressionContext * /*ctx*/) override { }

  virtual void enterResult_column(PotatoSQLParser::Result_columnContext * /*ctx*/) override { }
  virtual void exitResult_column(PotatoSQLParser::Result_columnContext * /*ctx*/) override { }

  virtual void enterTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext * /*ctx*/) override { }
  virtual void exitTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext * /*ctx*/) override { }

  virtual void enterJoin_clause(PotatoSQLParser::Join_clauseContext * /*ctx*/) override { }
  virtual void exitJoin_clause(PotatoSQLParser::Join_clauseContext * /*ctx*/) override { }

  virtual void enterJoin_operator(PotatoSQLParser::Join_operatorContext * /*ctx*/) override { }
  virtual void exitJoin_operator(PotatoSQLParser::Join_operatorContext * /*ctx*/) override { }

  virtual void enterJoin_constraint(PotatoSQLParser::Join_constraintContext * /*ctx*/) override { }
  virtual void exitJoin_constraint(PotatoSQLParser::Join_constraintContext * /*ctx*/) override { }

  virtual void enterSelect_core(PotatoSQLParser::Select_coreContext * /*ctx*/) override { }
  virtual void exitSelect_core(PotatoSQLParser::Select_coreContext * /*ctx*/) override { }

  virtual void enterCompound_operator(PotatoSQLParser::Compound_operatorContext * /*ctx*/) override { }
  virtual void exitCompound_operator(PotatoSQLParser::Compound_operatorContext * /*ctx*/) override { }

  virtual void enterSigned_number(PotatoSQLParser::Signed_numberContext * /*ctx*/) override { }
  virtual void exitSigned_number(PotatoSQLParser::Signed_numberContext * /*ctx*/) override { }

  virtual void enterLiteral_value(PotatoSQLParser::Literal_valueContext * /*ctx*/) override { }
  virtual void exitLiteral_value(PotatoSQLParser::Literal_valueContext * /*ctx*/) override { }

  virtual void enterUnary_operator(PotatoSQLParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(PotatoSQLParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterError_message(PotatoSQLParser::Error_messageContext * /*ctx*/) override { }
  virtual void exitError_message(PotatoSQLParser::Error_messageContext * /*ctx*/) override { }

  virtual void enterModule_argument(PotatoSQLParser::Module_argumentContext * /*ctx*/) override { }
  virtual void exitModule_argument(PotatoSQLParser::Module_argumentContext * /*ctx*/) override { }

  virtual void enterColumn_alias(PotatoSQLParser::Column_aliasContext * /*ctx*/) override { }
  virtual void exitColumn_alias(PotatoSQLParser::Column_aliasContext * /*ctx*/) override { }

  virtual void enterKeyword(PotatoSQLParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(PotatoSQLParser::KeywordContext * /*ctx*/) override { }

  virtual void enterName(PotatoSQLParser::NameContext * /*ctx*/) override { }
  virtual void exitName(PotatoSQLParser::NameContext * /*ctx*/) override { }

  virtual void enterFunction_name(PotatoSQLParser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(PotatoSQLParser::Function_nameContext * /*ctx*/) override { }

  virtual void enterDatabase_name(PotatoSQLParser::Database_nameContext * /*ctx*/) override { }
  virtual void exitDatabase_name(PotatoSQLParser::Database_nameContext * /*ctx*/) override { }

  virtual void enterSchema_name(PotatoSQLParser::Schema_nameContext * /*ctx*/) override { }
  virtual void exitSchema_name(PotatoSQLParser::Schema_nameContext * /*ctx*/) override { }

  virtual void enterTable_function_name(PotatoSQLParser::Table_function_nameContext * /*ctx*/) override { }
  virtual void exitTable_function_name(PotatoSQLParser::Table_function_nameContext * /*ctx*/) override { }

  virtual void enterTable_name(PotatoSQLParser::Table_nameContext * /*ctx*/) override { }
  virtual void exitTable_name(PotatoSQLParser::Table_nameContext * /*ctx*/) override { }

  virtual void enterTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext * /*ctx*/) override { }
  virtual void exitTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext * /*ctx*/) override { }

  virtual void enterNew_table_name(PotatoSQLParser::New_table_nameContext * /*ctx*/) override { }
  virtual void exitNew_table_name(PotatoSQLParser::New_table_nameContext * /*ctx*/) override { }

  virtual void enterColumn_name(PotatoSQLParser::Column_nameContext * /*ctx*/) override { }
  virtual void exitColumn_name(PotatoSQLParser::Column_nameContext * /*ctx*/) override { }

  virtual void enterCollation_name(PotatoSQLParser::Collation_nameContext * /*ctx*/) override { }
  virtual void exitCollation_name(PotatoSQLParser::Collation_nameContext * /*ctx*/) override { }

  virtual void enterForeign_table(PotatoSQLParser::Foreign_tableContext * /*ctx*/) override { }
  virtual void exitForeign_table(PotatoSQLParser::Foreign_tableContext * /*ctx*/) override { }

  virtual void enterIndex_name(PotatoSQLParser::Index_nameContext * /*ctx*/) override { }
  virtual void exitIndex_name(PotatoSQLParser::Index_nameContext * /*ctx*/) override { }

  virtual void enterTrigger_name(PotatoSQLParser::Trigger_nameContext * /*ctx*/) override { }
  virtual void exitTrigger_name(PotatoSQLParser::Trigger_nameContext * /*ctx*/) override { }

  virtual void enterView_name(PotatoSQLParser::View_nameContext * /*ctx*/) override { }
  virtual void exitView_name(PotatoSQLParser::View_nameContext * /*ctx*/) override { }

  virtual void enterModule_name(PotatoSQLParser::Module_nameContext * /*ctx*/) override { }
  virtual void exitModule_name(PotatoSQLParser::Module_nameContext * /*ctx*/) override { }

  virtual void enterPragma_name(PotatoSQLParser::Pragma_nameContext * /*ctx*/) override { }
  virtual void exitPragma_name(PotatoSQLParser::Pragma_nameContext * /*ctx*/) override { }

  virtual void enterSavepoint_name(PotatoSQLParser::Savepoint_nameContext * /*ctx*/) override { }
  virtual void exitSavepoint_name(PotatoSQLParser::Savepoint_nameContext * /*ctx*/) override { }

  virtual void enterTable_alias(PotatoSQLParser::Table_aliasContext * /*ctx*/) override { }
  virtual void exitTable_alias(PotatoSQLParser::Table_aliasContext * /*ctx*/) override { }

  virtual void enterTransaction_name(PotatoSQLParser::Transaction_nameContext * /*ctx*/) override { }
  virtual void exitTransaction_name(PotatoSQLParser::Transaction_nameContext * /*ctx*/) override { }

  virtual void enterAny_name(PotatoSQLParser::Any_nameContext * /*ctx*/) override { }
  virtual void exitAny_name(PotatoSQLParser::Any_nameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace potatosql
