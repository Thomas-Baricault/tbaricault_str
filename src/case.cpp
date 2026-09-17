/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "str/case.hpp"


namespace tbaricault::str
{

    std::string snakeToCamel(std::string_view str)
    {
        std::string result;
        bool upper = false;
        for (char c : str)
        {
            if (c == '_')
                upper = true;
            else if (upper)
            {
                result += toupper(c);
                upper = false;
            }
            else
                result += tolower(c);
        }
        return (result);
    }

    std::string snakeToPascal(std::string_view str)
    {
        std::string result;
        bool upper = true;
        for (char c : str)
        {
            if (c == '_')
                upper = true;
            else if (upper)
            {
                result += toupper(c);
                upper = false;
            }
            else
                result += tolower(c);
        }
        return (result);
    }

    std::string camelToSnake(std::string_view str)
    {
        std::string result;
        for (char c : str)
        {
            if (isupper(c))
                result += '_';
            result += tolower(c);
        }
        return (result);
    }

    std::string camelToPascal(std::string_view str)
    {
        if (str.empty())
            return ("");
        std::string result(str);
        result[0] = toupper(result[0]);
        return (result);
    }

    std::string pascalToSnake(std::string_view str)
    {
        std::string result;
        bool first = true;
        for (char c : str)
        {
            if (!first && isupper(c))
                result += '_';
            result += tolower(c);
            first = false;
        }
        return (result);
    }

    std::string pascalToCamel(std::string_view str)
    {
        if (str.empty())
            return ("");
        std::string result(str);
        result[0] = tolower(result[0]);
        return (result);
    }

}
