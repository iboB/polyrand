# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
add_executable(polyrand-cpp-example cpp-example.cpp)
target_link_libraries(polyrand-cpp-example polyrand::polyrand)
set_target_properties(polyrand-cpp-example PROPERTIES FOLDER example)

add_executable(polyrand-c-example c-example.c)
target_link_libraries(polyrand-c-example polyrand::polyrand)
set_target_properties(polyrand-c-example PROPERTIES FOLDER example)
