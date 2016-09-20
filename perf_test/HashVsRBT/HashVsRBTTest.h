#pragma once

namespace HashVsRBT
{
	struct HashVsRBTTest
	{
		int CaseSize = 200 * 1024;

	public:
		static void DoTest();

	private:
		void HashTimeTest();

		void RBTTimeTest();

		void HashFindTest();

		void RBTFindTest();
	};
}