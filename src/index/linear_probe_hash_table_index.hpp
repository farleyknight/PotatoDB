#pragma once

#include "catalog/index_meta.hpp"
#include "index/base_index.hpp"
#include "hash/linear_probe_hash_table.hpp"

class LinearProbeHTIndex : public BaseIndex {
public:
  LinearProbeHTIndex(Ref<IndexMeta> metadata,
                     MutRef<BuffMgr> buff_mgr,
                     size_t num_buckets,
                     Ref<HashFunc<GenericKey>> hash_fn);

  ~LinearProbeHTIndex() override = default;

  void insert_entry(Ref<Tuple> key, Ref<RID> rid) override;
  void delete_entry(Ref<Tuple> key, Ref<RID> rid) override;
  Vec<RID> scan_key(Ref<Tuple> key) const override;

protected:
  Ref<IndexMeta> meta_;
  GenericComp comp_;
  LinearProbeHT<GenericKey, RID> container_;
};
