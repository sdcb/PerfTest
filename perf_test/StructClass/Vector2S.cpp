#include "Vector2S.h"
#include <stdlib.h>

using namespace StructClass;

StructClass::Vector2S::Vector2S(int x, int y)
{
	X = x;
	Y = y;
}

Vector2S Vector2S::CreateRandom()
{
	return Vector2S(abs(rand() % 10), abs(rand() % 10));
}

std::vector<Vector2S> StructClass::Vector2S::CreateN(size_t size)
{
	std::vector<Vector2S> vec(size);
	for (auto& v : vec)
	{
		v = CreateRandom();
	}
	return vec;
}
