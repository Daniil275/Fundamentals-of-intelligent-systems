#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Visual c++\Aois_lab2\Aois_lab2\Source.cpp"
#include <deque>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforAOISlab2
{
	TEST_CLASS(UnitTestforAOISlab2)
	{
	public:
		
		TEST_METHOD(TestMethod1) // task 1
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input{5, 6, 3};
			string result_SDNF1 = " (!X1 * X2 * X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + X3)  *  (!X1 + X2 + X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, false, 0);
			if(exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if(exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod2) // task 1
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input{ 0,1,3,7,8,9,11,15 };
			string result_SDNF1 = " (!X1 * !X2 * !X3 * !X4)  +  (!X1 * !X2 * !X3 * X4)  +  (!X1 * !X2 * X3 * X4)  +  (!X1 * X2 * X3 * X4)  +  (X1 * !X2 * !X3 * !X4)  +  (X1 * !X2 * !X3 * X4)  +  (X1 * !X2 * X3 * X4)  +  (X1 * X2 * X3 * X4) ";
			string result_SKNF1 = " (X1 + X2 + !X3 + X4)  *  (X1 + !X2 + X3 + X4)  *  (X1 + !X2 + X3 + !X4)  *  (X1 + !X2 + !X3 + X4)  *  (!X1 + X2 + !X3 + X4)  *  (!X1 + !X2 + X3 + X4)  *  (!X1 + !X2 + X3 + !X4)  *  (!X1 + !X2 + !X3 + X4) ";
			exmpl.analysis_input(input, false, 0);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}
		TEST_METHOD(TestMethod3) //task 1
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input{ 0,2,3,8,10,11,12,14,15 };
			string result_SDNF1 = " (!X1 * !X2 * !X3 * !X4)  +  (!X1 * !X2 * X3 * !X4)  +  (!X1 * !X2 * X3 * X4)  +  (X1 * !X2 * !X3 * !X4)  +  (X1 * !X2 * X3 * !X4)  +  (X1 * !X2 * X3 * X4)  +  (X1 * X2 * !X3 * !X4)  +  (X1 * X2 * X3 * !X4)  +  (X1 * X2 * X3 * X4) ";
			string result_SKNF1 = " (X1 + X2 + X3 + !X4)  *  (X1 + !X2 + X3 + X4)  *  (X1 + !X2 + X3 + !X4)  *  (X1 + !X2 + !X3 + X4)  *  (X1 + !X2 + !X3 + !X4)  *  (!X1 + X2 + X3 + !X4)  *  (!X1 + !X2 + X3 + !X4) ";
			exmpl.analysis_input(input, false, 0);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod4) //task 2
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * X2 * !X3)  +  (X1 * !X2 * !X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + !X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 46);
			if(exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if(exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod5) //task 2
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * !X2 * X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + !X2 + X3)  *  (X1 + !X2 + !X3)  *  (!X1 + X2 + X3)  *  (!X1 + !X2 + X3) ";
			exmpl.analysis_input(input, true, 69);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod6) //task 2
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * !X2 * X3)  +  (!X1 * X2 * !X3)  +  (!X1 * X2 * X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (!X1 + X2 + X3)  *  (!X1 + X2 + !X3)  *  (!X1 + !X2 + X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 112);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod7) //task 3
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * X2 * !X3)  +  (X1 * !X2 * !X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + !X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 46);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod8) //task 3
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * X2 * !X3)  +  (X1 * !X2 * !X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + !X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 46);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}
		TEST_METHOD(TestMethod9) //task 3
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * X2 * !X3)  +  (X1 * !X2 * !X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + !X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 46);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}

		TEST_METHOD(TestMethod10) //task 3
		{
			Logic_function exmpl;
			bool SDNF = false, SKNF = false;
			deque<int> input;
			string result_SDNF1 = " (!X1 * X2 * !X3)  +  (X1 * !X2 * !X3)  +  (X1 * !X2 * X3)  +  (X1 * X2 * !X3) ";
			string result_SKNF1 = " (X1 + X2 + X3)  *  (X1 + X2 + !X3)  *  (X1 + !X2 + !X3)  *  (!X1 + !X2 + !X3) ";
			exmpl.analysis_input(input, true, 46);
			if (exmpl.get_SDNF_rez() == result_SDNF1) SDNF = true;
			if (exmpl.get_SKNF_rez() == result_SKNF1) SKNF = true;
			Assert::IsTrue(SDNF && SKNF);
		}


	};
}
