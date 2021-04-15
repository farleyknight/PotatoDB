#include <string>

/************************************************
 * Type defs
 ************************************************/

using int32_t       = std::int32_t;
using uint32_t      = std::uint32_t;

using String        = const std::string;
using MutString     = std::string;

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

