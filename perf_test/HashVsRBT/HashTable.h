#pragma once

#include <unordered_map>

namespace HashVsRBT
{
	struct HashTable
	{
		static std::unordered_map<std::string, std::string> CreateN(size_t size);
	};
}