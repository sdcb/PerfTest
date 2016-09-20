#pragma once

#include <vector>

namespace StructClass 
{
	struct Vector2S
	{
		int X;
		int Y;

		Vector2S() = default;

		Vector2S(int x, int y);

		static Vector2S CreateRandom();

		static std::vector<Vector2S> CreateN(size_t size);
	};
}
