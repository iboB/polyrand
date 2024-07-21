// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <dynamix/msg/declare_msg.hpp>
#include <cstdint>

namespace polyrand {
class rng;
DYNAMIX_DECLARE_EXPORTED_SIMPLE_MSG(POLYRAND_API, rand32_msg, uint32_t(rng&));
DYNAMIX_DECLARE_EXPORTED_SIMPLE_MSG(POLYRAND_API, rand64_msg, uint64_t(rng&));

inline uint32_t rand32(rng& r) { return rand32_msg::call(r); }
inline uint64_t rand64(rng& r) { return rand64_msg::call(r); }

} // namespace polyrand

