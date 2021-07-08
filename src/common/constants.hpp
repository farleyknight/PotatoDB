#pragma once

/**********************************************
* Regularly used constant values
**********************************************/

// Sets the 33rd bit of a 64 bit integer
// As a bit string: 0000000000000000000000000000000010000000000000000000000000000000
static constexpr uint64_t     DELETE_MASK = (1U << (8 * sizeof(uint32_t) - 1));
