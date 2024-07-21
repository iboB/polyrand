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

    virtual uint32_t rand32() = 0;
    virtual uint64_t rand64() = 0;

    virtual void seed(uint64_t s) = 0;
};

class POLYRAND_API rng32 : public rng {
public:
    virtual uint32_t rand() = 0;

    virtual uint32_t rand32() final override { return rand(); }

    // call i32 two times
    virtual uint64_t rand64() final override;
};

class POLYRAND_API rng64 : public rng {
public:
    virtual uint64_t rand() = 0;

    // slice i64
    virtual uint32_t rand32() final override;

    virtual uint64_t rand64() final override { return rand(); }
};

} // namespace polyrand
