#pragma once

#include "page/page.hpp"

class PageLayout {
public:
  PageLayout(Page* page)
    : page_ (page)
  {
    assert(page != nullptr);
  }

  void update_ptr(Page* page) {
    assert(page != nullptr);
    page_ = page;
  }

  Page* page_ptr() {
    return page_;
  }

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
