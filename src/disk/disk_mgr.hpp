#pragma once

#include <fstream>
#include <future>
#include <iostream>
#include <memory>

#include "common/config.hpp"
#include "page/page.hpp"

class DiskMgr {
public:
  /*********************************************************
   * DiskMgr - A disk manager for a single-file DB.
   * - TODO: Create a FileMgr class to give access
   *         to Blocks which are physical offsets
   *         but using using multiples of page size.
   *********************************************************/
  DiskMgr(string db_name);

  // No copy
  DiskMgr(CRef<DiskMgr>) = delete;
  // No copy assign
  MRef<DiskMgr> operator=(CRef<DiskMgr>) = delete;

  void write_buffer(PageId page_id, CRef<Buffer> buffer);
  void read_buffer(PageId page_id, Buffer& buffer);

  void write_page(PageId page_id, CRef<Page> page);
  void read_page(PageId page_id, Page& page);

  PageId allocate_page() {
    /*
     * Allocate new page (operations like create index/table)
     * For now just keep an increasing counter
     */
    // https://github.com/esengie/orbit/blob/5211612d4bf6cdc157bb17dda2c51734e70ef884/src/DiskSpaceManager/DiskSpaceManager.java#L44

    // TODO! Implement in "CREATE TABLE" or "CREATE INDEX" context.
    auto val = next_page_id_++;
    return PageId::from(val);
  }

  void deallocate_page(UNUSED PageId page_id) {
    /*
     * Deallocate page (operations like drop index/table)
     * Need bitmap in header page for tracking pages
     * This does not actually need to do anything for now.
     */
    // TODO! Implement in "DROP TABLE" or "DROP INDEX" context.
  }

  void write_log(CRef<Buffer> log_data, size_t size);
  bool read_log(Buffer& log_data, size_t size, size_t offset);

  // Close all file handles.
  void shutdown() {
    db_file_.close();
  }

private:
  std::atomic<page_id_t> next_page_id_{0};
  std::fstream db_file_;
  std::fstream log_io_;

  string db_name_, log_name_;

  // stream to write db file
  int num_flushes_;
  UNUSED int num_writes_;
  bool flush_log_;
  std::future<void> *flush_log_f_{nullptr};
};
