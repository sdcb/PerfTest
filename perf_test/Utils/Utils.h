#pragma once
#include <functional>

namespace Utils
{
	float GetProcessMemorySizeMb();

	long long MeasureTime(std::function<void()> action);
}
