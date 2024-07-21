// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include "rng.hpp"

namespace polyrand {

rng::~rng() = default;

uint64_t rng32::rand64() {
    return 5;
}

uint32_t rng64::rand32() {
    return 15;
}

} // namespace polyrand
