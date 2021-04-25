#include <iostream>
#include <strstream>
#include <string>

#include "common/types.hpp"

#include "antlr4-runtime.h"
#include "PotatoSQLLexer.h"
#include "PotatoSQLParser.h"
#include "PotatoSQLListener.h"

#include "parser/eval_parse_visitor.hpp"

using namespace potatosql;
using namespace antlr4;

class ErrorListener : public BaseErrorListener {
  virtual void syntaxError(UNUSED antlr4::Recognizer *recognizer,
                           UNUSED antlr4::Token *offendingSymbol,
                           size_t line,
                           size_t charPositionInLine,
                           const std::string &msg,
                           UNUSED std::exception_ptr e)
    override
  {
    std::string message(msg);
    std::string full_message = "Line(" + std::to_string(line) + ":" +
      std::to_string(charPositionInLine) + ") Error(" + message + ")";

    throw std::invalid_argument(full_message);
  }
};

class SQLParser {
public:
  static MutString as_tree(MutString input) {
    ANTLRInputStream stream(input);

    PotatoSQLLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);

    ErrorListener errorListener;

    PotatoSQLParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    try {
      tree::ParseTree* tree = parser.main();
      return tree->toStringTree();
    } catch (UNUSED std::invalid_argument &e) {
      return e.what();
    }
  }

  static Vec<MutString> as_expr_strings(MutString input) {
    ANTLRInputStream stream(input);

    PotatoSQLLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);

    ErrorListener errorListener;

    PotatoSQLParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    try {
      tree::ParseTree* tree = parser.main();
      EvalParseVisitor visitor;
      visitor.visit(tree);

      if (visitor.results.size() > 0) {
        return visitor.results;
      } else {
        MutVec<MutString> result {"No parse result!"};
        return result;
      }
    } catch (std::invalid_argument &e) {
      MutString error_message(e.what());
      MutVec<MutString> result {error_message};
      return result;
    }
  }

  static MutVec<MutPtr<BaseExpr>> as_exprs(MutString input) {
    ANTLRInputStream stream(input);

    PotatoSQLLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);

    ErrorListener errorListener;

    PotatoSQLParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    try {
      tree::ParseTree* tree = parser.main();
      EvalParseVisitor visitor;
      visitor.visit(tree);

      if (visitor.exprs.size() > 0) {
        return move(visitor.exprs);
      } else {
        MutVec<MutPtr<BaseExpr>> results;
        return results;
      }

    } catch (UNUSED std::invalid_argument &e) {
      MutVec<MutPtr<BaseExpr>> results;
      return results;
    }
  }
};