// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <iostream>
#include <polyrand/device.hpp>
#include <polyrand/create_rng.hpp>
#include <random>

int main() {
    auto t = polyrand::create_rng<std::minstd_rand>("minstd_rand");
    polyrand::rng r(t.type);

    std::cout << rand32(r) << std::endl;
}
