#pragma once

#include "catalog/index_meta.hpp"
#include "index/base_index.hpp"
#include "index/index_meta.hpp"
#include "hash/linear_probe_hash_table.hpp"

class LinearProbeHTIndex : public BaseIndex {
public:
  LinearProbeHTIndex(const IndexMeta& metadata,
                     BuffMgr& buff_mgr,
                     size_t num_buckets,
                     const IndexMeta& hash_fn);

  ~LinearProbeHTIndex() override = default;

  void insert_entry(const IndexMeta& key,
                    const IndexMeta& rid) override;
  void delete_entry(const IndexMeta& key) override;
  virtual Vec<RID> scan_key(const IndexMeta& key) override;

protected:
  const IndexMeta& meta_;
  GenericComp comp_;
  LinearProbeHT<GenericKey, RID> container_;
};
