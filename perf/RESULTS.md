## Strategies for read/writing data to buffers

### BM_BufferRW

Based on initial tests for `int32_t` the C++ built-in casting `reinterpret_cast` seems to be about 5x-10x faster than byte-by-byte hand written encodings.

This is not surprising, given the low-level nature of `reinterpret_cast`. Further study is necessary for non-integer types, like strings, floats, doubles, and nulls.

## Parsing SQL via different parsers

### ANTLR4 parser

TODO: Report findings here.

https://tomassetti.me/getting-started-antlr-cpp/

### Boost Spirit parser

TODO: Report findings here.

https://www.boost.org/doc/libs/1_75_0/libs/spirit/doc/html/spirit/qi/tutorials/warming_up.html

