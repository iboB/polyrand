// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "rng.hpp"
#include "domain.hpp"
#include "rng_interface.hpp"
#include <dynamix/mixin_info_data.hpp>
#include <dynamix/globals.hpp>
#include <dynamix/domain.hpp>
#include <dynamix/msg/msg_traits.hpp>
#include <random>

namespace polyrand {

template <typename G>
class rng_mixin {
public:
    G rng;

    static dynamix::util::mixin_info_data info_data;
};

template <typename G>
dynamix::util::mixin_info_data rng_mixin<G>::info_data;

template <typename G>
const dynamix::type& create_rng(std::string_view name) {
    using rngm = rng_mixin<G>;
    auto& info_data = rngm::info_data;

    auto& dom = dynamix::g::get_domain<domain>();

    dynamix::util::mixin_info_data_builder<rngm> builder(info_data, name);

    if constexpr (std::is_same_v<typename G::result_type, uint32_t>) {
        builder.implements_by<rand32_msg>([](rngm* r) { return r->rng(); });
    }
    else if constexpr (std::is_same_v<typename G::result_type, uint64_t>) {
        builder.implements_by<rand64_msg>([](rngm* r) { return r->rng(); });
    }

    info_data.register_in(dom);

    const dynamix::mixin_info* q[] = {&info_data.info};
    return dom.get_type(q);
}

} // namespace polyrand
