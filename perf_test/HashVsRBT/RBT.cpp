#include "RBT.h"
#include "..\Utils\Guid.h"

std::map<std::string, std::string> HashVsRBT::RBT::CreateN(size_t size)
{
	std::map<std::string, std::string> buffer;
	for (size_t i = 0; i < size; ++i)
	{
		buffer[Utils::NewGuidString()] = Utils::NewGuidString();
	}
	return buffer;
}
