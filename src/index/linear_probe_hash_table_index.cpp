
#include "index/linear_probe_hash_table_index.hpp"

LinearProbeHTIndex::LinearProbeHTIndex(Ref<IndexMeta> meta,
                                       MutRef<BuffMgr> buff_mgr,
                                       size_t num_buckets,
                                       Ref<HashFunc<GenericKey>> hash_fn)
  : meta_      (meta),
    comp_      (meta.key_schema()),
    container_ (meta.index_name(), buff_mgr, comp_, num_buckets, hash_fn) {}

void LinearProbeHTIndex::insert_entry(Ref<Tuple> key, Ref<RID> rid) {
  // construct insert index key
  GenericKey index_key;
  index_key.set_from_key(key);

  container_.insert(index_key, rid);
}

void LinearProbeHTIndex::delete_entry(Ref<Tuple> key, Ref<RID> rid) {
  // construct delete index key
  GenericKey index_key;
  index_key.set_from_key(key);

  container_.remove(index_key, rid);
}

Vec<RID> LinearProbeHTIndex::scan_key(Ref<Tuple> key) const {
  // construct scan index key
  GenericKey index_key;
  index_key.set_from_key(key);

  return container_.find_values(index_key);
}
