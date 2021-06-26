
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PotatoSQLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PotatoSQLParser.
 */
class  PotatoSQLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PotatoSQLParser.
   */
    virtual antlrcpp::Any visitMain(PotatoSQLParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitError(PotatoSQLParser::ErrorContext *context) = 0;

    virtual antlrcpp::Any visitSql_stmt_list(PotatoSQLParser::Sql_stmt_listContext *context) = 0;

    virtual antlrcpp::Any visitSql_stmt(PotatoSQLParser::Sql_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAlter_table_stmt(PotatoSQLParser::Alter_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitShow_tables_stmt(PotatoSQLParser::Show_tables_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDescribe_table_stmt(PotatoSQLParser::Describe_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAnalyze_stmt(PotatoSQLParser::Analyze_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAttach_stmt(PotatoSQLParser::Attach_stmtContext *context) = 0;

    virtual antlrcpp::Any visitBegin_stmt(PotatoSQLParser::Begin_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCommit_stmt(PotatoSQLParser::Commit_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCompound_select_stmt(PotatoSQLParser::Compound_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_index_stmt(PotatoSQLParser::Create_index_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_table_stmt(PotatoSQLParser::Create_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_trigger_stmt(PotatoSQLParser::Create_trigger_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_view_stmt(PotatoSQLParser::Create_view_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_virtual_table_stmt(PotatoSQLParser::Create_virtual_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDelete_stmt(PotatoSQLParser::Delete_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDelete_stmt_limited(PotatoSQLParser::Delete_stmt_limitedContext *context) = 0;

    virtual antlrcpp::Any visitDetach_stmt(PotatoSQLParser::Detach_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDrop_index_stmt(PotatoSQLParser::Drop_index_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDrop_table_stmt(PotatoSQLParser::Drop_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDrop_trigger_stmt(PotatoSQLParser::Drop_trigger_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDrop_view_stmt(PotatoSQLParser::Drop_view_stmtContext *context) = 0;

    virtual antlrcpp::Any visitFactored_select_stmt(PotatoSQLParser::Factored_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitInsert_prefix(PotatoSQLParser::Insert_prefixContext *context) = 0;

    virtual antlrcpp::Any visitInsert_tuple(PotatoSQLParser::Insert_tupleContext *context) = 0;

    virtual antlrcpp::Any visitInsert_tuples(PotatoSQLParser::Insert_tuplesContext *context) = 0;

    virtual antlrcpp::Any visitInsert_columns(PotatoSQLParser::Insert_columnsContext *context) = 0;

    virtual antlrcpp::Any visitInsert_stmt(PotatoSQLParser::Insert_stmtContext *context) = 0;

    virtual antlrcpp::Any visitPragma_stmt(PotatoSQLParser::Pragma_stmtContext *context) = 0;

    virtual antlrcpp::Any visitReindex_stmt(PotatoSQLParser::Reindex_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRelease_stmt(PotatoSQLParser::Release_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRollback_stmt(PotatoSQLParser::Rollback_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSavepoint_stmt(PotatoSQLParser::Savepoint_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSimple_select_stmt(PotatoSQLParser::Simple_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSelect_stmt(PotatoSQLParser::Select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSelect_or_values(PotatoSQLParser::Select_or_valuesContext *context) = 0;

    virtual antlrcpp::Any visitUpdate_stmt(PotatoSQLParser::Update_stmtContext *context) = 0;

    virtual antlrcpp::Any visitUpdate_stmt_limited(PotatoSQLParser::Update_stmt_limitedContext *context) = 0;

    virtual antlrcpp::Any visitVacuum_stmt(PotatoSQLParser::Vacuum_stmtContext *context) = 0;

    virtual antlrcpp::Any visitColumn_def(PotatoSQLParser::Column_defContext *context) = 0;

    virtual antlrcpp::Any visitType_name(PotatoSQLParser::Type_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_constraint(PotatoSQLParser::Column_constraintContext *context) = 0;

    virtual antlrcpp::Any visitNot_null(PotatoSQLParser::Not_nullContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_key(PotatoSQLParser::Primary_keyContext *context) = 0;

    virtual antlrcpp::Any visitAutoincrement(PotatoSQLParser::AutoincrementContext *context) = 0;

    virtual antlrcpp::Any visitConflict_clause(PotatoSQLParser::Conflict_clauseContext *context) = 0;

    virtual antlrcpp::Any visitFunction_args(PotatoSQLParser::Function_argsContext *context) = 0;

    virtual antlrcpp::Any visitExpr(PotatoSQLParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitForeign_key_clause(PotatoSQLParser::Foreign_key_clauseContext *context) = 0;

    virtual antlrcpp::Any visitRaise_function(PotatoSQLParser::Raise_functionContext *context) = 0;

    virtual antlrcpp::Any visitIndexed_column(PotatoSQLParser::Indexed_columnContext *context) = 0;

    virtual antlrcpp::Any visitTable_constraint(PotatoSQLParser::Table_constraintContext *context) = 0;

    virtual antlrcpp::Any visitWith_clause(PotatoSQLParser::With_clauseContext *context) = 0;

    virtual antlrcpp::Any visitQualified_table_name(PotatoSQLParser::Qualified_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitOrdering_term(PotatoSQLParser::Ordering_termContext *context) = 0;

    virtual antlrcpp::Any visitPragma_value(PotatoSQLParser::Pragma_valueContext *context) = 0;

    virtual antlrcpp::Any visitCommon_table_expression(PotatoSQLParser::Common_table_expressionContext *context) = 0;

    virtual antlrcpp::Any visitResult_column(PotatoSQLParser::Result_columnContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_subquery(PotatoSQLParser::Table_or_subqueryContext *context) = 0;

    virtual antlrcpp::Any visitJoin_clause(PotatoSQLParser::Join_clauseContext *context) = 0;

    virtual antlrcpp::Any visitJoin_operator(PotatoSQLParser::Join_operatorContext *context) = 0;

    virtual antlrcpp::Any visitJoin_constraint(PotatoSQLParser::Join_constraintContext *context) = 0;

    virtual antlrcpp::Any visitColumn_list(PotatoSQLParser::Column_listContext *context) = 0;

    virtual antlrcpp::Any visitSelect_core(PotatoSQLParser::Select_coreContext *context) = 0;

    virtual antlrcpp::Any visitWhere_clause(PotatoSQLParser::Where_clauseContext *context) = 0;

    virtual antlrcpp::Any visitCompound_operator(PotatoSQLParser::Compound_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSigned_number(PotatoSQLParser::Signed_numberContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_value(PotatoSQLParser::Literal_valueContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(PotatoSQLParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitError_message(PotatoSQLParser::Error_messageContext *context) = 0;

    virtual antlrcpp::Any visitModule_argument(PotatoSQLParser::Module_argumentContext *context) = 0;

    virtual antlrcpp::Any visitColumn_alias(PotatoSQLParser::Column_aliasContext *context) = 0;

    virtual antlrcpp::Any visitKeyword(PotatoSQLParser::KeywordContext *context) = 0;

    virtual antlrcpp::Any visitName(PotatoSQLParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(PotatoSQLParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitDatabase_name(PotatoSQLParser::Database_nameContext *context) = 0;

    virtual antlrcpp::Any visitSchema_name(PotatoSQLParser::Schema_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_function_name(PotatoSQLParser::Table_function_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_name(PotatoSQLParser::Table_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_index_name(PotatoSQLParser::Table_or_index_nameContext *context) = 0;

    virtual antlrcpp::Any visitNew_table_name(PotatoSQLParser::New_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name(PotatoSQLParser::Column_nameContext *context) = 0;

    virtual antlrcpp::Any visitCollation_name(PotatoSQLParser::Collation_nameContext *context) = 0;

    virtual antlrcpp::Any visitForeign_table(PotatoSQLParser::Foreign_tableContext *context) = 0;

    virtual antlrcpp::Any visitIndex_name(PotatoSQLParser::Index_nameContext *context) = 0;

    virtual antlrcpp::Any visitTrigger_name(PotatoSQLParser::Trigger_nameContext *context) = 0;

    virtual antlrcpp::Any visitView_name(PotatoSQLParser::View_nameContext *context) = 0;

    virtual antlrcpp::Any visitModule_name(PotatoSQLParser::Module_nameContext *context) = 0;

    virtual antlrcpp::Any visitPragma_name(PotatoSQLParser::Pragma_nameContext *context) = 0;

    virtual antlrcpp::Any visitSavepoint_name(PotatoSQLParser::Savepoint_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_alias(PotatoSQLParser::Table_aliasContext *context) = 0;

    virtual antlrcpp::Any visitTransaction_name(PotatoSQLParser::Transaction_nameContext *context) = 0;

    virtual antlrcpp::Any visitAny_name(PotatoSQLParser::Any_nameContext *context) = 0;


};

