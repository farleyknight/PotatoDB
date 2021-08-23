// Provide database file name.
// Open a connection to the file handle.

#include <algorithm>
#include "disk/disk_mgr.hpp"
#include "common/exceptions.hpp"

DiskMgr::DiskMgr(FileMgr& file_mgr)
  : file_mgr_    (file_mgr)
{
}


// TODO: All of these methods are just delegating to `file_mgr_`
// Let's just cut out the middle-man here.
// TODO: Slowly move away from using DiskMgr. Use FileMgr instead.
PageId DiskMgr::allocate_page(file_id_t file_id) {
  return file_mgr_.allocate_page(file_id);
}

