#pragma once

#include <utility>
#include "common/config.hpp"
#include "page/page.hpp"
#include "index/generic_key.hpp"
#include "index/generic_comp.hpp"
#include "index/int_comp.hpp"

/**
 * Store indexed key and and value together within block page. Supports
 * non-unique keys.
 *
 * Block page format (keys are stored in order):
 *  ----------------------------------------------------------------
 * | KEY(1) + VALUE(1) | KEY(2) + VALUE(2) | ... | KEY(n) + VALUE(n)
 *  ----------------------------------------------------------------
 *
 *  Here '+' means concatenation.
 *
 */

template<class KeyT, class ValueT>
class HTBlockPage {
public:
  /**********************************************
   * Useful types
   **********************************************/
  using CompT    = Comp<KeyT>;
  using MappingT = std::pair<KeyT, ValueT>;

  static const int BLOCK_ARRAY_SIZE =
    (4 * PAGE_SIZE / (4 * sizeof(MappingT) + 1));

  /**********************************************
   * Constructor & destructor
   **********************************************/

  // NOTE: We never actually use the constructor because
  // it is always implemented via `reinterpret_cast`.
  // What that means is, in practice we are overlaying
  // the memory layout of the instance variables onto
  // chunk of memory that is attached to a Page object.
  //
  // Suffice to say, this is hideous to me, from a memory
  // safety perspective. But, because I do not know how
  // else to do it, we'll use Pavlo's approach for now
  // and in the future we can find a better way to store
  // this.
  HTBlockPage() = delete;

  /**********************************************
   * Instance methods
   **********************************************/

  KeyT key_at(slot_offset_t bucket_ind) const;
  ValueT value_at(slot_offset_t bucket_ind) const;
  bool insert(slot_offset_t bucket_ind,
              CRef<KeyT> key,
              CRef<ValueT> value);

  void remove(slot_offset_t bucket_ind);
  bool is_occupied(slot_offset_t bucket_ind) const;
  bool is_readable(slot_offset_t bucket_ind) const;

 private:
  std::atomic_char occupied_[(BLOCK_ARRAY_SIZE - 1) / 8 + 1];

  // 0 if tombstone/brand new (never occupied), 1 otherwise.
  std::atomic_char readable_[(BLOCK_ARRAY_SIZE - 1) / 8 + 1];
  // MappingT array_[0];
};
