// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "polyrand.h"

extern "C" {

POLYRAND_API int add(int bias, int a, int b) {
    return bias + a + b;
}

}
