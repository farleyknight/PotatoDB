#pragma once

/**********************************************
* Regularly used constant values
**********************************************/

// static constexpr page_id_t    INVALID_PAGE_ID   = -1;
static constexpr table_oid_t  INVALID_TABLE_OID = -1;

static constexpr txn_id_t     INVALID_TXN_ID    = -1;
static constexpr lsn_t        INVALID_LSN       = -1;

// Pages are 4KB in size, which should be standard for most DBMSs
static constexpr page_id_t    HEADER_PAGE_ID = 0;
static constexpr int          PAGE_SIZE = 4096;
static constexpr int          BUFFER_POOL_SIZE = 10;
static constexpr int          LOG_BUFFER_SIZE = ((BUFFER_POOL_SIZE + 1) * PAGE_SIZE);  // size of a log buffer in bytes
static constexpr int          LEAF_PAGE_HEADER_SIZE = 28;

static constexpr int          MAX_VARCHAR_SIZE = 128;

// Sets the 33rd bit of a 64 bit integer
// As a bit string: 0000000000000000000000000000000010000000000000000000000000000000
static constexpr uint64_t     DELETE_MASK = (1U << (8 * sizeof(uint32_t) - 1));
