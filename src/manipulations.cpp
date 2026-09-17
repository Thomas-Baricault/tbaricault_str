/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "str/manipulations.hpp"


namespace tbaricault::str
{

    std::vector<std::string> split(std::string_view str, std::string_view delimiter, bool allowEmpty)
    {
        std::vector<std::string> result;
        std::size_t i = 0;
        std::size_t j = 0;
        while ((j = str.find(delimiter, i)) != std::string::npos)
        {
            if (allowEmpty || j > i)
                result.emplace_back(str.substr(i, j - i));
            i = j + delimiter.length();
        }
        if (i < str.length())
            result.emplace_back(str.substr(i));
        return (result);
    }

    std::string join(std::span<std::string_view> strs, std::string_view separator)
    {
        std::string result;
        for (std::size_t i = 0; i < strs.size(); i++)
        {
            if (i > 0)
                result += separator;
            result += strs[i];
        }
        return (result);
    }

    std::string repeat(std::string_view str, std::size_t n)
    {
        std::string result;
        for (std::size_t i = 0; i < n; i++)
            result += str;
        return (result);
    }

    std::string indent(std::string_view str, std::size_t indent, bool useTabs)
    {
        std::string result;
        std::vector<std::string> lines = str::split(str, "\n");
        for (std::size_t i = 0; i < lines.size(); i++)
        {
            if (i > 0)
                result += '\n';
            result += std::string(indent, useTabs ? '\t' : ' ') + lines.at(i);
        }
        return (result);
    }

}
