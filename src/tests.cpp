/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "str/tests.hpp"


namespace tbaricault::str
{

    bool containsOnly(std::string_view str, std::string_view set) noexcept
    {
        return (str.find_first_not_of(set) == std::string_view::npos);
    }

}
