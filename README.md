# FastPatternsScanner.cpp - Efficient Pattern Scanner for C++

FastPatternsScanner.cpp is a C++ implementation of a fast pattern scanner. It includes a class `CFastPatternsScanner` that allows efficient searching for patterns in data.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/FastPatternsScanner.cpp
cd FastPatternsScanner.cpp
make
```

## Usage

To use the `CFastPatternsScanner` class, follow these steps:

1. Include the `FastPatternsScanner.h` header file in your C++ project.
2. Create a `std::unordered_set<std::vector<uint8_t>>` containing the patterns you want to search for.
3. Instantiate a `CFastPatternsScanner` object with the patterns.
4. Use the `ContainsAny` method to search for patterns in your data.

Example usage:

```cpp
#include "FastPatternsScanner.h"
#include <cassert>
#include <iostream>

int main() {
	std::vector<std::vector<uint8_t>> patternsList = { {1}, {1, 2}, {1, 2, 3}, {48} };
	CFastPatternsScanner fastPatternsScanner({ patternsList.begin(), patternsList.end() });
	assert(fastPatternsScanner.ContainsAny(std::vector<uint8_t> {4, 1, 5, 6, 7}) == patternsList[0]);
	assert(fastPatternsScanner.ContainsAny(std::vector<uint8_t> {4, 5, 1, 2, 6}) == patternsList[1]);
	assert(fastPatternsScanner.ContainsAny(std::vector<uint8_t> {4, 5, 1, 2, 3}) == patternsList[2]);
	assert(fastPatternsScanner.ContainsAny("9876543210") == patternsList[3]);
	std::cout << "PASS" << std::endl;
}
```

## License
[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)  

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
