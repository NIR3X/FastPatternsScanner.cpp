#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace std {
	template <>
	struct hash<std::vector<uint8_t>> {
		size_t operator()(const std::vector<uint8_t>& v) const {
			size_t seed = v.size();
			for (const auto& i : v) {
				seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};
}

class CFastPatternsScanner {
protected:
	std::unordered_set<std::vector<uint8_t>> patterns;
	std::unordered_map<size_t, std::unordered_set<uint8_t>> patternsBytesMap;
	size_t maxPatternSize;

public:
	CFastPatternsScanner(const std::unordered_set<std::vector<uint8_t>>& patterns);

	std::vector<uint8_t> ContainsAny(const uint8_t* data, size_t dataSize) const;
	std::vector<uint8_t> ContainsAny(const std::vector<uint8_t>& data) const;
	std::vector<uint8_t> ContainsAny(const std::string& data) const;
};
