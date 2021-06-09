#pragma once

#include "common/ids.hpp"
#include "common/constants.hpp"
#include "common/types.hpp"
#include "common/type_limits.hpp"

/**********************************************
 * System configuration as constant values
 **********************************************/

// TODO: Some of these can be configured
// during system start-up

static constexpr table_oid_t   INVALID_TABLE_OID = -1;
static constexpr column_oid_t  INVALID_COLUMN_OID = -1;

static constexpr txn_id_t     INVALID_TXN_ID    = -1;
static constexpr lsn_t        INVALID_LSN       = -1;

// Pages are 4KB in size, which should be standard for most DBMSs
static constexpr page_id_t    HEADER_PAGE_ID = 0;
static constexpr int          PAGE_SIZE = 4096;
static constexpr int          BUFFER_POOL_SIZE = 10;
static constexpr int          LOG_BUFFER_SIZE = ((BUFFER_POOL_SIZE + 1) * PAGE_SIZE);
static constexpr int          LEAF_PAGE_HEADER_SIZE = 28;

static constexpr int          MAX_VARCHAR_SIZE = 128;

static constexpr std::chrono::duration<int64_t> LOG_TIMEOUT = std::chrono::seconds(1);
