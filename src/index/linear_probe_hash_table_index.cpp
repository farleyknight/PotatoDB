
#include "index/linear_probe_hash_table_index.hpp"

void LinearProbeHTIndex::insert_entry(const Tuple& key,
                                      const RID& rid) {
  // construct insert index key
  IndexKey index_key;
  index_key.set_from_key(key);

  container_.insert(index_key, rid);
}

void LinearProbeHTIndex::delete_entry(const Tuple& key) {
  // construct delete index key
  IndexKey index_key;
  index_key.set_from_key(key);

  container_.remove(index_key);
}

vector<RID> LinearProbeHTIndex::scan_key(const Tuple& key) {
  // construct scan index key
  IndexKey index_key;
  index_key.set_from_key(key);

  return container_.find_values(index_key);
}
