#pragma once

#include "Vector2S.h"
#include <memory>

namespace StructClass
{
	struct Vector2C
	{
		static std::shared_ptr<Vector2S> CreateRandom();

		static std::vector<std::shared_ptr<Vector2S>> CreateN(size_t size);
	};
}