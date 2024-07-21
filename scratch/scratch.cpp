// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <iostream>
#include <polyrand/device.hpp>
#include <polyrand/trng.hpp>
#include <random>

using minstd = polyrand::trng<std::minstd_rand>;

int main() {
    //std::cout << polyrand::get_device_random_number() << '\n';
    std::uniform_int_distribution<int> dist(0, 9);

    minstd m(42);
    std::cout << dist(m) << '\n';
    std::cout << dist(m) << '\n';
}
