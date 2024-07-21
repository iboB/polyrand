# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
include(icm_add_lib)

icm_add_lib(polyrand POLYRAND)
add_library(polyrand::polyrand ALIAS polyrand)
target_include_directories(polyrand INTERFACE .)

CPMAddPackage(gh:iboB/splat@1.3.2)
CPMAddPackage(gh:iboB/dynamix@2.0.2)

target_link_libraries(polyrand PUBLIC
    splat::splat
    dynamix::dynamix
)

target_sources(polyrand PRIVATE
    polyrand/api.h

    polyrand/device.hpp
    polyrand/device.cpp

    polyrand/domain.hpp
    polyrand/domain.cpp
    polyrand/rng.hpp
    polyrand/rng.cpp
    polyrand/rng_interface.hpp
    polyrand/rng_interface.cpp

    polyrand/polyrand.h
    polyrand/polyrand-c.cpp
)

