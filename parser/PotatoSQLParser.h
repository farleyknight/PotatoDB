
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace potatodb {


class  PotatoSQLParser : public antlr4::Parser {
public:
  enum {
    SCOL = 1, DOT = 2, OPEN_PAR = 3, CLOSE_PAR = 4, COMMA = 5, ASSIGN = 6, 
    STAR = 7, PLUS = 8, MINUS = 9, TILDE = 10, PIPE2 = 11, DIV = 12, MOD = 13, 
    LT2 = 14, GT2 = 15, AMP = 16, PIPE = 17, LT = 18, LT_EQ = 19, GT = 20, 
    GT_EQ = 21, EQ = 22, NOT_EQ1 = 23, NOT_EQ2 = 24, K_AND = 25, K_AS = 26, 
    K_ASC = 27, K_BEGIN = 28, K_GROUP = 29, K_JOIN = 30, K_LIMIT = 31, K_NOT = 32, 
    K_ON = 33, K_OR = 34, K_ORDER = 35, K_OUTER = 36, IDENTIFIER = 37, NUMERIC_LITERAL = 38, 
    STRING_LITERAL = 39, BLOB_LITERAL = 40, SINGLE_LINE_COMMENT = 41, MULTILINE_COMMENT = 42, 
    SPACES = 43, UNEXPECTED_CHAR = 44, K_ALTER = 45, K_TABLE = 46, K_RENAME = 47, 
    K_TO = 48, K_ADD = 49, K_COLUMN = 50, K_COMMIT = 51, K_END = 52, K_UNION = 53, 
    K_ALL = 54, K_INTERSECT = 55, K_EXCEPT = 56, K_BY = 57, K_OFFSET = 58, 
    K_CREATE = 59, K_UNIQUE = 60, K_INDEX = 61, K_IF = 62, K_EXISTS = 63, 
    K_WHERE = 64, K_TEMP = 65, K_TEMPORARY = 66, K_WITHOUT = 67, K_DELETE = 68, 
    K_FROM = 69, K_DROP = 70, K_INSERT = 71, K_REPLACE = 72, K_ROLLBACK = 73, 
    K_ABORT = 74, K_FAIL = 75, K_IGNORE = 76, K_INTO = 77, K_VALUES = 78, 
    K_DEFAULT = 79, K_PRAGMA = 80, K_TRANSACTION = 81, K_SAVEPOINT = 82, 
    K_SELECT = 83, K_DISTINCT = 84, K_HAVING = 85, K_UPDATE = 86, K_SET = 87, 
    K_CONSTRAINT = 88, K_PRIMARY = 89, K_KEY = 90, K_DESC = 91, K_AUTOINCREMENT = 92, 
    K_NULL = 93, K_CHECK = 94, K_COLLATE = 95, K_CONFLICT = 96, BIND_PARAMETER = 97, 
    K_CAST = 98, K_CASE = 99, K_WHEN = 100, K_THEN = 101, K_ELSE = 102, 
    K_IS = 103, K_BETWEEN = 104, K_IN = 105, K_LIKE = 106, K_GLOB = 107, 
    K_REGEXP = 108, K_MATCH = 109, K_ESCAPE = 110, K_ISNULL = 111, K_NOTNULL = 112, 
    K_RAISE = 113, K_REFERENCES = 114, K_CASCADE = 115, K_RESTRICT = 116, 
    K_NO = 117, K_ACTION = 118, K_DEFERRABLE = 119, K_INITIALLY = 120, K_DEFERRED = 121, 
    K_IMMEDIATE = 122, K_FOREIGN = 123, K_WITH = 124, K_RECURSIVE = 125, 
    K_INDEXED = 126, K_NATURAL = 127, K_LEFT = 128, K_INNER = 129, K_CROSS = 130, 
    K_USING = 131, K_CURRENT_TIME = 132, K_CURRENT_DATE = 133, K_CURRENT_TIMESTAMP = 134
  };

  enum {
    RuleMain = 0, RuleSql_stmt_list = 1, RuleSql_stmt = 2, RuleAlter_table_stmt = 3, 
    RuleBegin_stmt = 4, RuleCommit_stmt = 5, RuleCompound_select_stmt = 6, 
    RuleCreate_index_stmt = 7, RuleCreate_table_stmt = 8, RuleDelete_stmt = 9, 
    RuleDelete_stmt_limited = 10, RuleDrop_index_stmt = 11, RuleDrop_table_stmt = 12, 
    RuleFactored_select_stmt = 13, RuleInsert_stmt = 14, RulePragma_stmt = 15, 
    RuleRollback_stmt = 16, RuleSimple_select_stmt = 17, RuleSelect_stmt = 18, 
    RuleSelect_or_values = 19, RuleUpdate_stmt = 20, RuleUpdate_stmt_limited = 21, 
    RuleColumn_def = 22, RuleType_name = 23, RuleColumn_constraint = 24, 
    RuleConflict_clause = 25, RuleExpr = 26, RuleRaise_function = 27, RuleForeign_key_clause = 28, 
    RuleIndexed_column = 29, RuleTable_constraint = 30, RuleWith_clause = 31, 
    RuleQualified_table_name = 32, RuleOrdering_term = 33, RulePragma_value = 34, 
    RuleCommon_table_expression = 35, RuleResult_column = 36, RuleTable_or_subquery = 37, 
    RuleJoin_clause = 38, RuleJoin_operator = 39, RuleJoin_constraint = 40, 
    RuleSelect_core = 41, RuleCompound_operator = 42, RuleSigned_number = 43, 
    RuleLiteral_value = 44, RuleUnary_operator = 45, RuleError_message = 46, 
    RuleModule_argument = 47, RuleColumn_alias = 48, RuleName = 49, RuleFunction_name = 50, 
    RuleDatabase_name = 51, RuleSchema_name = 52, RuleTable_function_name = 53, 
    RuleTable_name = 54, RuleTable_or_index_name = 55, RuleNew_table_name = 56, 
    RuleColumn_name = 57, RuleCollation_name = 58, RuleForeign_table = 59, 
    RuleIndex_name = 60, RulePragma_name = 61, RuleSavepoint_name = 62, 
    RuleTransaction_name = 63, RuleTable_alias = 64, RuleAny_name = 65, 
    RuleKeyword = 66
  };

  explicit PotatoSQLParser(antlr4::TokenStream *input);
  ~PotatoSQLParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class Sql_stmt_listContext;
  class Sql_stmtContext;
  class Alter_table_stmtContext;
  class Begin_stmtContext;
  class Commit_stmtContext;
  class Compound_select_stmtContext;
  class Create_index_stmtContext;
  class Create_table_stmtContext;
  class Delete_stmtContext;
  class Delete_stmt_limitedContext;
  class Drop_index_stmtContext;
  class Drop_table_stmtContext;
  class Factored_select_stmtContext;
  class Insert_stmtContext;
  class Pragma_stmtContext;
  class Rollback_stmtContext;
  class Simple_select_stmtContext;
  class Select_stmtContext;
  class Select_or_valuesContext;
  class Update_stmtContext;
  class Update_stmt_limitedContext;
  class Column_defContext;
  class Type_nameContext;
  class Column_constraintContext;
  class Conflict_clauseContext;
  class ExprContext;
  class Raise_functionContext;
  class Foreign_key_clauseContext;
  class Indexed_columnContext;
  class Table_constraintContext;
  class With_clauseContext;
  class Qualified_table_nameContext;
  class Ordering_termContext;
  class Pragma_valueContext;
  class Common_table_expressionContext;
  class Result_columnContext;
  class Table_or_subqueryContext;
  class Join_clauseContext;
  class Join_operatorContext;
  class Join_constraintContext;
  class Select_coreContext;
  class Compound_operatorContext;
  class Signed_numberContext;
  class Literal_valueContext;
  class Unary_operatorContext;
  class Error_messageContext;
  class Module_argumentContext;
  class Column_aliasContext;
  class NameContext;
  class Function_nameContext;
  class Database_nameContext;
  class Schema_nameContext;
  class Table_function_nameContext;
  class Table_nameContext;
  class Table_or_index_nameContext;
  class New_table_nameContext;
  class Column_nameContext;
  class Collation_nameContext;
  class Foreign_tableContext;
  class Index_nameContext;
  class Pragma_nameContext;
  class Savepoint_nameContext;
  class Transaction_nameContext;
  class Table_aliasContext;
  class Any_nameContext;
  class KeywordContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Sql_stmt_listContext *> sql_stmt_list();
    Sql_stmt_listContext* sql_stmt_list(size_t i);

   
  };

  MainContext* main();

  class  Sql_stmt_listContext : public antlr4::ParserRuleContext {
  public:
    Sql_stmt_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sql_stmtContext *> sql_stmt();
    Sql_stmtContext* sql_stmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SCOL();
    antlr4::tree::TerminalNode* SCOL(size_t i);

   
  };

  Sql_stmt_listContext* sql_stmt_list();

  class  Sql_stmtContext : public antlr4::ParserRuleContext {
  public:
    Sql_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Alter_table_stmtContext *alter_table_stmt();
    Begin_stmtContext *begin_stmt();
    Commit_stmtContext *commit_stmt();
    Create_index_stmtContext *create_index_stmt();
    Compound_select_stmtContext *compound_select_stmt();
    Create_table_stmtContext *create_table_stmt();
    Drop_table_stmtContext *drop_table_stmt();
    Delete_stmtContext *delete_stmt();
    Drop_index_stmtContext *drop_index_stmt();
    Factored_select_stmtContext *factored_select_stmt();
    Insert_stmtContext *insert_stmt();
    Pragma_stmtContext *pragma_stmt();
    Rollback_stmtContext *rollback_stmt();
    Simple_select_stmtContext *simple_select_stmt();
    Update_stmtContext *update_stmt();
    Update_stmt_limitedContext *update_stmt_limited();

   
  };

  Sql_stmtContext* sql_stmt();

  class  Alter_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    Alter_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ALTER();
    antlr4::tree::TerminalNode *K_TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *K_RENAME();
    antlr4::tree::TerminalNode *K_TO();
    New_table_nameContext *new_table_name();
    antlr4::tree::TerminalNode *K_ADD();
    Column_defContext *column_def();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *K_COLUMN();

   
  };

  Alter_table_stmtContext* alter_table_stmt();

  class  Begin_stmtContext : public antlr4::ParserRuleContext {
  public:
    Begin_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_BEGIN();

   
  };

  Begin_stmtContext* begin_stmt();

  class  Commit_stmtContext : public antlr4::ParserRuleContext {
  public:
    Commit_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_COMMIT();
    antlr4::tree::TerminalNode *K_END();

   
  };

  Commit_stmtContext* commit_stmt();

  class  Compound_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Compound_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_coreContext *> select_core();
    Select_coreContext* select_core(size_t i);
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_LIMIT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_UNION();
    antlr4::tree::TerminalNode* K_UNION(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_INTERSECT();
    antlr4::tree::TerminalNode* K_INTERSECT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_EXCEPT();
    antlr4::tree::TerminalNode* K_EXCEPT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();
    std::vector<antlr4::tree::TerminalNode *> K_ALL();
    antlr4::tree::TerminalNode* K_ALL(size_t i);

   
  };

  Compound_select_stmtContext* compound_select_stmt();

  class  Create_index_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_index_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_CREATE();
    antlr4::tree::TerminalNode *K_INDEX();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *K_ON();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Indexed_columnContext *> indexed_column();
    Indexed_columnContext* indexed_column(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *K_UNIQUE();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_EXISTS();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_WHERE();
    ExprContext *expr();

   
  };

  Create_index_stmtContext* create_index_stmt();

  class  Create_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_CREATE();
    antlr4::tree::TerminalNode *K_TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_defContext *> column_def();
    Column_defContext* column_def(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *K_AS();
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_EXISTS();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *K_TEMP();
    antlr4::tree::TerminalNode *K_TEMPORARY();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Table_constraintContext *> table_constraint();
    Table_constraintContext* table_constraint(size_t i);
    antlr4::tree::TerminalNode *K_WITHOUT();
    antlr4::tree::TerminalNode *IDENTIFIER();

   
  };

  Create_table_stmtContext* create_table_stmt();

  class  Delete_stmtContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_DELETE();
    antlr4::tree::TerminalNode *K_FROM();
    Qualified_table_nameContext *qualified_table_name();
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_WHERE();
    ExprContext *expr();

   
  };

  Delete_stmtContext* delete_stmt();

  class  Delete_stmt_limitedContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmt_limitedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_DELETE();
    antlr4::tree::TerminalNode *K_FROM();
    Qualified_table_nameContext *qualified_table_name();
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_WHERE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *K_LIMIT();
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Delete_stmt_limitedContext* delete_stmt_limited();

  class  Drop_index_stmtContext : public antlr4::ParserRuleContext {
  public:
    Drop_index_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_DROP();
    antlr4::tree::TerminalNode *K_INDEX();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_EXISTS();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();

   
  };

  Drop_index_stmtContext* drop_index_stmt();

  class  Drop_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    Drop_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_DROP();
    antlr4::tree::TerminalNode *K_TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_EXISTS();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();

   
  };

  Drop_table_stmtContext* drop_table_stmt();

  class  Factored_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Factored_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_coreContext *> select_core();
    Select_coreContext* select_core(size_t i);
    With_clauseContext *with_clause();
    std::vector<Compound_operatorContext *> compound_operator();
    Compound_operatorContext* compound_operator(size_t i);
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_LIMIT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();

   
  };

  Factored_select_stmtContext* factored_select_stmt();

  class  Insert_stmtContext : public antlr4::ParserRuleContext {
  public:
    Insert_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_INTO();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *K_INSERT();
    antlr4::tree::TerminalNode *K_REPLACE();
    antlr4::tree::TerminalNode *K_OR();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_FAIL();
    antlr4::tree::TerminalNode *K_IGNORE();
    antlr4::tree::TerminalNode *K_VALUES();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *K_DEFAULT();
    With_clauseContext *with_clause();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Insert_stmtContext* insert_stmt();

  class  Pragma_stmtContext : public antlr4::ParserRuleContext {
  public:
    Pragma_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_PRAGMA();
    Pragma_nameContext *pragma_name();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ASSIGN();
    Pragma_valueContext *pragma_value();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();

   
  };

  Pragma_stmtContext* pragma_stmt();

  class  Rollback_stmtContext : public antlr4::ParserRuleContext {
  public:
    Rollback_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_TRANSACTION();
    antlr4::tree::TerminalNode *K_TO();
    Savepoint_nameContext *savepoint_name();
    Transaction_nameContext *transaction_name();
    antlr4::tree::TerminalNode *K_SAVEPOINT();

   
  };

  Rollback_stmtContext* rollback_stmt();

  class  Simple_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Simple_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_coreContext *select_core();
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_LIMIT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();

   
  };

  Simple_select_stmtContext* simple_select_stmt();

  class  Select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_or_valuesContext *> select_or_values();
    Select_or_valuesContext* select_or_values(size_t i);
    With_clauseContext *with_clause();
    std::vector<Compound_operatorContext *> compound_operator();
    Compound_operatorContext* compound_operator(size_t i);
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_LIMIT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();

   
  };

  Select_stmtContext* select_stmt();

  class  Select_or_valuesContext : public antlr4::ParserRuleContext {
  public:
    Select_or_valuesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_SELECT();
    std::vector<Result_columnContext *> result_column();
    Result_columnContext* result_column(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_FROM();
    antlr4::tree::TerminalNode *K_WHERE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *K_GROUP();
    antlr4::tree::TerminalNode *K_BY();
    antlr4::tree::TerminalNode *K_DISTINCT();
    antlr4::tree::TerminalNode *K_ALL();
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    antlr4::tree::TerminalNode *K_HAVING();
    antlr4::tree::TerminalNode *K_VALUES();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);

   
  };

  Select_or_valuesContext* select_or_values();

  class  Update_stmtContext : public antlr4::ParserRuleContext {
  public:
    Update_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_UPDATE();
    Qualified_table_nameContext *qualified_table_name();
    antlr4::tree::TerminalNode *K_SET();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_OR();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_REPLACE();
    antlr4::tree::TerminalNode *K_FAIL();
    antlr4::tree::TerminalNode *K_IGNORE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_WHERE();

   
  };

  Update_stmtContext* update_stmt();

  class  Update_stmt_limitedContext : public antlr4::ParserRuleContext {
  public:
    Update_stmt_limitedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_UPDATE();
    Qualified_table_nameContext *qualified_table_name();
    antlr4::tree::TerminalNode *K_SET();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *K_OR();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_REPLACE();
    antlr4::tree::TerminalNode *K_FAIL();
    antlr4::tree::TerminalNode *K_IGNORE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_WHERE();
    antlr4::tree::TerminalNode *K_LIMIT();
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    antlr4::tree::TerminalNode *K_OFFSET();

   
  };

  Update_stmt_limitedContext* update_stmt_limited();

  class  Column_defContext : public antlr4::ParserRuleContext {
  public:
    Column_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Column_nameContext *column_name();
    Type_nameContext *type_name();
    std::vector<Column_constraintContext *> column_constraint();
    Column_constraintContext* column_constraint(size_t i);

   
  };

  Column_defContext* column_def();

  class  Type_nameContext : public antlr4::ParserRuleContext {
  public:
    Type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Signed_numberContext *> signed_number();
    Signed_numberContext* signed_number(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *COMMA();

   
  };

  Type_nameContext* type_name();

  class  Column_constraintContext : public antlr4::ParserRuleContext {
  public:
    Column_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_PRIMARY();
    antlr4::tree::TerminalNode *K_KEY();
    Conflict_clauseContext *conflict_clause();
    antlr4::tree::TerminalNode *K_NULL();
    antlr4::tree::TerminalNode *K_UNIQUE();
    antlr4::tree::TerminalNode *K_CHECK();
    antlr4::tree::TerminalNode *OPEN_PAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *K_DEFAULT();
    antlr4::tree::TerminalNode *K_COLLATE();
    Collation_nameContext *collation_name();
    Foreign_key_clauseContext *foreign_key_clause();
    antlr4::tree::TerminalNode *K_CONSTRAINT();
    NameContext *name();
    Signed_numberContext *signed_number();
    Literal_valueContext *literal_value();
    antlr4::tree::TerminalNode *K_AUTOINCREMENT();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_ASC();
    antlr4::tree::TerminalNode *K_DESC();

   
  };

  Column_constraintContext* column_constraint();

  class  Conflict_clauseContext : public antlr4::ParserRuleContext {
  public:
    Conflict_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ON();
    antlr4::tree::TerminalNode *K_CONFLICT();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_FAIL();
    antlr4::tree::TerminalNode *K_IGNORE();
    antlr4::tree::TerminalNode *K_REPLACE();

   
  };

  Conflict_clauseContext* conflict_clause();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_valueContext *literal_value();
    antlr4::tree::TerminalNode *BIND_PARAMETER();
    Column_nameContext *column_name();
    Table_nameContext *table_name();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    Database_nameContext *database_name();
    Unary_operatorContext *unary_operator();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Function_nameContext *function_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *K_DISTINCT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_CAST();
    antlr4::tree::TerminalNode *K_AS();
    Type_nameContext *type_name();
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *K_EXISTS();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_CASE();
    antlr4::tree::TerminalNode *K_END();
    std::vector<antlr4::tree::TerminalNode *> K_WHEN();
    antlr4::tree::TerminalNode* K_WHEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_THEN();
    antlr4::tree::TerminalNode* K_THEN(size_t i);
    antlr4::tree::TerminalNode *K_ELSE();
    Raise_functionContext *raise_function();
    antlr4::tree::TerminalNode *PIPE2();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LT2();
    antlr4::tree::TerminalNode *GT2();
    antlr4::tree::TerminalNode *AMP();
    antlr4::tree::TerminalNode *PIPE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LT_EQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GT_EQ();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NOT_EQ1();
    antlr4::tree::TerminalNode *NOT_EQ2();
    antlr4::tree::TerminalNode *K_AND();
    antlr4::tree::TerminalNode *K_OR();
    antlr4::tree::TerminalNode *K_IS();
    antlr4::tree::TerminalNode *K_BETWEEN();
    antlr4::tree::TerminalNode *K_IN();
    antlr4::tree::TerminalNode *K_COLLATE();
    Collation_nameContext *collation_name();
    antlr4::tree::TerminalNode *K_LIKE();
    antlr4::tree::TerminalNode *K_GLOB();
    antlr4::tree::TerminalNode *K_REGEXP();
    antlr4::tree::TerminalNode *K_MATCH();
    antlr4::tree::TerminalNode *K_ESCAPE();
    antlr4::tree::TerminalNode *K_ISNULL();
    antlr4::tree::TerminalNode *K_NOTNULL();
    antlr4::tree::TerminalNode *K_NULL();

   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  Raise_functionContext : public antlr4::ParserRuleContext {
  public:
    Raise_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_RAISE();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *K_IGNORE();
    antlr4::tree::TerminalNode *COMMA();
    Error_messageContext *error_message();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_FAIL();

   
  };

  Raise_functionContext* raise_function();

  class  Foreign_key_clauseContext : public antlr4::ParserRuleContext {
  public:
    Foreign_key_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_REFERENCES();
    Foreign_tableContext *foreign_table();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *K_DEFERRABLE();
    std::vector<antlr4::tree::TerminalNode *> K_ON();
    antlr4::tree::TerminalNode* K_ON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_MATCH();
    antlr4::tree::TerminalNode* K_MATCH(size_t i);
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_DELETE();
    antlr4::tree::TerminalNode* K_DELETE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_UPDATE();
    antlr4::tree::TerminalNode* K_UPDATE(size_t i);
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_INITIALLY();
    antlr4::tree::TerminalNode *K_DEFERRED();
    antlr4::tree::TerminalNode *K_IMMEDIATE();
    std::vector<antlr4::tree::TerminalNode *> K_SET();
    antlr4::tree::TerminalNode* K_SET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_NULL();
    antlr4::tree::TerminalNode* K_NULL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_DEFAULT();
    antlr4::tree::TerminalNode* K_DEFAULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_CASCADE();
    antlr4::tree::TerminalNode* K_CASCADE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_RESTRICT();
    antlr4::tree::TerminalNode* K_RESTRICT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_NO();
    antlr4::tree::TerminalNode* K_NO(size_t i);
    std::vector<antlr4::tree::TerminalNode *> K_ACTION();
    antlr4::tree::TerminalNode* K_ACTION(size_t i);

   
  };

  Foreign_key_clauseContext* foreign_key_clause();

  class  Indexed_columnContext : public antlr4::ParserRuleContext {
  public:
    Indexed_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Column_nameContext *column_name();
    antlr4::tree::TerminalNode *K_COLLATE();
    Collation_nameContext *collation_name();
    antlr4::tree::TerminalNode *K_ASC();
    antlr4::tree::TerminalNode *K_DESC();

   
  };

  Indexed_columnContext* indexed_column();

  class  Table_constraintContext : public antlr4::ParserRuleContext {
  public:
    Table_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Indexed_columnContext *> indexed_column();
    Indexed_columnContext* indexed_column(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    Conflict_clauseContext *conflict_clause();
    antlr4::tree::TerminalNode *K_CHECK();
    ExprContext *expr();
    antlr4::tree::TerminalNode *K_FOREIGN();
    antlr4::tree::TerminalNode *K_KEY();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    Foreign_key_clauseContext *foreign_key_clause();
    antlr4::tree::TerminalNode *K_CONSTRAINT();
    NameContext *name();
    antlr4::tree::TerminalNode *K_PRIMARY();
    antlr4::tree::TerminalNode *K_UNIQUE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Table_constraintContext* table_constraint();

  class  With_clauseContext : public antlr4::ParserRuleContext {
  public:
    With_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_WITH();
    std::vector<Common_table_expressionContext *> common_table_expression();
    Common_table_expressionContext* common_table_expression(size_t i);
    antlr4::tree::TerminalNode *K_RECURSIVE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  With_clauseContext* with_clause();

  class  Qualified_table_nameContext : public antlr4::ParserRuleContext {
  public:
    Qualified_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    Database_nameContext *database_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *K_INDEXED();
    antlr4::tree::TerminalNode *K_BY();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *K_NOT();

   
  };

  Qualified_table_nameContext* qualified_table_name();

  class  Ordering_termContext : public antlr4::ParserRuleContext {
  public:
    Ordering_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *K_COLLATE();
    Collation_nameContext *collation_name();
    antlr4::tree::TerminalNode *K_ASC();
    antlr4::tree::TerminalNode *K_DESC();

   
  };

  Ordering_termContext* ordering_term();

  class  Pragma_valueContext : public antlr4::ParserRuleContext {
  public:
    Pragma_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signed_numberContext *signed_number();
    NameContext *name();
    antlr4::tree::TerminalNode *STRING_LITERAL();

   
  };

  Pragma_valueContext* pragma_value();

  class  Common_table_expressionContext : public antlr4::ParserRuleContext {
  public:
    Common_table_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *K_AS();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    Select_stmtContext *select_stmt();
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Common_table_expressionContext* common_table_expression();

  class  Result_columnContext : public antlr4::ParserRuleContext {
  public:
    Result_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *DOT();
    ExprContext *expr();
    Column_aliasContext *column_alias();
    antlr4::tree::TerminalNode *K_AS();

   
  };

  Result_columnContext* result_column();

  class  Table_or_subqueryContext : public antlr4::ParserRuleContext {
  public:
    Table_or_subqueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    Table_aliasContext *table_alias();
    antlr4::tree::TerminalNode *K_INDEXED();
    antlr4::tree::TerminalNode *K_BY();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_AS();
    Table_function_nameContext *table_function_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    Select_stmtContext *select_stmt();

   
  };

  Table_or_subqueryContext* table_or_subquery();

  class  Join_clauseContext : public antlr4::ParserRuleContext {
  public:
    Join_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    std::vector<Join_operatorContext *> join_operator();
    Join_operatorContext* join_operator(size_t i);
    std::vector<Join_constraintContext *> join_constraint();
    Join_constraintContext* join_constraint(size_t i);

   
  };

  Join_clauseContext* join_clause();

  class  Join_operatorContext : public antlr4::ParserRuleContext {
  public:
    Join_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *K_JOIN();
    antlr4::tree::TerminalNode *K_NATURAL();
    antlr4::tree::TerminalNode *K_LEFT();
    antlr4::tree::TerminalNode *K_INNER();
    antlr4::tree::TerminalNode *K_CROSS();
    antlr4::tree::TerminalNode *K_OUTER();

   
  };

  Join_operatorContext* join_operator();

  class  Join_constraintContext : public antlr4::ParserRuleContext {
  public:
    Join_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ON();
    ExprContext *expr();
    antlr4::tree::TerminalNode *K_USING();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Join_constraintContext* join_constraint();

  class  Select_coreContext : public antlr4::ParserRuleContext {
  public:
    Select_coreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_SELECT();
    std::vector<Result_columnContext *> result_column();
    Result_columnContext* result_column(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *K_FROM();
    antlr4::tree::TerminalNode *K_WHERE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *K_GROUP();
    antlr4::tree::TerminalNode *K_BY();
    antlr4::tree::TerminalNode *K_DISTINCT();
    antlr4::tree::TerminalNode *K_ALL();
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    antlr4::tree::TerminalNode *K_HAVING();
    antlr4::tree::TerminalNode *K_VALUES();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);

   
  };

  Select_coreContext* select_core();

  class  Compound_operatorContext : public antlr4::ParserRuleContext {
  public:
    Compound_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_UNION();
    antlr4::tree::TerminalNode *K_ALL();
    antlr4::tree::TerminalNode *K_INTERSECT();
    antlr4::tree::TerminalNode *K_EXCEPT();

   
  };

  Compound_operatorContext* compound_operator();

  class  Signed_numberContext : public antlr4::ParserRuleContext {
  public:
    Signed_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  Signed_numberContext* signed_number();

  class  Literal_valueContext : public antlr4::ParserRuleContext {
  public:
    Literal_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *BLOB_LITERAL();
    antlr4::tree::TerminalNode *K_NULL();
    antlr4::tree::TerminalNode *K_CURRENT_TIME();
    antlr4::tree::TerminalNode *K_CURRENT_DATE();
    antlr4::tree::TerminalNode *K_CURRENT_TIMESTAMP();

   
  };

  Literal_valueContext* literal_value();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *K_NOT();

   
  };

  Unary_operatorContext* unary_operator();

  class  Error_messageContext : public antlr4::ParserRuleContext {
  public:
    Error_messageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();

   
  };

  Error_messageContext* error_message();

  class  Module_argumentContext : public antlr4::ParserRuleContext {
  public:
    Module_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Column_defContext *column_def();

   
  };

  Module_argumentContext* module_argument();

  class  Column_aliasContext : public antlr4::ParserRuleContext {
  public:
    Column_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *STRING_LITERAL();

   
  };

  Column_aliasContext* column_alias();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  NameContext* name();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Function_nameContext* function_name();

  class  Database_nameContext : public antlr4::ParserRuleContext {
  public:
    Database_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Database_nameContext* database_name();

  class  Schema_nameContext : public antlr4::ParserRuleContext {
  public:
    Schema_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Schema_nameContext* schema_name();

  class  Table_function_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Table_function_nameContext* table_function_name();

  class  Table_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Table_nameContext* table_name();

  class  Table_or_index_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_or_index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Table_or_index_nameContext* table_or_index_name();

  class  New_table_nameContext : public antlr4::ParserRuleContext {
  public:
    New_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  New_table_nameContext* new_table_name();

  class  Column_nameContext : public antlr4::ParserRuleContext {
  public:
    Column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Column_nameContext* column_name();

  class  Collation_nameContext : public antlr4::ParserRuleContext {
  public:
    Collation_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Collation_nameContext* collation_name();

  class  Foreign_tableContext : public antlr4::ParserRuleContext {
  public:
    Foreign_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Foreign_tableContext* foreign_table();

  class  Index_nameContext : public antlr4::ParserRuleContext {
  public:
    Index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Index_nameContext* index_name();

  class  Pragma_nameContext : public antlr4::ParserRuleContext {
  public:
    Pragma_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Pragma_nameContext* pragma_name();

  class  Savepoint_nameContext : public antlr4::ParserRuleContext {
  public:
    Savepoint_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Savepoint_nameContext* savepoint_name();

  class  Transaction_nameContext : public antlr4::ParserRuleContext {
  public:
    Transaction_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

   
  };

  Transaction_nameContext* transaction_name();

  class  Table_aliasContext : public antlr4::ParserRuleContext {
  public:
    Table_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *OPEN_PAR();
    Table_aliasContext *table_alias();
    antlr4::tree::TerminalNode *CLOSE_PAR();

   
  };

  Table_aliasContext* table_alias();

  class  Any_nameContext : public antlr4::ParserRuleContext {
  public:
    Any_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    KeywordContext *keyword();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *OPEN_PAR();
    Any_nameContext *any_name();
    antlr4::tree::TerminalNode *CLOSE_PAR();

   
  };

  Any_nameContext* any_name();

  class  KeywordContext : public antlr4::ParserRuleContext {
  public:
    KeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ALTER();
    antlr4::tree::TerminalNode *K_AND();
    antlr4::tree::TerminalNode *K_BEGIN();
    antlr4::tree::TerminalNode *K_CASE();

   
  };

  KeywordContext* keyword();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace potatodb
