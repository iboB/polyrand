// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include "polyrand.h"
#include "device.hpp"

extern "C" {

uint32_t polyrand_get_device_random_number() {
    return polyrand::get_device_random_number();
}

}
