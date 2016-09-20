#include "HashVsRBTTest.h"
#include "HashTable.h"
#include "RBT.h"
#include "..\Utils\Utils.h"
#include "..\Utils\Guid.h"
#include <iostream>

using namespace std;

void HashVsRBT::HashVsRBTTest::DoTest()
{
	HashVsRBTTest t;
	t.HashTimeTest();
	t.RBTTimeTest();

	t.HashFindTest();
	t.RBTFindTest();
}

void HashVsRBT::HashVsRBTTest::HashTimeTest()
{
	cout << __FUNCTION__ << endl;
	auto time = Utils::MeasureTime([&]() {HashTable::CreateN(CaseSize); });
	cout << "time: " << time << "ms." << endl;
}

void HashVsRBT::HashVsRBTTest::RBTTimeTest()
{
	cout << __FUNCTION__ << endl;
	auto time = Utils::MeasureTime([&]() {RBT::CreateN(CaseSize); });
	cout << "time: " << time << "ms." << endl;
}

void HashVsRBT::HashVsRBTTest::HashFindTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = HashTable::CreateN(CaseSize);
	auto time = Utils::MeasureTime([&]() { 
		for (auto i = 0; i < CaseSize; ++i)
		{
			buffer.find(Utils::NewGuidString());
		}
	});
	cout << "time: " << time << "ms." << endl;
}

void HashVsRBT::HashVsRBTTest::RBTFindTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = RBT::CreateN(CaseSize);
	auto time = Utils::MeasureTime([&]() {
		for (auto i = 0; i < CaseSize; ++i)
		{
			buffer.find(Utils::NewGuidString());
		}
	});
	cout << "time: " << time << "ms." << endl;
}
