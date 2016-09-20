#pragma once
#include <functional>

namespace StructClass
{
	struct Utils
	{
		static float GetProcessMemorySizeMb();

		static long long MeasureTime(std::function<void()> action);
	};
}
