
#include "storage/hash_table_block_page.hpp"

template<class KeyT, class ValueT>
KeyT HTBlockPage<KeyT, ValueT>::key_at(slot_offset_t bucket_ind) const {
  return {};
}

template<class KeyT, class ValueT>
ValueT HTBlockPage<KeyT, ValueT>::value_at(slot_offset_t bucket_ind) const {
  return {};
}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::insert(slot_offset_t bucket_ind,
                                       Ref<KeyT> key,
                                       Ref<ValueT> value)
{
  return false;
}

template<class KeyT, class ValueT>
void HTBlockPage<KeyT, ValueT>::remove(slot_offset_t bucket_ind) {

}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::is_occupied(slot_offset_t bucket_ind) const {
  return false;
}

template<class KeyT, class ValueT>
bool HTBlockPage<KeyT, ValueT>::is_readable(slot_offset_t bucket_ind) const {
  return false;
}
