/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>

#include "sets.hpp"


namespace tbaricault::str
{

    /**
     * @brief Removes leading characters belonging to a given set
     * 
     * @param str String to trim
     * @param set Characters to remove
     * 
     * @return Trimmed copy of the string
     */
    std::string leftTrim(std::string_view str, std::string_view set = whitespaces);

    /**
     * @brief Removes trailing characters belonging to a given set
     * 
     * @param str String to trim
     * @param set Characters to remove
     * 
     * @return Trimmed copy of the string
     */
    std::string rightTrim(std::string_view str, std::string_view set = whitespaces);

    /**
     * @brief Removes leading and trailing characters belonging to a given set
     * 
     * @param str String to trim
     * @param set Characters to remove
     * 
     * @return Trimmed copy of the string
     */
    std::string trim(std::string_view str, std::string_view set = whitespaces);

}
