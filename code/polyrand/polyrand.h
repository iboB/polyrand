// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

// Return a random number from the device's random number generator
POLYRAND_API uint32_t polyrand_get_device_random_number();

#if defined(__cplusplus)
}
#endif
