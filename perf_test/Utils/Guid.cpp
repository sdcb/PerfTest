#include "Guid.h"
#include <boost\uuid\uuid.hpp>
#include <boost\uuid\random_generator.hpp>
#include <boost\uuid\uuid_generators.hpp>
#include <boost\uuid\uuid_io.hpp>
#include <boost\lexical_cast.hpp>
#include <sstream>
#include <rpc.h>

#pragma comment(lib, "Rpcrt4.lib")


using namespace std;
boost::uuids::random_generator uuidGen{};

std::string Utils::NewGuidString()
{
	UUID uuid;
	UuidCreate(&uuid);
	RPC_CSTR cstr;
	UuidToStringA(&uuid, &cstr);
	string str = (char*)cstr;
	RpcStringFreeA(&cstr);
	return str;
}
