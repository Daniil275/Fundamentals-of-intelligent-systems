#include "pch.h"
#include "CppUnitTest.h"
#include "D:\\Visual c++\\Lab4_Aois\\Lab4_Aois\\Source.cpp"
#include <deque>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLabAois4
{
	TEST_CLASS(UnitTestLabAois4)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Combinational_scheme exempl;
			string checker_SDNF{" (!X1 * X2 * X3) + (X1 * !X2 * !X3) + (X1 * X2 * X3)"};
			string checker_TDNF{ " (X1 * X2 * X3)" };
			string checker_SKNF{" (X1 + X2 + X3) * (X1 + X2 + !X3) * (X1 + !X2 + X3) * (!X1 + X2 + X3)  "};
			string checker_TKNF{ " (X1 + X2 + X3) * (X1 + X2 + !X3) * (X1 + !X2 + X3) * (!X1 + X2 + X3)  " };
			deque<bool> out1{ 0 ,0, 0 ,0 ,0 ,0, 0, 1 };
			deque<bool> out2{ 0, 0 ,0 ,1, 1 ,0, 0, 1 };
			exempl.scheme_SDNF(out1, out2);
		 	Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF && exempl.get_TDNF_rez() == checker_TDNF);
		}

		TEST_METHOD(TestMethod2)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ " (!X1 * X2 * X3) + (X1 * !X2 * !X3) " };
			string checker_TDNF{ " (X1 * X2 * X3) + (!X1 * X2 * X3)" };
			string checker_SKNF{ " (X1 + X2 + X3) * (X1 + X2 + !X3) * (X1 + !X2 + X3) * (!X1 + X2 + X3) * (!X1 + X2 + !X3)  " };
			string checker_TKNF{ " (X1 + X2)  * (X3)   " };
			deque<bool> out1{ 0 ,0, 0 ,0 ,0 ,0, 0, 1 };
			deque<bool> out2{ 0, 0, 0, 1, 0, 0, 1, 1 };
			exempl.scheme_SKNF(out1, out2);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF && exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod3)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ " (!X1 * !X2 * X3) + (!X1 * X2 * !X3) + (!X1 * X2 * X3) + (X1 * !X2 * !X3) + (X1 * !X2 * X3) + (X1 * X2 * !X3) + (X1 * X2 * X3) " };
			string checker_TDNF{ " (!X1)      + (X2 * X3) " };
			string checker_SKNF{ " (X1 + X2 + X3)  " };
			string checker_TKNF{ " (X1 + X2 + X3) " };
			deque<bool> out1{ 0,1,1,1,1,1,1,1 };
			deque<bool> out2{ 0,1,1,1,1,1,1,1 };
			exempl.scheme_SKNF(out1, out2);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF && exempl.get_TKNF_rez() == checker_TKNF );
		}

		TEST_METHOD(TestMethod4)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ " (!X1 * !X2 * X3) + (!X1 * X2 * !X3) + (!X1 * X2 * X3) + (X1 * !X2 * !X3) + (X1 * !X2 * X3) + (X1 * X2 * !X3) + (X1 * X2 * X3)" };
			string checker_TDNF{ " (!X1)      + (X2 * X3)" };
			string checker_SKNF{ " (X1 + X2 + X3) " };
			string checker_TKNF{ " (X1 + X2 + X3) " };
			deque<bool> out1{ 0,1,1,1,1,1,1,1 };
			deque<bool> out2{ 0,1,1,1,1,1,1,1 };
			exempl.scheme_SDNF(out1, out2);
			Assert::IsTrue( exempl.get_SDNF_rez() == checker_SDNF && exempl.get_TDNF_rez() == checker_TDNF);
		}

		TEST_METHOD(TestMethod5)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ "(!X1*!X2*X3*X4)+(!X1*X2*!X3*!X4)+(!X1*X2*!X3*X4)+(!X1*X2*X3*!X4)+(!X1*X2*X3*X4)+(X1*!X2*!X3*!X4)+(X1*!X2*!X3*X4)+(X1*!X2*X3*!X4)+(X1*!X2*X3*X4)+(X1*X2*!X3*!X4)+(X1*X2*!X3*X4)+(X1*X2*X3*!X4)+(X1*X2*X3*X4)" };
			string checker_TDNF{ "!X2*X3*X4)+(!X1*X2*!X3+(!X1*X2*!X4)+X2*!X3*!X4)+(!X1*X2*X4)+X2*!X3*X4)+(!X1*X2*X3+X2*X3*!X4)+(X1*!X2*!X3+(X1*!X2*!X4)+(X1*!X3*!X4)+(X1*!X2*X4)+(X1*!X3*X4)+(X1*!X2*X3+(X1*X3*!X4)+(X1*X2*!X3+(X1*X2*!X4)+(X1*X2*X3" };
			string checker_SKNF{ "(X1+X2+X3+X4)*(X1+X2+X3+!X4)*(X1+X2+!X3+X4)" };
			string checker_TKNF{ "(X1+X2+X3)*(X1+X2+X4)" };
			exempl.converter(5);
			Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF && exempl.get_TDNF_rez() == checker_TDNF && exempl.get_SKNF_rez() == checker_SKNF && exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod6)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ "(!X1*X2*X3*!X4)+(!X1*X2*X3*X4)+(X1*!X2*!X3*!X4)+(X1*!X2*!X3*X4)+(X1*!X2*X3*!X4)+(X1*!X2*X3*X4)+(X1*X2*!X3*!X4)+(X1*X2*!X3*X4)+(X1*X2*X3*!X4)+(X1*X2*X3*X4)" };
			string checker_SKNF{ "(X1+X2+X3+X4)*(X1+X2+X3+!X4)*(X1+X2+!X3+X4)*(X1+X2+!X3+!X4)*(X1+!X2+X3+X4)*(X1+!X2+X3+!X4)" };
			string checker_TDNF{ "X2*X3*!X4)+(X1*!X2*!X3+(X1*!X2*!X4)+(X1*!X3*!X4)+(X1*!X2*X4)+(X1*!X3*X4)+(X1*!X2*X3+(X1*X2*!X3+(X1*X2*!X4)+(X1*X2*X3" };
			string checker_TKNF{ "(X1+X3+!X4)*(" };
			exempl.converter(2);
			Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF);
			Assert::IsTrue(exempl.get_TDNF_rez() == checker_TDNF);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF);
			Assert::IsTrue(exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod7)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ "(!X1*!X2*X3*!X4)+(!X1*!X2*X3*X4)+(!X1*X2*!X3*!X4)+(!X1*X2*!X3*X4)+(!X1*X2*X3*!X4)+(!X1*X2*X3*X4)+(X1*!X2*!X3*!X4)+(X1*!X2*!X3*X4)+(X1*!X2*X3*!X4)+(X1*!X2*X3*X4)+(X1*X2*!X3*!X4)+(X1*X2*!X3*X4)+(X1*X2*X3*!X4)+(X1*X2*X3*X4)" };
			string checker_SKNF{ "(X1+X2+X3+X4)*(X1+X2+X3+!X4)" };
			string checker_TDNF{ "!X2*X3*!X4)+(!X1*X3*X4)+!X2*X3*X4)+(!X1*X2*!X3+(!X1*X2*!X4)+X2*!X3*!X4)+(!X1*X2*X4)+X2*!X3*X4)+(!X1*X2*X3+X2*X3*!X4)+(X1*!X2*!X3+(X1*!X2*!X4)+(X1*!X3*!X4)+(X1*!X2*X4)+(X1*!X3*X4)+(X1*!X2*X3+(X1*X3*!X4)+(X1*X2*!X3+(X1*X2*!X4)+(X1*X2*X3" };
			string checker_TKNF{ "(X1+X2+X3)" };
			exempl.converter(6);
			Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF);
			Assert::IsTrue(exempl.get_TDNF_rez() == checker_TDNF);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF);
			Assert::IsTrue(exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod8)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ "(!X1*X2*!X3*X4)+(!X1*X2*X3*!X4)+(!X1*X2*X3*X4)+(X1*!X2*!X3*!X4)+(X1*!X2*!X3*X4)+(X1*!X2*X3*!X4)+(X1*!X2*X3*X4)+(X1*X2*!X3*!X4)+(X1*X2*!X3*X4)+(X1*X2*X3*!X4)+(X1*X2*X3*X4)" };
			string checker_SKNF{ "(X1+X2+X3+X4)*(X1+X2+X3+!X4)*(X1+X2+!X3+X4)*(X1+X2+!X3+!X4)*(X1+!X2+X3+X4)" };
			string checker_TDNF{ "X2*!X3*X4)+(!X1*X2*X3+X2*X3*!X4)+(X1*!X2*!X3+(X1*!X2*!X4)+(X1*!X3*!X4)+(X1*!X2*X4)+(X1*!X3*X4)+(X1*!X2*X3+(X1*X3*!X4)+(X1*X2*!X3+(X1*X2*!X4)+(X1*X2*X3" };
			string checker_TKNF{ "(X1+X3+X4)*(X1+X2+!X4)*(" };
			exempl.converter(3);
			Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF);
			Assert::IsTrue(exempl.get_TDNF_rez() == checker_TDNF);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF);
			Assert::IsTrue(exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod9)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ "(!X1*X2*!X3*!X4)+(!X1*X2*!X3*X4)+(!X1*X2*X3*!X4)+(!X1*X2*X3*X4)+(X1*!X2*!X3*!X4)+(X1*!X2*!X3*X4)+(X1*!X2*X3*!X4)+(X1*!X2*X3*X4)+(X1*X2*!X3*!X4)+(X1*X2*!X3*X4)+(X1*X2*X3*!X4)+(X1*X2*X3*X4)" };
			string checker_SKNF{ "(X1+X2+X3+X4)*(X1+X2+X3+!X4)*(X1+X2+!X3+X4)*(X1+X2+!X3+!X4)" };
			string checker_TDNF{ "X2*!X3*!X4)+(!X1*X2*X4)+X2*!X3*X4)+(!X1*X2*X3+X2*X3*!X4)+(X1*!X2*!X3+(X1*!X2*!X4)+(X1*!X3*!X4)+(X1*!X2*X4)+(X1*!X3*X4)+(X1*!X2*X3+(X1*X3*!X4)+(X1*X2*!X3+(X1*X2*!X4)+(X1*X2*X3" };
			string checker_TKNF{ "(X1+X2+!X4)*(" };
			exempl.converter(4);
			Assert::IsTrue(exempl.get_SDNF_rez() == checker_SDNF);
			Assert::IsTrue(exempl.get_TDNF_rez() == checker_TDNF);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF);
			Assert::IsTrue(exempl.get_TKNF_rez() == checker_TKNF);
		}

		TEST_METHOD(TestMethod10)
		{
			Combinational_scheme exempl;
			string checker_SDNF{ " (!X1 * X2 * X3) + (X1 * !X2 * !X3) " };
			string checker_TDNF{ " (X1 * X2 * X3) + (!X1 * X2 * X3)" };
			string checker_SKNF{ " (X1 + X2 + X3) * (X1 + X2 + !X3) * (X1 + !X2 + X3) * (!X1 + X2 + X3) * (!X1 + X2 + !X3)  " };
			string checker_TKNF{ " (X1 + X2)  * (X3)   " };
			deque<bool> out1{ 0 ,0, 0 ,0 ,0 ,0, 0, 1 };
			deque<bool> out2{ 0,0,0,1,0,0,1,1 };
			exempl.scheme_SKNF(out1, out2);
			Assert::IsTrue(exempl.get_SKNF_rez() == checker_SKNF && exempl.get_TKNF_rez() == checker_TKNF);
		}


	};
}
