
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  PotatoSQLLexer : public antlr4::Lexer {
public:
  enum {
    SCOL = 1, DOT = 2, OPEN_PAR = 3, CLOSE_PAR = 4, COMMA = 5, ASSIGN = 6, 
    STAR = 7, PLUS = 8, MINUS = 9, TILDE = 10, PIPE2 = 11, DIV = 12, MOD = 13, 
    LT2 = 14, GT2 = 15, AMP = 16, PIPE = 17, LT = 18, LT_EQ = 19, GT = 20, 
    GT_EQ = 21, EQ = 22, NOT_EQ1 = 23, NOT_EQ2 = 24, K_ABORT = 25, K_ACTION = 26, 
    K_ADD = 27, K_AFTER = 28, K_ALL = 29, K_ALTER = 30, K_ANALYZE = 31, 
    K_AND = 32, K_AS = 33, K_ASC = 34, K_ATTACH = 35, K_AUTOINCREMENT = 36, 
    K_BEFORE = 37, K_BEGIN = 38, K_BETWEEN = 39, K_BY = 40, K_CASCADE = 41, 
    K_CASE = 42, K_CAST = 43, K_CHECK = 44, K_COLLATE = 45, K_COLUMN = 46, 
    K_COMMIT = 47, K_CONFLICT = 48, K_CONSTRAINT = 49, K_CREATE = 50, K_CROSS = 51, 
    K_CURRENT_DATE = 52, K_CURRENT_TIME = 53, K_CURRENT_TIMESTAMP = 54, 
    K_DATABASE = 55, K_DEFAULT = 56, K_DEFERRABLE = 57, K_DEFERRED = 58, 
    K_DELETE = 59, K_DESC = 60, K_DESCRIBE = 61, K_DETACH = 62, K_DISTINCT = 63, 
    K_DROP = 64, K_EACH = 65, K_ELSE = 66, K_END = 67, K_ESCAPE = 68, K_EXCEPT = 69, 
    K_EXCLUSIVE = 70, K_EXISTS = 71, K_EXPLAIN = 72, K_FAIL = 73, K_FALSE = 74, 
    K_FOR = 75, K_FOREIGN = 76, K_FROM = 77, K_FULL = 78, K_GLOB = 79, K_GROUP = 80, 
    K_HAVING = 81, K_IF = 82, K_IGNORE = 83, K_IMMEDIATE = 84, K_IN = 85, 
    K_INDEX = 86, K_INDEXED = 87, K_INITIALLY = 88, K_INNER = 89, K_INSERT = 90, 
    K_INSTEAD = 91, K_INTERSECT = 92, K_INTO = 93, K_IS = 94, K_ISNULL = 95, 
    K_JOIN = 96, K_KEY = 97, K_LEFT = 98, K_LIKE = 99, K_LIMIT = 100, K_MATCH = 101, 
    K_NATURAL = 102, K_NO = 103, K_NOT = 104, K_NOTNULL = 105, K_NULL = 106, 
    K_OF = 107, K_OFFSET = 108, K_ON = 109, K_OR = 110, K_ORDER = 111, K_OUTER = 112, 
    K_PLAN = 113, K_PRAGMA = 114, K_PRIMARY = 115, K_QUERY = 116, K_RAISE = 117, 
    K_RECURSIVE = 118, K_REFERENCES = 119, K_REGEXP = 120, K_REINDEX = 121, 
    K_RELEASE = 122, K_RENAME = 123, K_REPLACE = 124, K_RESTRICT = 125, 
    K_RIGHT = 126, K_ROLLBACK = 127, K_ROW = 128, K_SAVEPOINT = 129, K_SELECT = 130, 
    K_SET = 131, K_SHOW = 132, K_TABLE = 133, K_TABLES = 134, K_TEMP = 135, 
    K_TEMPORARY = 136, K_THEN = 137, K_TO = 138, K_TRANSACTION = 139, K_TRIGGER = 140, 
    K_TRUE = 141, K_UNION = 142, K_UNIQUE = 143, K_UPDATE = 144, K_USING = 145, 
    K_VACUUM = 146, K_VALUES = 147, K_VIEW = 148, K_VIRTUAL = 149, K_WHEN = 150, 
    K_WHERE = 151, K_WITH = 152, K_WITHOUT = 153, IDENTIFIER = 154, NUMERIC_LITERAL = 155, 
    BIND_PARAMETER = 156, STRING_LITERAL = 157, BLOB_LITERAL = 158, SINGLE_LINE_COMMENT = 159, 
    MULTILINE_COMMENT = 160, SPACES = 161, UNEXPECTED_CHAR = 162
  };

  explicit PotatoSQLLexer(antlr4::CharStream *input);
  ~PotatoSQLLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

