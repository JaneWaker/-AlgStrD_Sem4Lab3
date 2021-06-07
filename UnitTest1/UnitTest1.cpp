#include <iostream>
#include "CppUnitTest.h"
#include "../AlgStrD_4sem_lab3/Floyd-Warshall.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(test)
		{
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(Graph1)
		{
			try {
				Graph Test;
				string s = "in2.txt";
				Test.input(s);
				size_t res = 3, temp1 = Test.FloydWarshall(0, 3);
				Assert::AreEqual(temp1, res);
				Test.clear();
			}
			catch (char*)
			{
				Assert::AreEqual(1, 0);
			}
		}
		TEST_METHOD(Graph2)
		{
			try {
				Graph Test;
				Test.input();
				size_t res = 68, temp1 = Test.FloydWarshall(3, 0);;
				Assert::AreEqual(temp1, res);
				Test.clear();
			}
			catch (char*)
			{
				Assert::AreEqual(1, 0);
			}
		}
	};
}