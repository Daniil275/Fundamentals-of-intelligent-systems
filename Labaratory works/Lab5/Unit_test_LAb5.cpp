#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Visual c++\Lab5_AOIS\Lab5_AOIS\Source.cpp"
#include <deque>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1testforlab5
{
	TEST_CLASS(UnitTest1testforlab5)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Digital_machine exempl;
			exempl.converter(0);
			string test_SDNF;
			string test_SKNF;
			Assert::IsTrue(exempl.get_SDNF_rez().empty() && exempl.get_SKNF_rez().empty());
		}

		TEST_METHOD(TestMethod2)
		{
			Digital_machine exempl;
			exempl.converter(1);
			string test_SDNF{"(!Q1*!Q2*!Q3*V)"};
			string test_SKNF{"(Q1+Q2+Q3+V)"};
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod3)
		{
			Digital_machine exempl;
			exempl.converter(2);
			string test_SDNF{"(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)"};
			string test_SKNF{"(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)"};
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod4)
		{
			Digital_machine exempl;
			exempl.converter(3);
			string test_SDNF{"(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)"};
			string test_SKNF{"(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)"};
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod5)
		{
			Digital_machine exempl;
			exempl.converter(4);
			string test_SDNF{"(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)+(!Q1*Q2*Q3*V)"};
			string test_SKNF{"(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)*(Q1+!Q2+!Q3+V)"};
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod6)
		{
			Digital_machine exempl;
			exempl.converter(5);
			string test_SDNF{"(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)+(!Q1*Q2*Q3*V)+(Q1*!Q2*!Q3*V)"};
			string test_SKNF{"(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)*(Q1+!Q2+!Q3+V)*(!Q1+Q2+Q3+V)"};
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod7)
		{
			Digital_machine exempl;
			exempl.converter(6);
			string test_SDNF{ "(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)+(!Q1*Q2*Q3*V)+(Q1*!Q2*!Q3*V)+(Q1*!Q2*Q3*V)" };
			string test_SKNF{ "(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)*(Q1+!Q2+!Q3+V)*(!Q1+Q2+Q3+V)*(!Q1+Q2+!Q3+V)" };
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod8)
		{
			Digital_machine exempl;
			exempl.converter(7);
			string test_SDNF{ "(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)+(!Q1*Q2*Q3*V)+(Q1*!Q2*!Q3*V)+(Q1*!Q2*Q3*V)+(Q1*Q2*!Q3*V)" };
			string test_SKNF{ "(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)*(Q1+!Q2+!Q3+V)*(!Q1+Q2+Q3+V)*(!Q1+Q2+!Q3+V)*(!Q1+!Q2+Q3+V)" };
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}

		TEST_METHOD(TestMethod9)
		{
			Digital_machine exempl;
			exempl.converter(8);
			string test_SDNF{ "(!Q1*!Q2*!Q3*V)+(!Q1*!Q2*Q3*V)+(!Q1*Q2*!Q3*V)+(!Q1*Q2*Q3*V)+(Q1*!Q2*!Q3*V)+(Q1*!Q2*Q3*V)+(Q1*Q2*!Q3*V)+(Q1*Q2*Q3*V)" };
			string test_SKNF{ "(Q1+Q2+Q3+V)*(Q1+Q2+!Q3+V)*(Q1+!Q2+Q3+V)*(Q1+!Q2+!Q3+V)*(!Q1+Q2+Q3+V)*(!Q1+Q2+!Q3+V)*(!Q1+!Q2+Q3+V)*(!Q1+!Q2+!Q3+V)" };
			Assert::IsTrue(exempl.get_SDNF_rez() == test_SDNF && exempl.get_SKNF_rez() == test_SKNF);
		}
		TEST_METHOD(TestMethod10)
		{
			Digital_machine exempl;
			exempl.converter(9);
			string test_SDNF;
			string test_SKNF;
			Assert::IsFalse(exempl.get_SDNF_rez().empty() && exempl.get_SKNF_rez().empty());
		}

	};
}
