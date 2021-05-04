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
                           const string &msg,
                           UNUSED std::exception_ptr e)
    override
  {
    string message(msg);
    string full_message = "Line(" + std::to_string(line) + ":" +
      std::to_string(charPositionInLine) + ") Error(" + message + ")";

    throw std::invalid_argument(full_message);
  }
};

class SQLParser {
public:
  static string as_tree(string input) {
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

  static Vec<string> as_expr_strings(string input) {
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
        vector<string> result {"No parse result!"};
        return result;
      }
    } catch (std::invalid_argument &e) {
      string error_message(e.what());
      vector<string> result {error_message};
      return result;
    }
  }

  static vector<MutPtr<BaseExpr>> as_exprs(string input) {
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
        vector<MutPtr<BaseExpr>> results;
        return results;
      }

    } catch (UNUSED std::invalid_argument &e) {
      vector<MutPtr<BaseExpr>> results;
      return results;
    }
  }
};
