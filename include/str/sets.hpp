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
     * @brief Characters representing decimal digits
     */
    inline constexpr std::string_view digits = "0123456789";

    /**
     * @brief Characters representing hexadecimal digits
     */
    inline constexpr std::string_view hex = "0123456789abcdef";

    /**
     * @brief Characters considered as blank characters
     */
    inline constexpr std::string_view blanks = " \n\t";

    /**
     * @brief Characters considered as whitespace
     */
    inline constexpr std::string_view whitespaces = " \f\n\r\t\v";

}
