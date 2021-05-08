/**********************************************
 * Type defs
 **********************************************/

#include <cstdint>
#include <cstddef>
#include <string>

// Log recovery ID
using lsn_t         = std::int32_t;

// HashTable ID
using hash_t        = std::size_t;

// The page IDs, frame IDs, and txn IDs are signed 32-bit integers.
using frame_id_t    = std::int32_t;
// IDS for accessing page blocks
using page_id_t     = std::uint32_t;
// The above can be decomposed into these two:
using file_id_t     = std::uint16_t;
using block_id_t    = std::uint16_t;
// Offset is used for byte-level offsets in buffers
using offset_t      = std::uint32_t;

// This is stored separately in a RID
using slot_id_t     = std::uint16_t;
using txn_id_t      = std::int32_t;

// Catalog IDs
using table_oid_t   = std::int32_t;
using column_oid_t  = std::int32_t;
using index_oid_t   = std::int32_t;
using slot_offset_t = std::size_t;
using schema_oid_t  = std::int32_t;

// Names for things
using column_name_t = std::string;
using table_name_t  = std::string;
using index_name_t  = std::string;

// Index type is mostly meant for for-loops
using index_t       = std::uint32_t;
