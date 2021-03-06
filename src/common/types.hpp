#pragma once

#include <deque>

#include <future>

#include <memory>
#include <mutex>

#include <limits>
#include <list>

#include <string>

#include <map>
#include <unordered_map>
#include <unordered_set>

#include <vector>

/************************************************
 * Macros
 ************************************************/

#define UNUSED __attribute__ ((unused))

/************************************************
 * Types we will be using w/o the `std::` prefix
 ************************************************/

using std::int32_t;
using std::uint32_t;

using timestamp_t = std::uint64_t;

using std::fstream;

using std::deque;

using std::make_optional;
using std::make_pair;
using std::make_shared;
using std::make_tuple;
using std::make_unique;
using std::max;
using std::move;
using std::pair;
using std::chrono::milliseconds;

using std::nullopt;
using std::nullptr_t;
using std::numeric_limits;

using std::pair;

using std::shared_ptr;
using std::string;
using std::stringstream;

using std::tuple;

using std::unique_ptr;
using std::unique_lock;

template<typename K, typename V>
using map         = std::unordered_map<K, V>;

template<typename K, typename V>
using ordered_map = std::map<K, V>;

namespace fs = std::filesystem;

// ptr is shorter than unique_ptr
template<class T>
using ptr      = unique_ptr<T>;

// sptr is shorter than shared_ptr
template<class T>
using sptr     = shared_ptr<T>;


// NOTE: File descriptors are integers and are pointers to
// file objects elsewhere in the system.
//
// No need to know more details than that. They are used
// mostly in the server code.
using file_desc_t   = int;
using byte_t        = std::uint8_t;

using std::mutex;
using std::thread;
using std::weak_ptr;
using std::function;
using std::vector;
using std::list;
using std::future;
using std::condition_variable;
using std::atomic;
using std::optional;
using std::unordered_set;
using std::deque;

/************************************************
 * References and Pointers
 ************************************************/

template<typename T>
using Move      = T&&;

template<class K, class V>
using Map       = const std::unordered_map<K, V>;

template<class K, class V>
using MutMap    = std::unordered_map<K, V>;


// NOTE: SPtr means shared_ptr
template<class T>
using SPtr      = const std::shared_ptr<T>;
template<class T>
using MutSPtr   = std::shared_ptr<T>;

using std::list;
using std::future;
using task = future<void>;

using cond_var = condition_variable;

template<class T>
using ref_wrap  = std::reference_wrapper<T>;
template<class T>
using opt_ref = std::optional<std::reference_wrapper<T>>;

template<class T>
using option = optional<T>;

template<class T>
using set = unordered_set<T>;

using std::deque;
