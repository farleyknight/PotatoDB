# -----------------------------------------------------------------------------
# Compiler settings
# -----------------------------------------------------------------------------

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# NOTE: Turning this off to make builds faster
# set(CMAKE_CXX_CPPCHECK "cppcheck")

# NOTE: Turning this off to make builds faster
set(BUILD_SHARED_LIBS OFF)
# set(BUILD_SHARED_LIBS ON)

# NOTE: Turning this off to make builds faster
# set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*)

# All target binaries are placed under the directory `builds/`
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builds)

# -----------------------------------------------------------------------------
# Compiler Error Limit (+ more settings)
# -----------------------------------------------------------------------------

add_definitions(
  #######################################################
  # NOTE: If you want to see the entire list of errors,
  # change the next line from =N to =0
  #######################################################
  "-ferror-limit=50"
  "-Wall"
  "-Wextra"

  "-Wno-unknown-pragmas" # This one comes up rarely, and it's annoying to see.
  # "-Wno-sign-compare"    # This one I don't care about for now, but probably should *not* ignore it in the future.

  "-pedantic"
  "-g"
  "-fexceptions"
  )

# -----------------------------------------------------------------------------
# Source files added to the include path
# -----------------------------------------------------------------------------

include_directories(src)
include_directories(tests)
include_directories(perf)
include_directories(parser)

set(test_sources
  "tests/main.cpp")

set(perf_sources
  "perf/main.cpp")

set(server_sources
  "server/main.cpp")

set(parser_sources
  "src/parser/eval_parse_visitor.cpp"
  "parser/PotatoSQLLexer.cpp"
  "parser/PotatoSQLParser.cpp")

set(main_sources
  "src/btree/b_plus_tree.cpp"
  "src/buffer/buff_mgr.cpp"
  "src/buffer/buffer.cpp"
  "src/buffer/clock_replacer.cpp"
  "src/buffer/lru_replacer.cpp"
  "src/buffer/replacer.cpp"
  "src/buffer/table_mgr.cpp"
  "src/catalog/base_schema.cpp"
  "src/catalog/catalog.cpp"
  "src/catalog/query_builder.cpp"
  "src/catalog/query_schema.cpp"
  "src/catalog/table_schema.cpp"
  "src/common/hash_util.cpp"
  "src/disk/disk_mgr.cpp"
  "src/disk/file_mgr.cpp"
  "src/disk/file_handle.cpp"
  "src/execs/agg_exec.cpp"
  "src/execs/exec_ctx.cpp"
  "src/execs/exec_factory.cpp"
  "src/execs/hash_join_exec.cpp"
  "src/execs/seq_scan_exec.cpp"
  "src/execs/update_exec.cpp"
  "src/hash/linear_probe_hash_table.cpp"
  "src/index/index_iterator.cpp"
  "src/index/linear_probe_hash_table_index.cpp"
  "src/page/hash_table_block_page.cpp"
  "src/page/hash_table_header_page.cpp"
  "src/page/page.cpp"
  "src/page/table_heap.cpp"
  "src/page/table_iterator.cpp"
  "src/page/slotted_table_page.cpp"
  "src/plans/agg_plan.cpp"
  "src/plans/plan_builder.cpp" # TODO: Delete this
  "src/plans/plan_factory.cpp"
  "src/query/query_agg.cpp"
  "src/query/query_group_by.cpp"
  "src/query/query_having.cpp"
  "src/query/query_comp.cpp"
  "src/query/query_column.cpp"
  "src/query/query_join.cpp"
  "src/recovery/checkpoint_mgr.cpp"
  "src/recovery/log_mgr.cpp"
  "src/recovery/log_recovery.cpp"
  "src/server/client_socket.cpp"
  "src/server/potatodb.cpp"
  "src/server/session.cpp"
  "src/server/socket_server.cpp"
  "src/server/system_catalog.cpp"
  "src/tuple/tuple.cpp"
  "src/txns/lock_mgr.cpp"
  "src/txns/txn.cpp"
  "src/txns/txn_mgr.cpp"
  "src/types/type.cpp"
  "src/value/value.cpp"
  "src/value/value_factory.cpp"
  )
