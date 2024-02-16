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
