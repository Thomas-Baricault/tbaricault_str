/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>


namespace tbaricault::str
{

    /**
     * @brief Converts a snake_case identifier to camelCase
     * 
     * @param str Identifier in snake_case
     * 
     * @return Converted identifier
     */
    std::string snakeToCamel(std::string_view str);

    /**
     * @brief Converts a snake_case identifier to PascalCase
     * 
     * @param str Identifier in snake_case
     * 
     * @return Converted identifier
     */
    std::string snakeToPascal(std::string_view str);

    /**
     * @brief Converts a camelCase identifier to snake_case
     * 
     * @param str Identifier in camelCase
     * 
     * @return Converted identifier
     */
    std::string camelToSnake(std::string_view str);

    /**
     * @brief Converts a camelCase identifier to PascalCase
     * 
     * @param str Identifier in camelCase
     * 
     * @return Converted identifier
     */
    std::string camelToPascal(std::string_view str);

    /**
     * @brief Converts a PascalCase identifier to snake_case
     * 
     * @param str Identifier in PascalCase
     * 
     * @return Converted identifier
     */
    std::string pascalToSnake(std::string_view str);

    /**
     * @brief Converts a PascalCase identifier to camelCase
     * 
     * @param str Identifier in PascalCase
     * 
     * @return Converted identifier
     */
    std::string pascalToCamel(std::string_view str);

}
