#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <limits>
#include <mutex>
#include <vector>
#include <future>

/************************************************
 * Macros
 ************************************************/

#define UNUSED __attribute__ ((unused)) 

/************************************************
 * Type defs
 ************************************************/

using std::int32_t;
using std::uint32_t;

using std::make_shared;
using std::make_unique;
using std::max;
using std::move;

using std::nullptr_t;
using std::numeric_limits;

using std::string;


// NOTE: File descriptors are integers and are pointers to
// file objects elsewhere in the system.
//
// No need to know more details than that. They are used
// mostly in the server code.
using file_desc_t = int;

// NOTE: I prefer camel-cased names for types
using String        = const string;
using MutString     = string;

using std::mutex;
using Mutex         = mutex;

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

// NOTE: Ptr automatically means unique_ptr
template<class T>
using Ptr       = const std::unique_ptr<T>;
template<class T>
using MutPtr    = std::unique_ptr<T>;
template<class T>
using MovePtr   = std::unique_ptr<T> &&;


// NOTE: SPtr means shared_ptr
template<class T>
using SPtr      = const std::shared_ptr<T>;
template<class T>
using MutSPtr   = std::shared_ptr<T>;

// NOTE: WPtr means weak_ptr
template<class T>
using WPtr     = std::weak_ptr<T>;


using std::vector;
template<typename T>
using Vec      = const vector<T>;
template<typename T>
using MutVec   = vector<T>;


using std::future;
template<typename T>
using Future = future<T>;
using Task = Future<void>;
