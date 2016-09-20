#include "Utils.h"
#include <Windows.h>
#include <Psapi.h>
#include <boost\date_time\posix_time\posix_time.hpp>
#pragma comment(lib, "psapi.lib")

float Utils::GetProcessMemorySizeMb()
{
	auto handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId());
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	CloseHandle(handle);
	
	return pmc.WorkingSetSize / 1024.0f / 1024;
}

long long Utils::MeasureTime(std::function<void()> action)
{
	auto t1 = boost::posix_time::microsec_clock::local_time();
	action();
	auto t2 = boost::posix_time::microsec_clock::local_time();
	return (t2 - t1).total_milliseconds();
}
