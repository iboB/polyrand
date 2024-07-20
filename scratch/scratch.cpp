// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <iostream>
#include <polyrand/device.hpp>
#include <polyrand/rng.hpp>
#include <random>

class minstd final : public polyrand::rng_i32 {
    std::minstd_rand rng;
public:
    minstd(uint32_t seed) : rng(seed) {}
    void seed(uint32_t s) { rng.seed(s); }
    uint32_t i32() override { return rng(); }
};

int main() {
    std::cout << polyrand::get_device_random_number() << '\n';
    std::uniform_int_distribution<int> dist(0, 9);

    minstd m(42);
    std::cout << dist(m) << '\n';
}
