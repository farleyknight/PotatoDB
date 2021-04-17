#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <limits>

/************************************************
 * Type defs
 ************************************************/

using std::int32_t;
using std::uint32_t;
using std::string;

using std::make_unique;
using std::move;

using std::nullptr_t;
using std::numeric_limits;

using String        = const string;
using MutString     = string;

/************************************************
 * References and Pointers
 ************************************************/

// By default, all references should be const.
// This prevents us from accidentially modifying references.
template<class T>
using Ref       = T const&;

// To make a non-const reference, we borrow the `mut` keyword
// from Rust, giving us `MutRef`.
template<class T>
using MutRef    = T&;

template<typename T>
using Move      = T&&;

template<class K, class V>
using Map       = const std::unordered_map<K, V>;

template<class K, class V>
using MutMap    = std::unordered_map<K, V>;

template<class T>
using Ptr       = const std::unique_ptr<T>;

template<class T>
using MutPtr    = std::unique_ptr<T>;

template<class T>
using MovePtr   = std::unique_ptr<T> &&;
