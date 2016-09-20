#include "StructClassTest.h"
#include "Vector2C.h"
#include "Vector2S.h"
#include "..\Utils\Utils.h"

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void StructClass::StructClassTest::DoTest()
{
	StructClassTest t;

	t.ShowMemory();

	t.ClassMemoryTest();
	t.StructMemoryTest();

	t.ClassTimeTest();
	t.StructTimeTest();

	t.GenerateClassTimeTest();
	t.GenerateStructTimeTest();
}

void StructClass::StructClassTest::ShowMemory()
{
	cout << "Memory: " << Utils::GetProcessMemorySizeMb() << " MB." << endl;
}

void StructClass::StructClassTest::ClassMemoryTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = Vector2C::CreateN(CaseSize);
	ShowMemory();
}

void StructClass::StructClassTest::StructMemoryTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = Vector2S::CreateN(CaseSize);
	ShowMemory();
}

void StructClass::StructClassTest::ClassTimeTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = Vector2C::CreateN(CaseSize);
	auto time = Utils::MeasureTime([&]() {
		auto avg = 1.0 * accumulate(begin(buffer), end(buffer), size_t{}, [](size_t a, shared_ptr<Vector2S> b) {
			return a + b->X + b->Y;
		}) / buffer.size();
		cout << "avg = " << avg << "." << endl;
	});
	cout << "time = " << time << "ms." << endl;
}

void StructClass::StructClassTest::StructTimeTest()
{
	cout << __FUNCTION__ << endl;
	auto buffer = Vector2S::CreateN(CaseSize);
	auto time = Utils::MeasureTime([&]() {
		auto avg = 1.0 * accumulate(begin(buffer), end(buffer), size_t{}, [](size_t a, Vector2S b) {
			return a + b.X + b.Y;
		}) / buffer.size();
		cout << "avg = " << avg << "." << endl;
	});
	cout << "time = " << time << "ms." << endl;
}

void StructClass::StructClassTest::GenerateClassTimeTest()
{
	cout << __FUNCTION__ << endl;
	auto time = Utils::MeasureTime([&]() { Vector2C::CreateN(CaseSize); });
	cout << "time = " << time << "ms." << endl;
}

void StructClass::StructClassTest::GenerateStructTimeTest()
{
	auto time = Utils::MeasureTime([&]() { Vector2S::CreateN(CaseSize); });
	cout << "time = " << time << "ms." << endl;
}
