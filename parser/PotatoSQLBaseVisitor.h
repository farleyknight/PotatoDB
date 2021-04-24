
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PotatoSQLVisitor.h"


namespace potatosql {

/**
 * This class provides an empty implementation of PotatoSQLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PotatoSQLBaseVisitor : public PotatoSQLVisitor {
public:

  virtual antlrcpp::Any visitMain(PotatoSQLParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError(PotatoSQLParser::ErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt(PotatoSQLParser::Sql_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttach_stmt(PotatoSQLParser::Attach_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBegin_stmt(PotatoSQLParser::Begin_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommit_stmt(PotatoSQLParser::Commit_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelete_stmt(PotatoSQLParser::Delete_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDetach_stmt(PotatoSQLParser::Detach_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_prefix(PotatoSQLParser::Insert_prefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_tuple(PotatoSQLParser::Insert_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_tuples(PotatoSQLParser::Insert_tuplesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_columns(PotatoSQLParser::Insert_columnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_stmt(PotatoSQLParser::Insert_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_stmt(PotatoSQLParser::Pragma_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReindex_stmt(PotatoSQLParser::Reindex_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelease_stmt(PotatoSQLParser::Release_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollback_stmt(PotatoSQLParser::Rollback_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_stmt(PotatoSQLParser::Select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_or_values(PotatoSQLParser::Select_or_valuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdate_stmt(PotatoSQLParser::Update_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_def(PotatoSQLParser::Column_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_name(PotatoSQLParser::Type_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_constraint(PotatoSQLParser::Column_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConflict_clause(PotatoSQLParser::Conflict_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(PotatoSQLParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRaise_function(PotatoSQLParser::Raise_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexed_column(PotatoSQLParser::Indexed_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_constraint(PotatoSQLParser::Table_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith_clause(PotatoSQLParser::With_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualified_table_name(PotatoSQLParser::Qualified_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdering_term(PotatoSQLParser::Ordering_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_value(PotatoSQLParser::Pragma_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommon_table_expression(PotatoSQLParser::Common_table_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult_column(PotatoSQLParser::Result_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_clause(PotatoSQLParser::Join_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_operator(PotatoSQLParser::Join_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_constraint(PotatoSQLParser::Join_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_list(PotatoSQLParser::Column_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_core(PotatoSQLParser::Select_coreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_operator(PotatoSQLParser::Compound_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigned_number(PotatoSQLParser::Signed_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral_value(PotatoSQLParser::Literal_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(PotatoSQLParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_message(PotatoSQLParser::Error_messageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_argument(PotatoSQLParser::Module_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_alias(PotatoSQLParser::Column_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(PotatoSQLParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(PotatoSQLParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_name(PotatoSQLParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDatabase_name(PotatoSQLParser::Database_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSchema_name(PotatoSQLParser::Schema_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_function_name(PotatoSQLParser::Table_function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_name(PotatoSQLParser::Table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNew_table_name(PotatoSQLParser::New_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_name(PotatoSQLParser::Column_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollation_name(PotatoSQLParser::Collation_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeign_table(PotatoSQLParser::Foreign_tableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_name(PotatoSQLParser::Index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrigger_name(PotatoSQLParser::Trigger_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitView_name(PotatoSQLParser::View_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_name(PotatoSQLParser::Module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_name(PotatoSQLParser::Pragma_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepoint_name(PotatoSQLParser::Savepoint_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_alias(PotatoSQLParser::Table_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransaction_name(PotatoSQLParser::Transaction_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAny_name(PotatoSQLParser::Any_nameContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace potatosql
