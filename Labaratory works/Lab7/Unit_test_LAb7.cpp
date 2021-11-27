#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Visual c++\Aois_LAb7\Aois_LAb7\Source.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab7
{
	TEST_CLASS(UnitTestLab7)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word;
			for (size_t i = 0; i < 8; i++)
			{
				if (book[5][i] == 1) word += "1";
				else word += "0";
			}
			bool find = false;
			for (size_t i = 0; i < number_of_words; i++)
			{
				Result_find temp = recursive_find(word, book[i], 0);
				if (temp.trigger_left == 0 && temp.trigger_right == 0) find = true;
			}
			Assert::IsTrue(find);
		}
		TEST_METHOD(TestMethod2)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word;
			for (size_t i = 0; i < 8; i++)
			{
				if (book[7][i] == 1) word += "1";
				else word += "0";
			}
			bool find = false;
			for (size_t i = 0; i < number_of_words; i++)
			{
				Result_find temp = recursive_find(word, book[i], 0);
				if (temp.trigger_left == 0 && temp.trigger_right == 0) find = true;
			}
			Assert::IsTrue(find);
		}
		TEST_METHOD(TestMethod3)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word;
			for (size_t i = 0; i < 8; i++)
			{
				if (book[10][i] == 1) word += "1";
				else word += "0";
			}
			bool find = false;
			for (size_t i = 0; i < number_of_words; i++)
			{
				Result_find temp = recursive_find(word, book[i], 0);
				if (temp.trigger_left == 0 && temp.trigger_right == 0) find = true;
			}
			Assert::IsTrue(find);
		}
		TEST_METHOD(TestMethod4)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word;
			for (size_t i = 0; i < 8; i++)
			{
				if (book[14][i] == 1) word += "1";
				else word += "0";
			}
			bool find = false;
			for (size_t i = 0; i < number_of_words; i++)
			{
				Result_find temp = recursive_find(word, book[i], 0);
				if (temp.trigger_left == 0 && temp.trigger_right == 0) find = true;
			}
			Assert::IsTrue(find);
		}

		TEST_METHOD(TestMethod5)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word;
			for (size_t i = 0; i < 8; i++)
			{
				if (book[18][i] == 1) word += "1";
				else word += "0";
			}
			bool find = false;
			for (size_t i = 0; i < number_of_words; i++)
			{
				Result_find temp = recursive_find(word, book[i], 0);
				if (temp.trigger_left == 0 && temp.trigger_right == 0) find = true;
			}
			Assert::IsTrue(find);
		}

		TEST_METHOD(TestMethod6)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word{ "01001001" };
			string max = nearest(book, book[3]);
			Assert::IsTrue(max == word);
		}

		TEST_METHOD(TestMethod7)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word{ "10010011" };
			string max = nearest(book, book[6]);
			Assert::IsTrue(max == word);
		}

		TEST_METHOD(TestMethod8)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word{ "11100001" };
			string max = nearest(book, book[10]);
			Assert::IsTrue(max == word);
		}

		TEST_METHOD(TestMethod9)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word{ "01111011" };
			string max = nearest(book, book[15]);
			Assert::IsTrue(max == word);
		}

		TEST_METHOD(TestMethod10)
		{
			vector<vector<bool>> book;
			int number_of_words = 30;
			for (size_t i = 0; i < number_of_words; i++)
			{
				vector<bool> boof = get_random_word();
				book.push_back(boof);
			}
			string word{ "10111011" };
			string max = nearest(book, book[14]);
			Assert::IsTrue(max == word);
		}
	};
}
