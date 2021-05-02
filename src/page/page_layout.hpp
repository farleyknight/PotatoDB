#pragma once

#include "page/page.hpp"

class PageLayout {
public:
  PageLayout(Page& page)
    : page_ (page)
  {}

  // TODO: Finish recovery module
  lsn_t lsn();
  void set_lsn(lsn_t lsn);
  void reset_memory();

protected:
  Page& page_;
};
