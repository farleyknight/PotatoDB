#pragma once

#include "page/page.hpp"

class PageLayout {
public:

  // TODO: Finish recovery module
  lsn_t lsn(CRef<Page> page);
  void set_lsn(MRef<Page> page, lsn_t lsn);
  void reset_memory(MRef<Page> page);

  PageId read_page_id(CRef<Page> page, size_t offset);
  void write_page_id(MRef<Page> page, size_t offset, PageId page_id);

private:

};
