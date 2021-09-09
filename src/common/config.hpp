#pragma once

#include "common/ids.hpp"
#include "common/constants.hpp"
#include "common/types.hpp"
#include "common/type_limits.hpp"

/**********************************************
 * Logger across all of PotatoDB
 **********************************************/

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

extern sptr<spdlog::logger> logger;

/**********************************************
 * System configuration as constant values
 **********************************************/

// TODO: Some of these can be configured
// during system start-up

// TODO: Move some of these to their respective classes
static constexpr table_oid_t   INVALID_TABLE_OID  = -1;
static constexpr column_oid_t  INVALID_COLUMN_OID = -1;
static constexpr index_oid_t   INVALID_INDEX_OID  = -1;
static constexpr txn_id_t      INVALID_TXN_ID     = -1;
static constexpr lsn_t         INVALID_LSN        = -1;

static constexpr table_oid_t   FIRST_TABLE_OID  = 1;
static constexpr column_oid_t  FIRST_COLUMN_OID = 1;
static constexpr index_oid_t   FIRST_INDEX_OID  = 1;
static constexpr txn_id_t      FIRST_TXN_ID     = 1;
static constexpr lsn_t         FIRST_LSN        = 1;

// Pages are 4KB in size, which should be standard for most DBMSs
static constexpr page_id_t    HEADER_PAGE_ID = 0;
static constexpr int32_t      PAGE_SIZE             = 4096;
static constexpr int32_t      BUFFER_POOL_SIZE      = 10;
static constexpr int32_t      LOG_BUFFER_SIZE       = ((BUFFER_POOL_SIZE + 1) * PAGE_SIZE);
static constexpr int32_t      LEAF_PAGE_HEADER_SIZE = 28;

static constexpr int          MAX_VARCHAR_SIZE = 128;
