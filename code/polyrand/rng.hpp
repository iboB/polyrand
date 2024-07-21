// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <dynamix/object.hpp>
#include <dynamix/object_of.hpp>
#include <cstdint>

namespace polyrand {

class rng : public dynamix::object {
public:
    using dynamix::object::object;

    static rng* of(void* mixin) {
        return static_cast<rng*>(dynamix::object_of(mixin));
    }
    static const rng* of(const void* mixin) {
        return static_cast<const rng*>(dynamix::object_of(mixin));
    }
};

#define polyrand_rng_self ::polyrand::rng::of(this)

} // namespace polyrand
