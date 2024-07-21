// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <iostream>
#include <polyrand/device.hpp>
#include <polyrand/trng.hpp>
#include <random>
#include <memory>

int main() {
    //std::cout << polyrand::get_device_random_number() << '\n';
    std::unique_ptr<polyrand::rng> r = std::make_unique<polyrand::trng<std::mt19937>>(43);

    std::uniform_int_distribution<int32_t> id(0, 20);
    for (int i=0; i<10; ++i) {
        std::cout << r->rand_with_d(id) << ' ';
    }
    std::cout << '\n';

    std::uniform_real_distribution<double> rd(-1, 1);
    for (int i=0; i<10; ++i) {
        std::cout << r->rand_with_d(rd) << ' ';
    }
    std::cout << '\n';

    return 0;
}
