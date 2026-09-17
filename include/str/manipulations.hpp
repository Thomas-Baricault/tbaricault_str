/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <span>
#include <string>
#include <string_view>
#include <vector>


namespace tbaricault::str
{

    /**
     * @brief Splits a string using a delimiter
     * 
     * @param str String to split
     * @param delimiter Delimiter used to split the string
     * @param allowEmpty Whether empty substrings should be preserved
     * 
     * @return Vector containing the resulting substrings
     */
    std::vector<std::string> split(std::string_view str, std::string_view delimiter = " ", bool allowEmpty = true);


    /**
     * @brief Joins a sequence of strings using a separator
     * 
     * @param strs Strings to join
     * @param separator Separator inserted between consecutive strings
     * 
     * @return Resulting string
     */
    std::string join(std::span<std::string_view> strs, std::string_view separator = "");

    /**
     * @brief Repeats a string n times
     * 
     * @param str String to reapeat
     * @param n Number of time to repeat
     * 
     * @return Resulting string
     */
    std::string repeat(std::string_view str, std::size_t n);

    /**
     * @brief Indents a string
     * 
     * @param str String to indent
     * @param indent Indent size
     * @param useTabs Whether indentation should use tabs instead of spaces
     * 
     * @return Resulting string
     */
    std::string indent(std::string_view str, std::size_t indent = 1, bool useTabs = false);

}
