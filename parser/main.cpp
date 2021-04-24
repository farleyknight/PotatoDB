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
    std::ostrstream s;
    s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
    throw std::invalid_argument(s.str());
  }
};

int main(int argc, const char* argv[]) {
  std::string input = std::string(argv[1]);
  ANTLRInputStream stream(input);

  PotatoSQLLexer lexer(&stream);
  CommonTokenStream tokens(&lexer);

  ErrorListener errorListener;

  PotatoSQLParser parser(&tokens);
  parser.addErrorListener(&errorListener);

  try {
    tree::ParseTree* tree = parser.main();
    std::cout << tree->toStringTree() << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    return 10;
  }
}
