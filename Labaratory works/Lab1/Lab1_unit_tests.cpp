#include "pch.h"
#include "CppUnitTest.h"
#include "..\Aois_first_Lb\Source.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnittestforAOIS1
{
	TEST_CLASS(UnittestforAOIS1)
	{
		static const int bit_depth = 16;

	public:
		TEST_METHOD(TestMethod1)//test converting
		{
			Numbers x1(9, bit_depth), x2(22, bit_depth);
			vector<bool> nine_in_binary      { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 };
			vector<bool> twenty_two_in_binary{ 0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0 };
			Assert::IsTrue(x1.get_numbr() == 9 && x2.get_numbr() == 22);
			Assert::IsTrue(x1.get_direct_vector() == nine_in_binary && x2.get_direct_vector() == twenty_two_in_binary);
			Assert::IsTrue(x1.get_backward_vector() == nine_in_binary && x2.get_backward_vector() == twenty_two_in_binary);
			Assert::IsTrue(x1.get_additional_vector() == nine_in_binary && x2.get_additional_vector() == twenty_two_in_binary);
			
		}
		TEST_METHOD(TestMethod2)//test converting
		{
			Numbers x3(-9, bit_depth), x4(-22, bit_depth);
			vector<bool> negative_nine_in_binary  { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 };
			vector<bool> negative_nine_revers     { 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0 };
			vector<bool> negative_nine_additional { 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1 };
			vector<bool> negative_twenty_two_in_binary    { 0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0 };
			vector<bool> negative_twenty_two_in_reverse   { 1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1 };
			vector<bool> negative_twenty_two_in_additional{ 1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0 };
			Assert::IsTrue(x3.get_numbr() == -9 && x4.get_numbr() == -22);
			Assert::IsTrue(x3.get_direct_vector() == negative_nine_in_binary && x3.get_backward_vector() == negative_nine_revers && x3.get_additional_vector() == negative_nine_additional, L"cheking -9");
			Assert::IsTrue(x4.get_direct_vector() == negative_twenty_two_in_binary && x4.get_backward_vector() == negative_twenty_two_in_reverse && x4.get_additional_vector() == negative_twenty_two_in_additional);
			
		}

		TEST_METHOD(TestMethod3)//test operation +
		{
			Numbers x1(10, bit_depth), x2(15, bit_depth), x3(-12, bit_depth), x4(-14, bit_depth);
			x1 + x2;                             
			vector<bool> ressult_summation_direct   { 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward { 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal{ 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x1.get_result_direct_vector() == ressult_summation_direct && x1.get_result_backward_vector() == ressult_summation_backward && x1.get_result_additional_vector() == ressult_summation_additonal);
			x2 + x3;
			vector<bool> ressult_summation_direct1   { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward1 { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal1{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x2.get_result_direct_vector() == ressult_summation_direct1 && x2.get_result_backward_vector() == ressult_summation_backward1 && x2.get_result_additional_vector() == ressult_summation_additonal1);
			x3 + x4;
			vector<bool> ressult_summation_direct2   { 0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward2 { 1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1 };
			vector<bool> ressult_summation_additonal2{ 0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x3.get_result_direct_vector() == ressult_summation_direct2 && x3.get_result_backward_vector() == ressult_summation_backward2 && x3.get_result_additional_vector() == ressult_summation_additonal2);
			x4 + x1;
			vector<bool> ressult_summation_direct3   { 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward3 { 1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1};
			vector<bool> ressult_summation_additonal3{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x4.get_result_direct_vector() == ressult_summation_direct3 && x4.get_result_backward_vector() == ressult_summation_backward3 && x4.get_result_additional_vector() == ressult_summation_additonal3);
		
		}

		TEST_METHOD(TestMethod4)//test operation +
		{
			Numbers x1(10, bit_depth), x2(15, bit_depth), x3(-12, bit_depth), x4(-14, bit_depth);
			x1 + x2;
			vector<bool> ressult_summation_direct{ 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward{ 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal{ 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x1.get_result_direct_vector() == ressult_summation_direct && x1.get_result_backward_vector() == ressult_summation_backward && x1.get_result_additional_vector() == ressult_summation_additonal);
			x2 + x3;
			vector<bool> ressult_summation_direct1{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward1{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal1{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x2.get_result_direct_vector() == ressult_summation_direct1 && x2.get_result_backward_vector() == ressult_summation_backward1 && x2.get_result_additional_vector() == ressult_summation_additonal1);
			x3 + x4;
			vector<bool> ressult_summation_direct2{ 0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward2{ 1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1 };
			vector<bool> ressult_summation_additonal2{ 0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x3.get_result_direct_vector() == ressult_summation_direct2 && x3.get_result_backward_vector() == ressult_summation_backward2 && x3.get_result_additional_vector() == ressult_summation_additonal2);
			x4 + x1;
			vector<bool> ressult_summation_direct3{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward3{ 1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			vector<bool> ressult_summation_additonal3{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x4.get_result_direct_vector() == ressult_summation_direct3 && x4.get_result_backward_vector() == ressult_summation_backward3 && x4.get_result_additional_vector() == ressult_summation_additonal3);

		}

		TEST_METHOD(TestMethod5)//test operation +
		{
			Numbers x1(5, bit_depth), x2(10, bit_depth), x3(-5, bit_depth), x4(-10, bit_depth);
			x1 + x2;
			vector<bool> ressult_summation_direct   { 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward { 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x1.get_result_direct_vector() == ressult_summation_direct && x1.get_result_backward_vector() == ressult_summation_backward && x1.get_result_additional_vector() == ressult_summation_additonal);
			x2 + x3;
			vector<bool> ressult_summation_direct1   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward1 { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			vector<bool> ressult_summation_additonal1{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(x2.get_result_direct_vector() == ressult_summation_direct1 && x2.get_result_backward_vector() == ressult_summation_backward1 && x2.get_result_additional_vector() == ressult_summation_additonal1);
			x3 + x4;
			vector<bool> ressult_summation_direct2   { 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward2 { 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 };
			vector<bool> ressult_summation_additonal2{ 1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x3.get_result_direct_vector() == ressult_summation_direct2 && x3.get_result_backward_vector() == ressult_summation_backward2 && x3.get_result_additional_vector() == ressult_summation_additonal2);
			x4 + x1;
			vector<bool> ressult_summation_direct3   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };//reverse code 'case i so represent
			vector<bool> ressult_summation_backward3 { 0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			vector<bool> ressult_summation_additonal3{ 1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			Assert::IsTrue(x4.get_result_direct_vector() == ressult_summation_direct3 && x4.get_result_backward_vector() == ressult_summation_backward3 && x4.get_result_additional_vector() == ressult_summation_additonal3);
		}

		TEST_METHOD(TestMethod6)//test operation *
		{
			Numbers x1(14, bit_depth), x2(11, bit_depth), x3(-14, bit_depth), x4(-11, bit_depth);
			x2 * x3;
			deque<bool> ressult_summation_direct   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward { 1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1 };
			deque<bool> ressult_summation_additonal{ 1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0 };
			Assert::IsTrue(x2.get_result_direct_multiplication_vector() == ressult_summation_direct && x2.get_result_backward_multiplication_vector() == ressult_summation_backward && x2.get_result_additional_multiplication_vector() == ressult_summation_additonal);
			x1 * x2;
			deque<bool> ressult_summation_direct1   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward1 { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_additonal1{ 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			Assert::IsTrue(x1.get_result_direct_multiplication_vector() == ressult_summation_direct1 && x1.get_result_backward_multiplication_vector() == ressult_summation_backward1 && x1.get_result_additional_multiplication_vector() == ressult_summation_additonal1);
			x3 * x4;
			deque<bool> ressult_summation_direct2   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward2 { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_additonal2{ 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			Assert::IsTrue(x3.get_result_direct_multiplication_vector() == ressult_summation_direct2 && x3.get_result_backward_multiplication_vector() == ressult_summation_backward2 && x3.get_result_additional_multiplication_vector() == ressult_summation_additonal2);
			x4 * x1;
			deque<bool> ressult_summation_direct3   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward3 { 1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1 };
			deque<bool> ressult_summation_additonal3{ 1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0 };
			Assert::IsTrue(x4.get_result_direct_multiplication_vector() == ressult_summation_direct3 && x4.get_result_backward_multiplication_vector() == ressult_summation_backward3 && x4.get_result_additional_multiplication_vector() == ressult_summation_additonal3);
		}

		TEST_METHOD(TestMethod7)//test operation *
		{
			Numbers x1(14, bit_depth), x2(11, bit_depth), x3(-14, bit_depth), x4(-11, bit_depth);
			x1 * x2;
			deque<bool> ressult_summation_direct   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_additonal{ 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			Assert::IsTrue(x1.get_result_direct_multiplication_vector() == ressult_summation_direct && x1.get_result_backward_multiplication_vector() == ressult_summation_backward && x1.get_result_additional_multiplication_vector() == ressult_summation_additonal);
			x2 * x3;
			deque<bool> ressult_summation_direct1   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward1 { 1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1 };
			deque<bool> ressult_summation_additonal1{ 1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0 };
			Assert::IsTrue(x2.get_result_direct_multiplication_vector() == ressult_summation_direct1 && x2.get_result_backward_multiplication_vector() == ressult_summation_backward1 && x2.get_result_additional_multiplication_vector() == ressult_summation_additonal1);
			x3 * x4;
			deque<bool> ressult_summation_direct2   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward2 { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_additonal2{ 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			Assert::IsTrue(x3.get_result_direct_multiplication_vector() == ressult_summation_direct2 && x3.get_result_backward_multiplication_vector() == ressult_summation_backward2 && x3.get_result_additional_multiplication_vector() == ressult_summation_additonal2);
			x4 * x1;
			deque<bool> ressult_summation_direct3   { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0 };
			deque<bool> ressult_summation_backward3 { 1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1 };
			deque<bool> ressult_summation_additonal3{ 1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0 };
			Assert::IsTrue(x4.get_result_direct_multiplication_vector() == ressult_summation_direct3 && x4.get_result_backward_multiplication_vector() == ressult_summation_backward3 && x4.get_result_additional_multiplication_vector() == ressult_summation_additonal3);
		}

		TEST_METHOD(TestMethod8)//test operation *
		{
			Numbers x1(17, bit_depth), x2(23, bit_depth), x3(-17, bit_depth), x4(-23, bit_depth);
			x1 * x2;
			deque<bool> ressult_summation_direct  { 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_backward{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_additonal{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			Assert::IsTrue(x1.get_result_direct_multiplication_vector() == ressult_summation_direct && x1.get_result_backward_multiplication_vector() == ressult_summation_backward && x1.get_result_additional_multiplication_vector() == ressult_summation_additonal);
			x2 * x3;
			deque<bool> ressult_summation_direct1  { 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_backward1{ 1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0 };
			deque<bool> ressult_summation_additonal1{ 1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1 };
			Assert::IsTrue(x2.get_result_direct_multiplication_vector() == ressult_summation_direct1 && x2.get_result_backward_multiplication_vector() == ressult_summation_backward1 && x2.get_result_additional_multiplication_vector() == ressult_summation_additonal1);
			x3 * x4;
			deque<bool> ressult_summation_direct2{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_backward2{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_additonal2{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			Assert::IsTrue(x3.get_result_direct_multiplication_vector() == ressult_summation_direct2 && x3.get_result_backward_multiplication_vector() == ressult_summation_backward2 && x3.get_result_additional_multiplication_vector() == ressult_summation_additonal2);
			x4 * x1;
			deque<bool> ressult_summation_direct3{ 0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1 };
			deque<bool> ressult_summation_backward3{ 1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0 };
			deque<bool> ressult_summation_additonal3{ 1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1 };
			Assert::IsTrue(x4.get_result_direct_multiplication_vector() == ressult_summation_direct3 && x4.get_result_backward_multiplication_vector() == ressult_summation_backward3 && x4.get_result_additional_multiplication_vector() == ressult_summation_additonal3);
		}

		TEST_METHOD(TestMethod9)//test operation /
		{
			Numbers x1(20, bit_depth), x2(10, bit_depth);
			deque<bool> result_deviding{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 };
			x1 / x2;
			Assert::IsTrue(x1.get_result_direct_deviding_vector() == result_deviding);
			Numbers x3(200, bit_depth), x4(10, bit_depth);
			deque<bool> result_deviding1{ 0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0 };
			x3 / x4;
			Assert::IsTrue(x3.get_result_direct_deviding_vector() == result_deviding1);
			Numbers x5(22, bit_depth), x6(9, bit_depth);
			deque<bool> result_deviding2{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 };
			deque<bool> result_deviding3{ 0,1,0,0,0 };
			x5 / x6;
			Assert::IsTrue(x5.get_result_direct_deviding_vector() == result_deviding2 && x5.get_result_direct_deviding_vector_FP()== result_deviding3);
			Numbers x7(9, bit_depth), x8(22, bit_depth);
			deque<bool> result_deviding4{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			deque<bool> result_deviding5{ 0,1,0,0,0 };
			x7 / x8;
			Assert::IsTrue(x7.get_result_direct_deviding_vector() == result_deviding4 && x7.get_result_direct_deviding_vector_FP() == result_deviding5);
		}

		TEST_METHOD(TestMethod10)//test operation +float
		{
			Numbers x1(10, bit_depth), x2(20, bit_depth);
			x1.summation_two_float_numbers(x2);
			deque<bool> result_FP{ 1,1,1,1,0 };
			Assert::IsTrue(x1.get_result_summation_FP()==result_FP && x1.Get_deqree_numbers()==5);
		}


	};
}
