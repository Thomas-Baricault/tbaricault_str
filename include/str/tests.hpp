/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string_view>


namespace tbaricault::str
{

    /**
     * @brief Checks whether a string contains only characters from a given set
     * 
     * @param str String to test
     * @param set Set of allowed characters
     * 
     * @return `true` if every character in @p str belongs to @p set, `false` otherwise
     */
    bool containsOnly(std::string_view str, std::string_view set) noexcept;

}
