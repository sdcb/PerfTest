#pragma once

#include <map>

namespace HashVsRBT
{
	struct RBT
	{
		static std::map<std::string, std::string> CreateN(size_t size);
	};
}