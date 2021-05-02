
#include "page/hash_table_block_page.hpp"

template<class KeyT, class ValueT>
KeyT HTBlockPage<KeyT, ValueT>::key_at(UNUSED slot_offset_t bucket_ind) const {
  return {};
}

template<class KeyT, class ValueT>
ValueT HTBlockPage<KeyT, ValueT>::value_at(UNUSED slot_offset_t bucket_ind) const {
  return {};
}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::insert(UNUSED slot_offset_t bucket_ind,
                                       UNUSED CRef<KeyT> key,
                                       UNUSED CRef<ValueT> value)
{
  return false;
}

template<class KeyT, class ValueT>
void HTBlockPage<KeyT, ValueT>::remove(UNUSED slot_offset_t bucket_ind) {

}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::is_occupied(UNUSED slot_offset_t bucket_ind) const {
  return false;
}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::is_readable(UNUSED slot_offset_t bucket_ind) const {
  return false;
}
