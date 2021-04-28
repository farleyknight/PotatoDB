#pragma once

#include <deque>

#include <future>

#include <memory>
#include <mutex>

#include <limits>
#include <list>

#include <string>

#include <unordered_map>
#include <unordered_set>

#include <vector>

/************************************************
 * Macros
 ************************************************/

#define UNUSED __attribute__ ((unused))

/************************************************
 * Type defs
 ************************************************/

using std::int32_t;
using std::uint32_t;

using std::make_optional;
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
using file_desc_t   = int;
using byte_t        = std::uint8_t;

// NOTE: I prefer camel-cased names for types
using String        = const string;
using MutString     = string;

using std::mutex;
using Mutex         = mutex;

using std::thread;
using Thread        = thread;


/************************************************
 * References and Pointers
 ************************************************/

// By default, all references should be const.
// This prevents us from accidentially modifying references.
template<class T>
using CRef      = T const&;

// To make a non-const reference, we borrow the `mut` keyword
// from Rust, giving us `MRef`.
template<class T>
using MRef      = T&;

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

using std::list;
template<class T>
using List      = const list<T>;
template<class T>
using MutList   = list<T>;


using std::future;
template<typename T>
using Future = future<T>;
using Task = Future<void>;

using std::condition_variable;
using CondVar = condition_variable;

using std::atomic;
template<class T>
using Atomic    = atomic<T>;

template<class T>
using RefWrap   = std::reference_wrapper<T>;
template<class T>
using OptRef    = std::optional<std::reference_wrapper<T>>;

using std::optional;
template<class T>
using Option    = const optional<T>;

template<class T>
using MutOption = optional<T>;

using std::unordered_set;
template<class T>
using Set       = const unordered_set<T>;
template<class T>
using MutSet    = unordered_set<T>;

using std::deque;
template<class T>
using Deque     = const deque<T>;
template<class T>
using MutDeque  = deque<T>;
