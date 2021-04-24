#include <iostream>
#include <strstream>
#include <string>

#include "antlr4-runtime.h"
#include "PotatoSQLLexer.h"
#include "PotatoSQLParser.h"

using namespace potatosql;
using namespace antlr4;

class ErrorListener: public BaseErrorListener {
  virtual void syntaxError(antlr4::Recognizer *recognizer,
                           antlr4::Token *offendingSymbol,
                           size_t line,
                           size_t charPositionInLine,
                           const std::string &msg,
                           std::exception_ptr e) override {
    std::ostrstream stream;
    std::string message(msg);

    stream << "Line(" << line << ":" << charPositionInLine <<
      ") Error(" << message << ")";
    //std::string response(stream.str());

    throw std::invalid_argument(message);
  }
};

class PotatoSQL {
public:
  static MutString parse(MutString input) {
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
    } catch (std::invalid_argument &e) {
      return e.what();
    }
  }
};
