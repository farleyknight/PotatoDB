
#include "index/linear_probe_hash_table_index.hpp"

LinearProbeHTIndex::LinearProbeHTIndex(const IndexMeta& meta,
                                       BuffMgr& buff_mgr,
                                       size_t num_buckets,
                                       const GenericHashFunc& hash_fn)
  : meta_      (meta),
    comp_      (meta.key_schema()),
    container_ (meta.index_name(),
                buff_mgr, comp_, num_buckets, hash_fn)
{}

void LinearProbeHTIndex::insert_entry(const Tuple& key,
                                      const RID& rid) {
  // construct insert index key
  GenericKey index_key;
  index_key.set_from_key(key);

  container_.insert(index_key, rid);
}

void LinearProbeHTIndex::delete_entry(const Tuple& key) {
  // construct delete index key
  GenericKey index_key;
  index_key.set_from_key(key);

  container_.remove(index_key);
}

vector<RID> LinearProbeHTIndex::scan_key(const Tuple& key) {
  // construct scan index key
  GenericKey index_key;
  index_key.set_from_key(key);

  return container_.find_values(index_key);
}
