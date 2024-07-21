// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "api.h"
#include <cstdint>
#include <random>

namespace polyrand {

#define I_POLYRAND_DISTRIBUTIONS(MACRO) \
    MACRO(std::uniform_int_distribution<int32_t>) \
    MACRO(std::uniform_real_distribution<double>) \
    MACRO(std::normal_distribution<double>) \
    MACRO(std::discrete_distribution<uint32_t>) \


class POLYRAND_API rng {
public:
    virtual ~rng();

    virtual uint32_t rand32() = 0;
    virtual uint64_t rand64() = 0;

    virtual void seed(uint64_t s) = 0;

#define I_D_METHOD_DECLARE_PV(distribution) \
        virtual distribution::result_type rand_with_d(distribution&) = 0;
    I_POLYRAND_DISTRIBUTIONS(I_D_METHOD_DECLARE_PV)
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
