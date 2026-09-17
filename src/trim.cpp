/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "str/trim.hpp"


namespace tbaricault::str
{

    std::string leftTrim(std::string_view str, std::string_view set)
    {
        std::size_t i = str.find_first_not_of(set);
        if (i == std::string::npos)
            return ("");
        return std::string(str.substr(i));
    }

    std::string rightTrim(std::string_view str, std::string_view set)
    {
        std::size_t i = str.find_last_not_of(set);
        if (i == std::string::npos)
            return ("");
        return std::string(str.substr(0, i + 1));
    }

    std::string trim(std::string_view str, std::string_view set)
    {
        std::size_t i = str.find_first_not_of(set);
        if (i == std::string::npos)
            return ("");
        std::size_t j = str.find_last_not_of(set);
        return std::string(str.substr(i, j - i + 1));
    }

}
