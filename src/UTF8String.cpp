/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "str/UTF8String.hpp"


namespace tbaricault::str
{

    UTF8String::UTF8String(const char* s)
        : UTF8String(std::string(s))
    {
        return;
    }

    UTF8String::UTF8String(std::string_view str)
    {
        if (!utf8::is_valid(str.begin(), str.end()))
            throw std::invalid_argument("invalid UTF-8 string");
        this->_data = str;
        return;
    }

    UTF8String::UTF8String(char32_t c)
    {
        utf8::append(c, std::back_inserter(this->_data));
        this->_length = 1;
        return;
    }

    UTF8String& UTF8String::operator+=(const UTF8String& other)
    {
        this->_data += other._data;
        if (this->_length != std::numeric_limits<std::size_t>::max() && other._length != std::numeric_limits<std::size_t>::max())
            this->_length = this->_length + other._length;
        return (*this);
    }

    UTF8String& UTF8String::operator+=(char32_t c)
    {
        utf8::append(c, std::back_inserter(this->_data));
        if (this->_length != std::numeric_limits<std::size_t>::max())
            this->_length++;
        return (*this);
    }

    UTF8String operator+(UTF8String a, const UTF8String& b)
    {
        a += b;
        return (a);
    }

    bool UTF8String::operator==(const UTF8String& other) const noexcept
    {
        return (this->_data == other._data);
    }

    bool UTF8String::operator!=(const UTF8String& other) const noexcept
    {
        return (this->_data != other._data);
    }

    bool UTF8String::operator<(const UTF8String& other) const noexcept
    {
        return (this->_data < other._data);
    }

    UTF8String::operator std::string() const
    {
        return (this->_data);
    }

    UTF8String::operator std::u32string() const
    {
        std::u32string result;
        utf8::utf8to32(this->_data.begin(), this->_data.end(), std::back_inserter(result));
        return (result);
    }

    std::ostream& operator<<(std::ostream& out, const UTF8String& obj)
    {
        return (out << obj._data);
    }

    UTF8String::iterator UTF8String::begin() noexcept
    {
        return (iterator(this->_data.begin(), this->_data.begin(), this->_data.end()));
    }

    UTF8String::iterator UTF8String::end() noexcept
    {
        return (iterator(this->_data.end(), this->_data.begin(), this->_data.end()));
    }

    UTF8String::const_iterator UTF8String::begin() const noexcept
    {
        return (const_iterator(this->_data.begin(), this->_data.begin(), this->_data.end()));
    }

    UTF8String::const_iterator UTF8String::end() const noexcept
    {
        return (const_iterator(this->_data.end(), this->_data.begin(), this->_data.end()));
    }

    UTF8String::const_iterator UTF8String::cbegin() const noexcept
    {
        return (this->begin());
    }

    UTF8String::const_iterator UTF8String::cend() const noexcept
    {
        return (this->end());
    }

    const std::string& UTF8String::str() const noexcept
    {
        return (this->_data);
    }

    bool UTF8String::empty() const noexcept
    {
        return (this->_data.empty());
    }

    std::size_t UTF8String::length() const noexcept
    {
        if (this->_length == std::numeric_limits<std::size_t>::max())
            this->_length = utf8::distance(this->_data.begin(), this->_data.end());
        return (this->_length);
    }

    char32_t UTF8String::at(std::size_t i) const noexcept
    {
        auto it = this->_data.begin();
        utf8::advance(it, i, this->_data.end());
        return (utf8::next(it, this->_data.end()));
    }

    void UTF8String::clear() noexcept
    {
        this->_data.clear();
        this->_length = 0;
        return;
    }

    UTF8String UTF8String::substr(std::size_t i, std::size_t length) const
    {
        if (i >= this->length())
            return ("");
        length = std::min(this->length() - i, length);
        auto begin = this->_data.begin();
        utf8::advance(begin, i, this->_data.end());
        auto end = begin;
        utf8::advance(end, length, this->_data.end());
        return (UTF8String(std::string(begin, end)));
    }

}
