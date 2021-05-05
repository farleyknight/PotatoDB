#pragma once

#include "index/index_meta.hpp"
#include "index/base_index.hpp"
#include "hash/linear_probe_hash_table.hpp"

class LinearProbeHTIndex : public BaseIndex {
public:
  using GenericHashFunc = HashFunc<GenericKey>;

  LinearProbeHTIndex(const IndexMeta& metadata,
                     BuffMgr& buff_mgr,
                     size_t num_buckets,
                     const GenericHashFunc& hash_fn);

  ~LinearProbeHTIndex() override = default;

  void insert_entry(const Tuple& key,
                    const RID& rid) override;

  void delete_entry(const Tuple& key) override;
  virtual vector<RID> scan_key(const Tuple& key) override;

protected:
  const IndexMeta& meta_;
  GenericComp comp_;
  LinearProbeHT<GenericKey, RID> container_;
};
