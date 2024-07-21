// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "rng.hpp"
#include <type_traits>

namespace polyrand {

template <typename G>
class trng final :
    public G,
    public std::conditional<sizeof(typename G::result_type) == 4, rng32, rng64>::type {
public:
    using typename G::result_type;
    using G::G;

    virtual result_type rand() override { return G::operator()(); }

    virtual void seed(uint64_t s) override { G::seed(result_type(s)); }

    #define I_D_METHOD_DEFINE(distribution) \
        virtual distribution::result_type rand_with_d(distribution& d) override { return d(static_cast<G&>(*this)); }
    I_POLYRAND_DISTRIBUTIONS(I_D_METHOD_DEFINE)
};

} // namespace polyrand
