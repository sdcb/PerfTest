#pragma once

namespace StructClass
{
	class StructClassTest
	{
	public:
		static void DoTest();

		const int CaseSize = 20 * 1024 * 1024;

	private:
		void ShowMemory();

		void ClassMemoryTest();

		void StructMemoryTest();

		void ClassTimeTest();

		void StructTimeTest();

		void GenerateClassTimeTest();

		void GenerateStructTimeTest();
	};
}