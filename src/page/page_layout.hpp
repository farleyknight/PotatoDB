#pragma once

#include "page/page.hpp"

class PageLayout {
public:
  PageLayout(Page* page)
    : page_ (page)
  {
    assert(page != nullptr);
  }

  void reset_memory();

  void rlatch() {
    page_->rlatch();
  }
  void runlatch() {
    page_->runlatch();
  }

  void wlatch() {
    page_->wlatch();
  }

  void wunlatch() {
    page_->wunlatch();
  }

  PageId page_id() {
    return page_->page_id();
  }

protected:
  Page* page_;
};
