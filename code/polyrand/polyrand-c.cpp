// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "polyrand.h"
#include "device.hpp"

extern "C" {

uint32_t polyrand_get_device_random_number() {
    return polyrand::get_device_random_number();
}

}
