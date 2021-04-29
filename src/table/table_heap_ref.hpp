#pragma once

#include "common/config.hpp"

class TableHeapRef {
public:
  TableHeapRef(file_id_t file_id)
    : file_id_ (file_id)
  {}

private:
  UNUSED file_id_t file_id_;
};
