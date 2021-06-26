# -----------------------------------------------------------------------------
# Common files object library
# -----------------------------------------------------------------------------

add_library(potatodb-main OBJECT
  ${main_sources}
  )

set_target_properties(potatodb-main
  PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON)

add_library(potatodb-parser OBJECT
  ${parser_sources}
  )

set_target_properties(potatodb-parser
  PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON)
