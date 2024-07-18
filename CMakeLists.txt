# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(polyrand
    LANGUAGES C CXX
)

# cpm
include(./get_cpm.cmake)

#######################################
# cmake lib
CPMAddPackage(gh:iboB/icm@1.5.1)

list(APPEND CMAKE_MODULE_PATH
    "${icm_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

set(ICM_DEV_C_STANDARD 11)
set(ICM_DEV_CXX_STANDARD 20)

include(icm_dev_mode)

#######################################
# options

option(BUILD_SHARED_LIBS "${CMAKE_PROJECT_NAME}: build shared libraries" ON)
option(POLYRAND_BUILD_TESTS "${CMAKE_PROJECT_NAME}: enable testing and build tests" ${ICM_DEV_MODE})
option(POLYRAND_BUILD_EXAMPLES "${CMAKE_PROJECT_NAME}: build examples" ${ICM_DEV_MODE})
option(POLYRAND_BUILD_SCRATCH "${CMAKE_PROJECT_NAME}: build scratch project (dev experiments)" ${ICM_DEV_MODE})
mark_as_advanced(POLYRAND_BUILD_SCRATCH)

#######################################
# code
add_subdirectory(code)

if(POLYRAND_BUILD_SCRATCH)
    add_subdirectory(scratch)
endif()

if(POLYRAND_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

if(POLYRAND_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()
