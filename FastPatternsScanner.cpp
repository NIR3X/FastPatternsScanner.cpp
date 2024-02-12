#include "FastPatternsScanner.h"

CFastPatternsScanner::CFastPatternsScanner(const std::unordered_set<std::vector<uint8_t>>& patterns) : patterns(patterns), patternsBytesMap({}), maxPatternSize(0) {
	for (const std::vector<uint8_t>& pattern : patterns) {
		size_t patternSize = pattern.size();

		for (size_t i = 0; i < patternSize; ++i) {
			patternsBytesMap[i].insert(pattern[i]);
		}

		if (patternSize > maxPatternSize) {
			maxPatternSize = patternSize;
		}
	}
}

std::vector<uint8_t> CFastPatternsScanner::ContainsAny(const uint8_t* data, size_t dataSize) const {
	for (size_t i = 0; i < dataSize; ++i) {
		std::vector<uint8_t> foundPattern = {};

		std::vector<uint8_t> temp = {};
		for (size_t jBegin = i, j = jBegin, jEnd = (std::min)(jBegin + maxPatternSize, dataSize); j < jEnd; ++j) {
			uint8_t byte = data[j];
			const auto& bytesMap = patternsBytesMap.at(j - jBegin);
			if (bytesMap.find(byte) == bytesMap.end()) {
				break;
			}
			temp.push_back(byte);
			if (patterns.find(temp) != patterns.end()) {
				if (temp.size() > foundPattern.size()) {
					i = j;
					foundPattern.insert(foundPattern.end(), temp.begin() + foundPattern.size(), temp.end());
				}
			}
			if (temp.size() == maxPatternSize) {
				break;
			}
		}
	
		if (foundPattern.size() > 0) {
			return foundPattern;
		}
	}

	return {};
}

std::vector<uint8_t> CFastPatternsScanner::ContainsAny(const std::vector<uint8_t>& data) const {
	return ContainsAny(data.data(), data.size());
}

std::vector<uint8_t> CFastPatternsScanner::ContainsAny(const std::string& data) const {
	return ContainsAny((const uint8_t*)data.data(), data.size());
}
