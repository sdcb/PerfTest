#include "HashTable.h"
#include "..\Utils\Guid.h"

std::unordered_map<std::string, std::string> HashVsRBT::HashTable::CreateN(size_t size)
{
	std::unordered_map<std::string, std::string> buffer;
	for (size_t i = 0; i < size; ++i)
	{
		buffer[Utils::NewGuidString()] = Utils::NewGuidString();
	}
	return buffer;
}
