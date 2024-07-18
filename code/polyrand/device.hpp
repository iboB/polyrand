// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <cstdint>

namespace polyrand {
// Return a random number from the device's random number generator
// Basically hide the instantiation of std::random_device
POLYRAND_API uint32_t get_device_random_number();
} // namespace polyrand
