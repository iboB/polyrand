# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
CPMAddPackage(gh:iboB/doctest-util@0.1.2)
CPMAddPackage(gh:ThrowTheSwitch/Unity@2.6.0)
set_target_properties(doctest PROPERTIES FOLDER test)
set_target_properties(doctest-main PROPERTIES FOLDER test)
set_target_properties(unity PROPERTIES FOLDER test)

macro(polyrand_c_test test)
    icm_add_test(
        NAME polyrand-c-${test}
        TARGET test-polyrand-c-${test}
        LIBRARIES
            unity::framework
            polyrand::polyrand
        SOURCES
            ${ARGN}
        FOLDER test
    )
endmacro()

macro(polyrand_cpp_test test)
    add_doctest_lib_test(${test} polyrand ${ARGN})
endmacro()

#polyrand_c_test(ctest t-ctest.c)
#polyrand_cpp_test(cxxtest t-cxxtest.cpp)
