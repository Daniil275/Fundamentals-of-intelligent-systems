#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Visual c++\Aois_Lab8\Aois_Lab8\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab8
{
	TEST_CLASS(UnitTestLab8)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0;
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
				}
			}
			Assert::IsTrue(count == 256);
		}

		TEST_METHOD(TestMethod2)
		{
			Asoc_memory exempl;
			exempl.add_element("0000000100011110038257927502751-75-`757");
			string checker;
			int count = 0;
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
				}
			}
			Assert::IsTrue(count == 256);
		}

		TEST_METHOD(TestMethod3)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0;
			exempl.add_element("!@#$%%^^&**())_+++_)(*&^%$#@!~");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
				}
			}
			Assert::IsTrue(count == 256);
		}

		TEST_METHOD(TestMethod4)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0; 
			exempl.add_element("1111111111111111");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 240 && count_truth == 16);
		}

		TEST_METHOD(TestMethod5)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1100000000111111");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 248 && count_truth == 8);
		}

		TEST_METHOD(TestMethod6)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1111111111111111");
			exempl.add_element("0101010101010101");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 232 && count_truth == 24);
		}

		TEST_METHOD(TestMethod7)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1111111111111111");
			exempl.add_element("0101010101010101");
			exempl.add_element("1101010101111001");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 222 && count_truth == 34);
		}

		TEST_METHOD(TestMethod8)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1111111111111111");
			exempl.add_element("0101010101010101");
			exempl.add_element("1101010101111001");
			exempl.add_element("0101011111111000");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 212 && count_truth == 44);
		}

		TEST_METHOD(TestMethod9)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1111111111111111");
			exempl.add_element("0101010101010101");
			exempl.ariphmetics();
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 232 && count_truth == 24);
		}

		TEST_METHOD(TestMethod10)
		{
			Asoc_memory exempl;
			string checker;
			int count = 0, count_truth = 0;
			exempl.add_element("1111111111111111");
			exempl.add_element("0101010101010101");
			exempl.add_element("1101010101111001");
			exempl.add_element("0101011111111000");
			for (size_t i = 0; i < 16; i++)
			{
				checker = exempl.get_element(i);
				for (size_t j = 0; j < checker.length(); j++)
				{
					if (checker[j] == '0') count++;
					else count_truth++;
				}
			}
			Assert::IsTrue(count == 212 && count_truth == 44);
		}
	};
}
