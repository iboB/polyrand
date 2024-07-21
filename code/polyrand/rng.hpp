// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <cstdint>

namespace polyrand {

class POLYRAND_API rng {
public:
    virtual ~rng();

    virtual uint32_t i32() = 0;
    virtual uint64_t i64() = 0;

    virtual void seed(uint64_t s) = 0;
};

class POLYRAND_API rng_i32 : public rng {
public:
    // call i32 two times
    virtual uint64_t i64() final override;

    // seed slice to 32 bits
    virtual void seed(uint64_t s) final override;

    virtual void seed(uint32_t s) = 0;

    uint64_t operator()() { return i64(); }
};

class POLYRAND_API rng_i64 : public rng {
public:
    // slice i64
    virtual uint32_t i32() final override;

    uint32_t operator()() { return i32(); }
};

} // namespace polyrand
