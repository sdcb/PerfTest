#include "Vector2C.h"

using namespace std;
using namespace StructClass;

shared_ptr<Vector2S> StructClass::Vector2C::CreateRandom()
{
	return make_shared<Vector2S>(abs(rand() % 10), abs(rand() % 10));
}

vector<shared_ptr<Vector2S>> StructClass::Vector2C::CreateN(size_t size)
{
	vector<shared_ptr<Vector2S>> vec(size);
	for (auto & v : vec)
	{
		v = CreateRandom();
	}
	return vec;
}
