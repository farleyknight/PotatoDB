#include <iostream>
#include <strstream>
#include <string>

#include "parser/sql_parser.hpp"

int main(UNUSED int argc,
         const char* argv[])
{
  string input = string(argv[1]);

  // std::cout << SQLParser::as_tree(input);

  // std::cout << "Exprs as strings" << std::endl;
  auto results = SQLParser::as_expr_strings(input);

  //for (auto result : results) {
  //  std::cout << result << std::endl;
  // }

  // std::cout << "Nested Exprs" << std::endl;
  auto exprs = SQLParser::as_exprs(input);

  //for (auto &expr : exprs) {
  //  std::cout << expr->to_string() << std::endl;
  // }

  return 0;
}
