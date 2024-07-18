// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include "device.hpp"
#include <random>

namespace polyrand {

uint32_t get_device_random_number() {
    static thread_local std::random_device rd;
    return rd();
}

} // namespace polyrand
