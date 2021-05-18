
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace potatosql {


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
    K_EXCLUSIVE = 70, K_EXISTS = 71, K_EXPLAIN = 72, K_FAIL = 73, K_FOR = 74, 
    K_FOREIGN = 75, K_FROM = 76, K_FULL = 77, K_GLOB = 78, K_GROUP = 79, 
    K_HAVING = 80, K_IF = 81, K_IGNORE = 82, K_IMMEDIATE = 83, K_IN = 84, 
    K_INDEX = 85, K_INDEXED = 86, K_INITIALLY = 87, K_INNER = 88, K_INSERT = 89, 
    K_INSTEAD = 90, K_INTERSECT = 91, K_INTO = 92, K_IS = 93, K_ISNULL = 94, 
    K_JOIN = 95, K_KEY = 96, K_LEFT = 97, K_LIKE = 98, K_LIMIT = 99, K_MATCH = 100, 
    K_NATURAL = 101, K_NO = 102, K_NOT = 103, K_NOTNULL = 104, K_NULL = 105, 
    K_OF = 106, K_OFFSET = 107, K_ON = 108, K_OR = 109, K_ORDER = 110, K_OUTER = 111, 
    K_PLAN = 112, K_PRAGMA = 113, K_PRIMARY = 114, K_QUERY = 115, K_RAISE = 116, 
    K_RECURSIVE = 117, K_REFERENCES = 118, K_REGEXP = 119, K_REINDEX = 120, 
    K_RELEASE = 121, K_RENAME = 122, K_REPLACE = 123, K_RESTRICT = 124, 
    K_RIGHT = 125, K_ROLLBACK = 126, K_ROW = 127, K_SAVEPOINT = 128, K_SELECT = 129, 
    K_SET = 130, K_SHOW = 131, K_TABLE = 132, K_TABLES = 133, K_TEMP = 134, 
    K_TEMPORARY = 135, K_THEN = 136, K_TO = 137, K_TRANSACTION = 138, K_TRIGGER = 139, 
    K_UNION = 140, K_UNIQUE = 141, K_UPDATE = 142, K_USING = 143, K_VACUUM = 144, 
    K_VALUES = 145, K_VIEW = 146, K_VIRTUAL = 147, K_WHEN = 148, K_WHERE = 149, 
    K_WITH = 150, K_WITHOUT = 151, IDENTIFIER = 152, NUMERIC_LITERAL = 153, 
    BIND_PARAMETER = 154, STRING_LITERAL = 155, BLOB_LITERAL = 156, SINGLE_LINE_COMMENT = 157, 
    MULTILINE_COMMENT = 158, SPACES = 159, UNEXPECTED_CHAR = 160
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

}  // namespace potatosql
