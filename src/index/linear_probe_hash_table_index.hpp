#pragma once

#include "catalog/index_meta.hpp"
#include "index/base_index.hpp"
#include "index/index_meta.hpp"
#include "hash/linear_probe_hash_table.hpp"

class LinearProbeHTIndex : public BaseIndex {
public:
  LinearProbeHTIndex(CRef<IndexMeta> metadata,
                     BuffMgr& buff_mgr,
                     size_t num_buckets,
                     CRef<HashFunc<GenericKey>> hash_fn);

  ~LinearProbeHTIndex() override = default;

  void insert_entry(CRef<Tuple> key, CRef<RID> rid) override;
  void delete_entry(CRef<Tuple> key) override;
  virtual Vec<RID> scan_key(CRef<Tuple> key) override;

protected:
  CRef<IndexMeta> meta_;
  GenericComp comp_;
  LinearProbeHT<GenericKey, RID> container_;
};
