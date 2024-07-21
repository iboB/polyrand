// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include "rng_interface.hpp"
#include "rng.hpp"
#include <dynamix/msg/define_msg.hpp>

namespace polyrand {
DYNAMIX_DEFINE_SIMPLE_MSG(rand32_msg, unicast);
DYNAMIX_DEFINE_SIMPLE_MSG(rand64_msg, unicast);
} // namespace polyrand
