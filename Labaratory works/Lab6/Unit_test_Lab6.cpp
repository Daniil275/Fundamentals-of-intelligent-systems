#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Visual c++\Aois_Lab6\Aois_Lab6\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6
{
	TEST_CLASS(UnitTest6)
	{
	public:
		
		TEST_METHOD(TestMethod1)//testing search and add
		{
			Dictionary example;
			example.add_info("Vlad", "02824924235");
			example.add_info("Liza", "23239502151616");
			example.add_info("Mariya", "237923516163");
			example.add_info("Mike", "389239161635");
			example.add_info("kolya", "389239136136325");
			example.add_info("Julia", "383339262624635");
			example.add_info("Tod", "34563926212135");
			example.add_info("Kostya", "789212473574573935");
			example.add_info("Daniil", "589262642723935");
			example.add_info("Vladimir", "362272826221923935");
			bool exmp1 = example.print_search_info("Vlad");
			bool exmp2 = example.print_search_info("Liza");
			bool exmp3 = example.print_search_info("Mariya");
			bool exmp4 = example.print_search_info("Mike");
			bool exmp5 = example.print_search_info("kolya");
			bool exmp6 = example.print_search_info("Julia");
			bool exmp7 = example.print_search_info("Tod");
			bool exmp8 = example.print_search_info("Kostya");
			bool exmp9 = example.print_search_info("Daniil");
			bool exmp10 = example.print_search_info("Vladimir");
			Assert::IsTrue(exmp1 && exmp2 && exmp3 && exmp4 && exmp5 && exmp6 && exmp7 && exmp8 && exmp9 && exmp10);

		}
		TEST_METHOD(TestMethod2)//test add - delete
		{
			Dictionary example;
			for (size_t i = 0; i < 15; i++)
			{
				example.add_info("ajfjojfoajdofjsfsjdfiosjiofd" + i, "028249" + i );
			}
			for (size_t i = 0; i < 15; i++)
			{
				example.del_info("ajfjojfoajdofjsfsjdfiosjiofd" + i);
			}

			Assert::IsTrue(example.getTable().size() == 0);

		}
		TEST_METHOD(TestMethod3) // testing exeptions
		{
			Dictionary example;
			for (size_t i = 0; i < 10; i++)
			{
				example.add_info("�����" + i, "02824924" + i);
			}

			Assert::IsTrue( example.getTable().size() == 0);

			for (size_t i = 0; i < 10; i++)
			{
				example.add_info("�����", "02824924");
			}
			Assert::IsTrue( example.getTable().size() == 0);

			example.add_info("Mike",  "028256924");
			example.add_info("Mike",  "028249247");
			Assert::IsTrue(example.getTable().size() == 1);
			
		}
		TEST_METHOD(TestMethod4)//test collisions
		{
			Dictionary example;
			example.add_info("Vlad", "02824924235");
			example.add_info("Liza", "23239502151616");
			example.add_info("Mariya", "237923516163");
			example.add_info("Mike", "389239161635");
			example.add_info("kolya", "389239136136325");
			example.add_info("Julia", "383339262624635");
			example.add_info("Tod", "34563926212135");
			example.add_info("Kostya", "789212473574573935");
			example.add_info("Daniil", "589262642723935");
			example.add_info("Vladimir", "362272826221923935");
			Assert::IsTrue( example.getTable().size() == 10);
		}

		TEST_METHOD(TestMethod5)//all test
		{
			Dictionary example;
			example.add_info("Vladislav", "0203246824924");
			example.add_info("Azamat", "23239502");
			example.add_info("Mariya", "33792353");
			example.add_info("Mike", "48923935");
			example.add_info("Tasya", "68923925");
			example.add_info("Julia", "78333935");
			example.add_info("Tod", "84563935");
			example.add_info("Karl", "18923935");
			example.add_info("John", "38923935");
			example.add_info("Rouse", "38523935");
			bool exmp1 = example.print_search_info("Vladislav");
			bool exmp2 = example.print_search_info("Azamat");
			bool exmp3 = example.print_search_info("Mariya");
			bool exmp4 = example.print_search_info("Tasya");
			bool exmp5 = example.print_search_info("Mike");
			bool exmp6 = example.print_search_info("Julia");
			bool exmp7 = example.print_search_info("Tod");
			bool exmp8 = example.print_search_info("Karl");
			bool exmp9 = example.print_search_info("John");
			bool exmp10 = example.print_search_info("Rouse");
			Assert::IsTrue(exmp1 && exmp2 && exmp3 && exmp4 && exmp5 && exmp6 && exmp7 && exmp8 && exmp9 && exmp10);
			example.del_info("Vladislav");
			example.del_info("Azamat");
			example.del_info("Mariya");
			example.del_info("Tasya");
			example.del_info("Mike");
			example.del_info("Julia");
			example.del_info("Tod");
			example.del_info("Karl");
			example.del_info("John");
			example.del_info("Rouse");
			Assert::IsTrue( example.getTable().size() == 0);
			example.add_info("Vladislav", "0203246824924");
			example.add_info("Vladislav", "0203246824924");
			example.add_info("Vladislav", "0203246824924");
			example.add_info("Vladislav", "0203246824924");
			Assert::IsTrue(example.getTable().size() == 1);

		}
	};
}
