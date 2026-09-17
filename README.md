# tbaricault::str

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++23](https://img.shields.io/badge/C%2B%2B-23-blue)
![CMake](https://img.shields.io/badge/CMake-3.20%2B-blue)

## Description

This C++23 library provides utility functions and classes for string manipulation.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
    - [Download and install](#download-and-install)
    - [Uninstall](#uninstall)
    - [CMake](#cmake)
    - [Include](#include)
    - [Environment](#environment)
- [Documentation](#documentation)
- [Examples](#examples)
    - [String manipulation](#string-manipulation)
    - [Case switching](#case-switching)
    - [UTF-8 string usage](#utf-8-string-usage)
- [License](#license)

## Features

- UTF-8 string class
- String manipulation functions

## Requirements

- C++23 or later
- CMake 3.20 or later
- [nemtrif/utfcpp](https://github.com/nemtrif/utfcpp)

## Usage

### Download and install

```Shell
git clone https://github.com/Thomas-Baricault/str.git
cd str
make install
```

### Uninstall

```Shell
make uninstall
```

### CMake

Add the library to your project:

```cmake
find_package(tbaricault_str REQUIRED)

target_link_libraries(
    my_target
    PRIVATE
        tbaricault::str
)
```

### Include

```cpp
#include <tbaricault/str.hpp>
```

### Environment

If you have a custom C++ installation, you can edit the `ENV` variable in the `Makefile` to specify your environment path.

Example on Windows with MSYS2/MinGW64:

```makefile
ENV = C:/msys64/mingw64
```

## Documentation

Read the complete documentation at [https://docs.thomas-baricault.fr/str](https://docs.thomas-baricault.fr/str).

## Examples

### Case switching

```cpp
#include <iostream>
#include <tbaricault/str.hpp>


int main()
{
    std::string snake = "snake_case";
    std::string camel = "camelCase";
    std::string pascal = "PascalCase";

    std::cout << tbaricault::str::snakeToCamel(snake) << std::endl;
    std::cout << tbaricault::str::snakeToPascal(snake) << std::endl;
    std::cout << tbaricault::str::camelToSnake(camel) << std::endl;
    std::cout << tbaricault::str::camelToPascal(camel) << std::endl;
    std::cout << tbaricault::str::pascalToSnake(pascal) << std::endl;
    std::cout << tbaricault::str::pascalToCamel(pascal) << std::endl;

    return (0);
}
```

Output:

```text
snakeCase
SnakeCase
camel_case
CamelCase
pascal_case
pascalCase
```

### String manipulation

```cpp
#include <iostream>
#include <vector>
#include <tbaricault/str.hpp>


int main()
{
    std::cout << "Split:" << std::endl;
    for (auto word : tbaricault::str::split("String to split"))
        std::cout << word << std::endl;
    std::cout << std::endl;

    std::cout << "Join:" << std::endl;
    std::string_view words[] = {"String", "to", "join"};
    std::cout << tbaricault::str::join(words, " ") << std::endl;
    std::cout << std::endl;

    std::cout << "Repeat:" << std::endl;
    std::cout << tbaricault::str::repeat("String to repeat ", 3) << std::endl;
    std::cout << std::endl;

    std::cout << "Indent:" << std::endl;
    std::cout << tbaricault::str::indent(
        "    This is a long\n"
        "text paragraph to\n"
        "indent using\n"
        "tbaricault::str::indent",
        4
    ) << std::endl;
    std::cout << std::endl;

    std::cout << "Trim:" << std::endl;
    std::string s = " \t  String to trim   ";
    std::cout << "String: \"" << s << "\"" << std::endl;
    std::cout << "Left trim: \"" << tbaricault::str::leftTrim(s) << "\"" << std::endl;
    std::cout << "Right trim: \"" << tbaricault::str::rightTrim(s) << "\"" << std::endl;
    std::cout << "Both trim: \"" << tbaricault::str::trim(s) << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "Contains only:" << std::endl;
    std::cout << tbaricault::str::containsOnly("73", "0123456789") << std::endl;
    std::cout << tbaricault::str::containsOnly("73a", "0123456789") << std::endl;
    std::cout << tbaricault::str::containsOnly("", "0123456789") << std::endl;
    std::cout << tbaricault::str::containsOnly("73", "") << std::endl;

    return (0);
}
```

Output:

```text
Split:
String
to
split

Join:
String to join

Repeat:
String to repeat String to repeat String to repeat 

Indent:
        This is a long
    text paragraph to
    indent using
    tbaricault::str::indent

Trim:
String: "         String to trim   "
Left trim: "String to trim   "
Right trim: "     String to trim"
Both trim: "String to trim"

Contains only:
1
0
1
0
```

### UTF-8 string usage

```cpp
#include <iostream>
#include <tbaricault/str.hpp>


int main()
{
    std::string s = "Hello world! 🌍";

    tbaricault::str::UTF8String u = s;

    std::cout << s.length() << std::endl;
    std::cout << u.length() << std::endl;

    return (0);
}
```

Output:

```text
17
14
```

## License

This project is licensed under the MIT License.

See [LICENSE](LICENSE) for details.
