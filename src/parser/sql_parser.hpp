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
    auto message = string(msg);
    auto full_message = "Line(" + std::to_string(line) + ":" +
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

  static vector<string> as_expr_strings(string input) {
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
      // TODO: We should pass in a reference to the `Catalog`
      // like this:
      // visitor.set_catalog(catalog)
      visitor.visit(tree);

      if (visitor.results().size() > 0) {
        return move(visitor.results());
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

  static vector<ptr<BaseExpr>> as_exprs(string input) {
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
      // TODO: We should pass in a reference to the `Catalog`
      // like this:
      //
      // > visitor.set_catalog(catalog)
      //
      // And then we can check the system catalog as we
      // traverse the syntax tree.
      visitor.visit(tree);

      if (visitor.exprs().size() > 0) {
        return move(visitor.exprs());
      } else {
        vector<ptr<BaseExpr>> results;
        return results;
      }

    } catch (UNUSED std::invalid_argument &e) {
      vector<ptr<BaseExpr>> results;
      return results;
    }
  }
};
