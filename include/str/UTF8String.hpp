/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <limits>
#include <string>
#include <string_view>

#include <utf8cpp/utf8.h>


namespace tbaricault::str
{

    /**
     * @brief UTF-8 encoded Unicode string
     */
    class UTF8String final
    {

        public:

            /**
             * @brief Mutable iterator over Unicode code points
             */
            using iterator = utf8::iterator<std::string::iterator>;

            /**
             * @brief Constant iterator over Unicode code points
             */
            using const_iterator = utf8::iterator<std::string::const_iterator>;


            /**
             * @brief Constructs an empty UTF-8 string
             */
            UTF8String() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other String to copy
             */
            UTF8String(const UTF8String& other) = default;

            /**
             * @brief Moves constructor
             *
             * @param other String to move
             */
            UTF8String(UTF8String&& other) noexcept = default;

            /**
             * @brief Constructs a UTF-8 string from a null-terminated UTF-8 string
             * 
             * @param s UTF-8 encoded C string
             */
            UTF8String(const char* s);

            /**
             * @brief Constructs a UTF-8 string from a UTF-8 encoded std::string
             * 
             * @param str UTF-8 encoded string
             */
            UTF8String(std::string_view str);

            /**
             * @brief Constructs a UTF-8 string containing a single Unicode code point
             * 
             * @param c Unicode code point
             */
            UTF8String(char32_t c);

            /**
             * @brief Destructor
             */
            ~UTF8String() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other String to copy
             * 
             * @return Reference to this string
             */
            UTF8String& operator=(const UTF8String& other) = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other String to move
             * 
             * @return Reference to this string
             */
            UTF8String& operator=(UTF8String&& other) noexcept = default;

            /**
             * @brief Appends another UTF-8 string
             * 
             * @param other String to append
             * 
             * @return Reference to this string
             */
            UTF8String& operator+=(const UTF8String& other);

            /**
             * @brief Appends a Unicode code point
             *  
             * @param c Unicode code point to append
             * 
             * @return Reference to this string
             */
            UTF8String& operator+=(char32_t c);

            /**
             * @brief Concatenates two UTF8 strings
             * 
             * @param a First string
             * @param b Second string
             * 
             * @return Concatenated string
             */
            friend UTF8String operator+(UTF8String a, const UTF8String& b);

            /**
             * @brief Tests whether two strings are equal
             * 
             * @param other String to compare with
             * 
             * @return `true` if both strings contain the same UTF-8 sequence, `false` otherwise
             */
            bool operator==(const UTF8String& other) const noexcept;

            /**
             * @brief Tests whether two strings are different
             * 
             * @param other String to compare with
             * 
             * @return `true` if the strings differ, `false` otherwise
             */
            bool operator!=(const UTF8String& other) const noexcept;

            /**
             * @brief Performs a lexicographical comparison
             * 
             * @param other String to compare with
             * 
             * @return `true` if the string is lexicographically less than the other, `false` otherwise
             */
            bool operator<(const UTF8String& other) const noexcept;

            /**
             * @brief Converts the UTF-8 string to raw string
             */
            operator std::string() const;

            /**
             * @brief Converts the UTF-8 string to UTF-32 string
             */
            operator std::u32string() const;

            /**
             * @brief Writes the UTF-8 string to an output stream
             *
             * @param os Output stream
             * @param obj String to write
             * 
             * @return The output stream
             */
            friend std::ostream& operator<<(std::ostream& os, const UTF8String& obj);

            /**
             * @brief Returns an iterator to the first Unicode code point
             * 
             * @return Mutable iterator
             */
            iterator begin() noexcept;

            /**
             * @brief Returns an iterator past the last Unicode code point
             * 
             * @return Mutable iterator
             */
            iterator end() noexcept;

            /**
             * @brief Returns a constant iterator to the first Unicode code point
             * 
             * @return Constant iterator
             */
            const_iterator begin() const noexcept;

            /**
             * @brief Returns a constant iterator past the last Unicode code point
             * 
             * @return Constant iterator
             */
            const_iterator end() const noexcept;

            /**
             * @brief Returns a constant iterator to the first Unicode code point
             * 
             * @return Constant iterator
             */
            const_iterator cbegin() const noexcept;

            /**
             * @brief Returns a constant iterator past the last Unicode code point
             * 
             * @return Constant iterator
             */
            const_iterator cend() const noexcept;

            /**
             * @brief Returns the underlying UTF-8 encoded string
             * 
             * @return Reference to the internal std::string
             */
            const std::string& str() const noexcept;

            /**
             * @brief Checks whether the string is empty
             * 
             * @return `true` if the string contains no characters, `false` otherwise
             */
            bool empty() const noexcept;

            /**
             * @brief Returns the number of Unicode code points
             * 
             * @return Character count
             */
            std::size_t length() const noexcept;

            /**
             * @brief Returns the Unicode code point at the specified index
             * 
             * @param i Character index
             * 
             * @return Unicode code point
             */
            char32_t at(std::size_t i) const noexcept;

            /**
             * @brief Removes all characters from the string
             */
            void clear() noexcept;

            /**
             * @brief Extracts a substring
             * 
             * @param i Starting character index
             * @param length Number of characters to extract
             * 
             * @return Extracted substring
             */
            UTF8String substr(std::size_t i, std::size_t length = std::numeric_limits<std::size_t>::max()) const;


        private:

            /**
             * @brief Raw string
             */
            std::string _data;

            /**
             * @brief Cached length
             */
            mutable size_t _length = std::numeric_limits<std::size_t>::max();

    };

}
