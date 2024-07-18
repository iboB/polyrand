// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <iostream>
#include <polyrand/device.hpp>

int main() {
    std::cout << polyrand::get_device_random_number() << '\n';
}
