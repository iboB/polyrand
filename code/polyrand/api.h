// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include <splat/symbol_export.h>

#if POLYRAND_SHARED
#   if BUILDING_POLYRAND
#       define POLYRAND_API SYMBOL_EXPORT
#   else
#       define POLYRAND_API SYMBOL_IMPORT
#   endif
#else
#   define POLYRAND_API
#endif
