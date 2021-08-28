#pragma once

#include "index/base_index.hpp"
#include "hash/linear_probe_hash_table.hpp"

class LinearProbeHTIndex : public BaseIndex {
public:
  using IndexHashFunc = HashFunc<IndexKey>;

  LinearProbeHTIndex(BuffMgr& buff_mgr,
                     IndexSchema schema,
                     size_t num_buckets,
                     const IndexHashFunc& hash_fn);

  ~LinearProbeHTIndex() override = default;

  void insert_entry(const Tuple& key,
                    const RID& rid) override;

  void delete_entry(const Tuple& key) override;
  virtual vector<RID> scan_key(const Tuple& key) override;

protected:
  IndexSchema schema_;
  IndexComp comp_;
  LinearProbeHT<IndexKey, RID> container_;
};
