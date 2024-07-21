// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "rng.hpp"
#include <type_traits>
#include <random>

namespace polyrand {

template <typename G>
class trng :
    public G,
    public std::conditional<sizeof(typename G::result_type) == 4, rng32, rng64>::type {
public:
    using typename G::result_type;
    using G::G;

    virtual result_type rand() override { return G::operator()(); }

    virtual void seed(uint64_t s) override { G::seed(result_type(s)); }
};

} // namespace polyrand
