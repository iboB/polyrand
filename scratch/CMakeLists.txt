# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
add_executable(polyrand-scratch
    scratch.cpp
)
target_link_libraries(polyrand-scratch polyrand::polyrand)
set_target_properties(polyrand-scratch PROPERTIES FOLDER scratch)
