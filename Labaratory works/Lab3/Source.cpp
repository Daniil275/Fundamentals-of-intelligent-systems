#include <iostream>
#include <deque>
#include <string>
using namespace std;
#define endl cout << "\n";

class Logic_function
{
public:
	void print_array(const bool(&Array)[5][16])
	{
		for (int i = 0; i < bit_depth + 1; i++)
		{
			if (i == bit_depth) cout << "Fi: ";
			else cout << "X" << i + 1 << ": ";


			for (int j = 0; j < numbr_of_column; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
	}

	void print_array_minimization(const char(&Array)[15][3])
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
		endl

	}

	void print_array_check(const int(&Array)[3][4])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
		endl
	}

	void print_array_check1(const int(&Array)[1][4])
	{
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
		endl
	}

	static void print_deque(const deque<char>& dq)
	{
		for (auto i : dq)
		{
			cout << i;
		}
		endl
	}

	void analysis_input(const deque<int>& function, bool second_task, int numbr)
	{
		SDNF_rez = "";
		SKNF_rez = "";
		deque<bool> container;
		int j = -1, num = 0, count = 0;
		bool num_have_in_column = false;
		status_of_calls = false;
		container.clear();
		int default_column_size = 16, default_strings_size = 5;
		for (int i = 0; i < default_strings_size; i++)
		{
			for (int j = 0; j < default_column_size; j++)
			{
				spreadsheet_truth[i][j] = false;
			}
		}


		if (second_task)
		{
			int position = 8;
			numbr_of_column = 8;
			bit_depth = 3;
			while (numbr >= 1)  //convert max number to know how many colmn and sityations
			{
				position--;
				if (numbr % 2 == 1) count++;
				spreadsheet_truth[3][position] = (numbr % 2);
				numbr /= 2;

			}

		}

		else
		{
			int max_num = 0;
			for (auto i : function)
			{
				if (max_num < i) max_num = i;
			}


			while (max_num >= 1)
			{
				bit_depth++;                     //convert max number to know how many colmn and sityations
				max_num /= 2;
			}
			numbr_of_column = pow(2, bit_depth);
		}



		for (int i = 0; i < numbr_of_column; i++)
		{
			j++;
			num_have_in_column = false;
			num = i;

			if (!second_task)
			{
				for (int q = 0; q < function.size(); q++)
				{
					if (function[q] == num) num_have_in_column = true;
				}
			}

			while (num >= 1)
			{
				container.push_front(num % 2);
				num /= 2;
			}

			if (container.size() < bit_depth)
			{
				while (container.size() != bit_depth)
				{
					container.push_front(0);
				}
			}

			for (int s = 0; s < bit_depth; s++)
			{
				spreadsheet_truth[s][j] = container[s];
				if (num_have_in_column) spreadsheet_truth[bit_depth][j] = true;
			}
			container.clear();
		}
		if (check_mass) print_array(spreadsheet_truth);
		endl
			SDNF_and_SKNF();
		endl
			calculation_method(SDNF_rez);
		status_of_calls = true;
		
		calculation_method(SKNF_rez);
		endl
		minimization_method_Cvain_Mak_Klasski();

	}

	void analysis_input_logical_form(deque<char>& logical_fucntion)
	{
		int X = 0, Y = 0, Z = 0, num_i = 0;
		deque<char> preparing_function;
		bool reverse = false;
		SDNF_rez = "";
		SKNF_rez = "";
		deque<bool> container, container_result;
		int j = -1, num = 0, count = 0;
		bool num_1_in_column = false, note_reversive = false;
		container.clear();
		int number_of_brackets = 0;
		preparing_function.clear();
		numbr_of_column = 8;
		bit_depth = 3;
		int default_column_size = 16, default_strings_size = 5;
		int bit_size_container = 8;
		status_of_calls = false;

		for (int i = 0; i < logical_fucntion.size(); i++)
		{

			if (logical_fucntion[i] == '!' && logical_fucntion[i + 1] == '(')
			{

				for (int j = i; j < logical_fucntion.size(); j++)
				{
					if (logical_fucntion[j] == '!' && logical_fucntion[j + 1] == '(' && j != 0 && logical_fucntion[0] == '!' && logical_fucntion[1] == '(')
					{
						number_of_brackets++;
						preparing_function.push_back(logical_fucntion[j + 2]);
						preparing_function.push_back(logical_fucntion[j + 3]);
						preparing_function.push_back(logical_fucntion[j + 4]);
						j += 4;
					}
					else if (logical_fucntion[j] == '(') number_of_brackets++;
					else if (logical_fucntion[j] == '!' && (logical_fucntion[j + 1] == 'X' || logical_fucntion[j + 1] == 'Y' || logical_fucntion[j + 1] == 'Z')) preparing_function.push_back(logical_fucntion[j]);
					else if (logical_fucntion[j] == 'X' || logical_fucntion[j] == 'Y' || logical_fucntion[j] == 'Z')
					{
						if (logical_fucntion[j] == 'X') preparing_function.push_back('R');
						else if (logical_fucntion[j] == 'Y') preparing_function.push_back('F');
						else preparing_function.push_back('L');
					}
					else if (logical_fucntion[j] == '+') preparing_function.push_back('*');
					else if (logical_fucntion[j] == '*') preparing_function.push_back('+');
					if (logical_fucntion[j] == ')' && number_of_brackets == 0)
					{
						count = j;
						break;
					}
					else if (logical_fucntion[j + 1] == ')') number_of_brackets--;

				}
				i = count;//break;
			}

			else if (logical_fucntion[i] == '(')
			{
				for (int j = i; j < logical_fucntion.size(); j++)
				{
					if (logical_fucntion[j] == '(') number_of_brackets++;
					else if (logical_fucntion[j] == '!' && (logical_fucntion[j + 1] == 'X' || logical_fucntion[j + 1] == 'Y' || logical_fucntion[j + 1] == 'Z'))
					{
						if (logical_fucntion[j + 1] == 'X') preparing_function.push_back('R');
						else if (logical_fucntion[j + 1] == 'Y') preparing_function.push_back('F');
						else preparing_function.push_back('L');
						j += 1;
					}
					else if (logical_fucntion[j] == 'X' || logical_fucntion[j] == 'Y' || logical_fucntion[j] == 'Z') preparing_function.push_back(logical_fucntion[j]);
					else if (logical_fucntion[j] == '+' || logical_fucntion[j] == '*') preparing_function.push_back(logical_fucntion[j]);
					if (logical_fucntion[j] == ')' && number_of_brackets == 0)
					{
						count = j;
						break;
					}
					else if (logical_fucntion[j + 1] == ')') number_of_brackets--;
				}
				i = count;//break;
			}

			else if (logical_fucntion[i] == '!')
			{
				if (logical_fucntion[i] == '!' && (logical_fucntion[i + 1] == 'X' || logical_fucntion[i + 1] == 'Y' || logical_fucntion[i + 1] == 'Z'))
				{
					if (logical_fucntion[i + 1] == 'X') preparing_function.push_back('R');
					else if (logical_fucntion[i + 1] == 'Y') preparing_function.push_back('F');
					else preparing_function.push_back('L');
					i += 1;
				}

			}
			else preparing_function.push_back(logical_fucntion[i]);
		}

		if(check) print_deque(preparing_function);

		for (int i = 0; i < default_strings_size; i++)
		{
			for (int j = 0; j < default_column_size; j++)
			{
				spreadsheet_truth[i][j] = false;
			}
		}

		for (int i = 0; i < numbr_of_column; i++)
		{
			j++;

			num = i;

			while (num >= 1)
			{
				container.push_front(num % 2);
				num /= 2;
			}

			if (container.size() < bit_depth)
			{
				while (container.size() != bit_depth)
				{
					container.push_front(0);
				}
			}

			for (int s = 0; s < bit_depth; s++)
			{
				spreadsheet_truth[s][j] = container[s];

			}
			container.clear();
		}


		container_result = processing(preparing_function);
		for (int i = 0; i < bit_size_container; i++)
		{
			if (container_result[i] == 1) num_i += pow(2, 8 - (i + 1));
			spreadsheet_truth[bit_depth][i] = container_result[i];

		}

		if (check_mass) print_array(spreadsheet_truth);

			endl
			SDNF_and_SKNF();
		calculation_method(SDNF_rez);
		status_of_calls = true;
			calculation_method(SKNF_rez);
		endl
			minimization_method_Cvain_Mak_Klasski();
		endl
			cout << "Index = " << num_i;
		endl
	}

	void minimization_method_Cvain_Mak_Klasski() // !(X+Y)+!Z#   //in develop
	{
		const int static num_strings_for_no_one_true = 1, num_column_for_one_true = 3, num_columns = 4, num_column_for_firstX = 3, num_strings_for_firstX = 15;
		int no_one_true[num_strings_for_no_one_true][num_columns], one_in_true[num_column_for_one_true][num_columns], two_in_true[num_column_for_one_true][num_columns], tree_in_true[num_strings_for_no_one_true][num_columns], trigger_for_c = false, trigger_for_s = false;
		char firstX[num_strings_for_firstX][num_column_for_firstX];
		bool stringUp = false, stringUp1 = false, stringUp2 = false;

		for (int i = 0; i < num_column_for_one_true; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				if (i < 1)
				{
					no_one_true[i][j] = 0;
					tree_in_true[i][j] = 0;
				}
				one_in_true[i][j] = 0;
				two_in_true[i][j] = 0;
			}
		}

		for (int i = 0; i < num_strings_for_firstX; i++)
		{
			for (int j = 0; j < num_column_for_firstX; j++)
			{
				firstX[i][j] = ' ';
			}
		}

		int number_of_input = 0;
		int s = 0, c = 0;
		for (int i = 0; i < numbr_of_column; i++)
		{
			number_of_input = 0;
			if (spreadsheet_truth[3][i])
			{

				for (int j = 0; j < bit_depth; j++)
				{
					if (spreadsheet_truth[j][i]) number_of_input++;

				}
				trigger_for_c = false;
				trigger_for_s = false;

				for (int j = 0; j < this->bit_depth; j++)
				{

					if (number_of_input == 0)
					{
						no_one_true[0][j + 1] = spreadsheet_truth[j][i];
						no_one_true[0][0] = number_of_input + 9;
					}
					else if (number_of_input == 1)
					{
						one_in_true[s][j + 1] = spreadsheet_truth[j][i];
						trigger_for_s = true;
						one_in_true[s][0] = number_of_input;
					}
					else if (number_of_input == 2)
					{
						two_in_true[c][j + 1] = spreadsheet_truth[j][i];
						trigger_for_c = true;
						two_in_true[c][0] = number_of_input;
					}
					else if (number_of_input == 3)
					{
						tree_in_true[0][j + 1] = spreadsheet_truth[j][i];
						tree_in_true[0][0] = number_of_input;
					}

				}
				if (trigger_for_s) s++;
				if (trigger_for_c) c++;
			}
		}

		print_array_check1(no_one_true);
		print_array_check(one_in_true);
		print_array_check(two_in_true);
		print_array_check1(tree_in_true);
		int mut = 0, mut1 = 0, mut2 = 0, str = 0;


		mut = 0;
		mut1 = 0;
		mut2 = 0;

		stringUp = false;
		stringUp1 = false;
		stringUp2 = false;

		for (int j = 1; j < num_columns; j++)  //пропускаем число вхождений
		{

			if ((no_one_true[0][j] == 0 && one_in_true[0][j] == 1 || no_one_true[0][j] == 1 && one_in_true[0][j] == 0) && one_in_true[0][0] == 1 && no_one_true[0][0] == 9) mut++;
			if ((no_one_true[0][j] == 0 && one_in_true[1][j] == 1 || no_one_true[0][j] == 1 && one_in_true[1][j] == 0) && one_in_true[1][0] == 1 && no_one_true[0][0] == 9) mut1++;
			if ((no_one_true[0][j] == 0 && one_in_true[2][j] == 1 || no_one_true[0][j] == 1 && one_in_true[2][j] == 0) && one_in_true[2][0] == 1 && no_one_true[0][0] == 9) mut2++;
		}

		for (int q = 0; q < num_column_for_one_true; q++)  //пропускаем число вхождений
		{
			if (mut == 1)
			{
				if (no_one_true[0][q + 1]) firstX[str][q] += '1';
				else firstX[str][q] += '0';
				stringUp = true;
			}

			if (mut == 1 && (no_one_true[0][q + 1] == 0 && one_in_true[0][q + 1] == 1 || no_one_true[0][q + 1] == 1 && one_in_true[0][q + 1] == 0))
			{
				firstX[str][q] += 'X';
			}

			if (mut1 == 1)
			{
				if (no_one_true[0][q + 1]) firstX[str + 1][q] = '1';
				else firstX[str + 1][q] += '0';
				stringUp1 = true;
			}

			if (mut1 == 1 && (no_one_true[0][q + 1] == 1 && one_in_true[1][q + 1] == 0 || no_one_true[0][q + 1] == 0 && one_in_true[1][q + 1] == 1))
			{
				firstX[str + 1][q] += 'X';
			}

			if (mut2 == 1)
			{
				if (no_one_true[0][q + 1]) firstX[str + 2][q] = '1';
				else firstX[str + 2][q] += '0';
				stringUp2 = true;
			}

			if (mut2 == 1 && (no_one_true[0][q + 1] == 0 && one_in_true[2][q + 1] == 1 || no_one_true[0][q + 1] == 1 && one_in_true[2][q + 1] == 0))
			{
				firstX[str + 2][q] += 'X';
			}

		}

		if (stringUp || stringUp1 || stringUp2)
		{
			str += (int)stringUp + (int)stringUp1 + (int)stringUp2;
		}


		//using x___  _x___
		//сранвивем 2 массива определяем __X_ и т.д надо подумать
		str++;
		for (int i = 0; i < num_column_for_one_true; i++) //сравниваю слеива.тбся ли только смежные т.е 1-1 2-2 но не промежуточные надо пофиксить
		{
			mut = 0;
			mut1 = 0;
			mut2 = 0;

			stringUp = false;
			stringUp1 = false;
			stringUp2 = false;

			for (int j = 1; j < num_columns; j++)  //пропускаем число вхождений
			{

				if ((one_in_true[i][j] == 0 && two_in_true[0][j] == 1 || one_in_true[i][j] == 1 && two_in_true[0][j] == 0) && one_in_true[0][0] == 1 && two_in_true[0][0] == 2) mut++;
				if ((one_in_true[i][j] == 0 && two_in_true[1][j] == 1 || one_in_true[i][j] == 1 && two_in_true[1][j] == 0) && one_in_true[1][0] == 1 && two_in_true[1][0] == 2) mut1++;
				if ((one_in_true[i][j] == 0 && two_in_true[2][j] == 1 || one_in_true[i][j] == 1 && two_in_true[2][j] == 0) && one_in_true[2][0] == 1 && two_in_true[2][0] == 2) mut2++;
			}

			for (int q = 0; q < num_column_for_one_true; q++)  //пропускаем число вхождений
			{
				if (mut == 1)
				{
					if (one_in_true[i][q + 1]) firstX[str][q] = '1';
					else firstX[str][q] = '0';
					stringUp = true;
				}

				if (mut == 1 && (one_in_true[i][q + 1] == 0 && two_in_true[0][q + 1] == 1 || mut == 1 && one_in_true[i][q + 1] == 1 && two_in_true[0][q + 1] == 0))
				{
					firstX[str][q] = 'X';
				}

				if (mut1 == 1)
				{
					if (one_in_true[i][q + 1]) firstX[str + 1][q] = '1';
					else firstX[str + 1][q] = '0';
					stringUp1 = true;
				}

				if (mut1 == 1 && (one_in_true[i][q + 1] == 1 && two_in_true[1][q + 1] == 0 || one_in_true[i][q + 1] == 0 && two_in_true[1][q + 1] == 1))
				{
					firstX[str + 1][q] = 'X';
				}

				if (mut2 == 1)
				{
					if (one_in_true[i][q + 1]) firstX[str + 2][q] = '1';
					else firstX[str + 2][q] = '0';
					stringUp2 = true;
				}

				if (mut2 == 1 && (one_in_true[i][q + 1] == 0 && two_in_true[2][q + 1] == 1 || one_in_true[i][q + 1] == 1 && two_in_true[2][q + 1] == 0))
				{
					firstX[str + 2][q] = 'X';
				}

			}
			if (stringUp || stringUp1 || stringUp2)
			{
				str += (int)stringUp + (int)stringUp1 + (int)stringUp2;
			}
		}
		// with 3 mass
		str++;
		mut = 0;
		mut1 = 0;
		mut2 = 0;

		stringUp = false;
		stringUp1 = false;
		stringUp2 = false;

		for (int j = 1; j < num_columns; j++)  //пропускаем число вхождений
		{

			if (((two_in_true[0][j] == 0 && tree_in_true[0][j] == 1 || two_in_true[0][j] == 1 && tree_in_true[0][j] == 0) && two_in_true[0][0] == 2 && tree_in_true[0][0] == 3)) mut++;
			if (((two_in_true[1][j] == 0 && tree_in_true[0][j] == 1 || two_in_true[1][j] == 1 && tree_in_true[0][j] == 0) && two_in_true[1][0] == 2 && tree_in_true[0][0] == 3)) mut1++;
			if (((two_in_true[2][j] == 0 && tree_in_true[0][j] == 1 || two_in_true[2][j] == 1 && tree_in_true[0][j] == 0) && two_in_true[2][0] == 2 && tree_in_true[0][0] == 3)) mut2++;
		}

		for (int q = 0; q < num_column_for_one_true; q++)  //пропускаем число вхождений
		{
			if (mut == 1)
			{
				if (two_in_true[0][q + 1]) firstX[str][q] = '1';
				else firstX[str][q] = '0';
				stringUp = true;
			}

			if (mut == 1 && (two_in_true[0][q + 1] == 0 && tree_in_true[0][q + 1] == 1 || two_in_true[0][q + 1] == 1 && tree_in_true[0][q + 1] == 0))
			{
				firstX[str][q] = 'X';
			}

			if (mut1 == 1)
			{
				if (two_in_true[1][q + 1]) firstX[str + 1][q] = '1';
				else firstX[str + 1][q] = '0';
				stringUp1 = true;
			}

			if (mut1 == 1 && (two_in_true[1][q + 1] == 0 && tree_in_true[0][q + 1] == 1 || two_in_true[1][q + 1] == 1 && tree_in_true[0][q + 1] == 0))
			{
				firstX[str + 1][q] = 'X';
			}

			if (mut2 == 1)
			{
				if (two_in_true[2][q + 1]) firstX[str + 2][q] = '1';
				else firstX[str + 2][q] = '0';
				stringUp2 = true;
			}

			if (mut2 == 1 && (two_in_true[2][q + 1] == 0 && tree_in_true[0][q + 1] == 1 || two_in_true[2][q + 1] == 1 && tree_in_true[0][q + 1] == 0))
			{
				firstX[str + 2][q] = 'X';
			}

		}

		endl
			print_array_minimization(firstX);
		//таблица покрытия

	}

	void map_Carno()////in develop
	{

	}

	void calculation_method(string SDNF_rezult)
	{
		//!X+!Y*!(X+Y+Z)#
		bool trigger_X_in = false, trigger_Y_in = false, trigger_Z_in = false;
		bool trigger_anti_X_in = false, trigger_anti_Y_in = false, trigger_anti_Z_in = false;

		int trigger_reverse_X = 0, trigger_reverse_Y = 0, trigger_reverse_Z = 0;
		int trigger_anti_X = 0, trigger_anti_Y = 0, trigger_anti_Z = 0;
		deque<char> result_minimization;
		for (int i = 0; i < SDNF_rezult.length(); i++)
		{
			if (SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '1' || SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '2' || SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '3' || SDNF_rezult[i] == '+' || SDNF_rezult[i] == '*' || SDNF_rezult[i] == '(' || SDNF_rezult[i] == ')')
			{
				if (SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '1')
				{
					trigger_reverse_X = i;
					result_minimization.push_back(SDNF_rezult[i]);
					result_minimization.push_back(SDNF_rezult[i + 1]);
					trigger_X_in = true;
					i++;
				}
				else if (SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '2')
				{
					trigger_reverse_Y = i;
					result_minimization.push_back(SDNF_rezult[i]);
					result_minimization.push_back(SDNF_rezult[i + 1]);
					trigger_Y_in = true;
					i++;
				}
				else if (SDNF_rezult[i] == 'X' && SDNF_rezult[i + 1] == '3')
				{
					trigger_reverse_Z = i;
					result_minimization.push_back(SDNF_rezult[i]);
					result_minimization.push_back(SDNF_rezult[i + 1]);
					trigger_Z_in = true;
					i++;
				}
				else
				{
					result_minimization.push_back(SDNF_rezult[i]);
					continue;
				}
			}


			if (SDNF_rezult[i] == ' ')
			{
				result_minimization.push_back(SDNF_rezult[i]);
				continue;
			}

			if (SDNF_rezult[i] == '!' && SDNF_rezult[i + 1] == 'X' && SDNF_rezult[i + 2] == '1')
			{
				result_minimization.push_back(SDNF_rezult[i]);
				result_minimization.push_back(SDNF_rezult[i + 1]);
				result_minimization.push_back(SDNF_rezult[i + 2]);
				trigger_anti_X = i;
				i += 2;
				trigger_anti_X_in = true;
			}
			else if (SDNF_rezult[i] == '!' && SDNF_rezult[i + 1] == 'X' && SDNF_rezult[i + 2] == '2')
			{
				result_minimization.push_back(SDNF_rezult[i]);
				result_minimization.push_back(SDNF_rezult[i + 1]);
				result_minimization.push_back(SDNF_rezult[i + 2]);
				trigger_anti_Y = i;
				i += 2;
				trigger_anti_Y_in = true;
			}
			else if (SDNF_rezult[i] == '!' && SDNF_rezult[i + 1] == 'X' && SDNF_rezult[i + 2] == '3')
			{
				result_minimization.push_back(SDNF_rezult[i]);
				result_minimization.push_back(SDNF_rezult[i + 1]);
				result_minimization.push_back(SDNF_rezult[i + 2]);
				trigger_anti_Z = i;
				i += 2;
				trigger_anti_Z_in = true;
			}

			if (trigger_reverse_X != 0 && trigger_X_in && trigger_anti_X_in) //стираем инвериторавние
			{
				result_minimization[trigger_anti_X] = 'O';
				result_minimization[trigger_anti_X + 1] = 'O';
				result_minimization[trigger_anti_X + 2] = 'O';
				result_minimization[trigger_reverse_X] = 'O';
				result_minimization[trigger_reverse_X + 1] = 'O';
				trigger_X_in = trigger_anti_X_in = false;

			}
			else if (trigger_reverse_Y != 0 && trigger_Y_in && trigger_anti_Y_in)
			{
				result_minimization[trigger_anti_Y] = 'O';
				result_minimization[trigger_anti_Y + 1] = 'O';
				result_minimization[trigger_anti_Y + 2] = 'O';
				result_minimization[trigger_reverse_Y] = 'O';
				result_minimization[trigger_reverse_Y + 1] = 'O';
				trigger_Y_in = trigger_anti_Y_in = false;
			}
			else if (trigger_reverse_Z != 0 && trigger_Z_in && trigger_anti_Z_in)
			{
				result_minimization[trigger_anti_Z] = 'O';
				result_minimization[trigger_anti_Z + 1] = 'O';
				result_minimization[trigger_anti_Z + 2] = 'O';
				result_minimization[trigger_reverse_Z] = 'O';
				result_minimization[trigger_reverse_Z + 1] = 'O';
				trigger_Z_in = trigger_anti_Z_in = false;

			}
		}
		if(check) print_deque(result_minimization);

		for (int i = 0; i < result_minimization.size(); i++)//deleting 0
		{
			if (!(status_of_calls) && (result_minimization[i] == 'O' || result_minimization[i] == '*' && !(result_minimization[i + 2] == '!' || result_minimization[i + 2] == 'X')))
			{
				result_minimization.erase(result_minimization.begin() + i);
				i--;
			}
			else if ((status_of_calls) && (result_minimization[i] == 'O' || result_minimization[i] == '+' && !(result_minimization[i + 2] == '!' || result_minimization[i + 2] == 'X')))
			{
				result_minimization.erase(result_minimization.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < result_minimization.size(); i++)//deleting " "
		{
			if (i == result_minimization.size() - 1) break;
			if (result_minimization[i] == ' ' && result_minimization[i + 1] == ' ' || result_minimization[i] == ' ' && result_minimization[i + 1] == ')')
			{
				result_minimization.erase(result_minimization.begin() + i);
				i--;
			}
			if (result_minimization[i] == '(' && result_minimization[i + 1] == ' ')
			{
				result_minimization.erase(result_minimization.begin() + i + 1);
				i--;
			}
		}

		if (check) print_deque(result_minimization);
		trigger_reverse_X = 0, trigger_reverse_Y = 0, trigger_reverse_Z = 0;
		trigger_anti_X = 0, trigger_anti_Y = 0, trigger_anti_Z = 0;

		for (int i = 0; i < result_minimization.size(); i++)//склеиваем одинаковые импликанты
		{
			if (result_minimization[i] == 'X' && result_minimization[i + 1] == '1') trigger_reverse_X++;
			else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '2') trigger_reverse_Y++;
			else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '3') trigger_reverse_Z++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '1') trigger_anti_X++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '2') trigger_anti_Y++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '3') trigger_anti_Z++;
		}

		function_processing(trigger_reverse_X, trigger_reverse_Y, trigger_reverse_Z, trigger_anti_X, trigger_anti_Y, trigger_anti_Z, result_minimization);
		if(status_of_calls) cout << "TKNF: " << TKNF << "\n";
		else cout << "TDNF: " << TDNF << "\n";
	}

	void function_processing(int num1, int num2, int num3, int num4, int num5, int num6, deque<char> result_minimization)
	{
		//!(X + Y) + !Z#

		bool trigger_X_in = false, trigger_Y_in = false, trigger_Z_in = false;
		bool trigger_anti_X_in = false, trigger_anti_Y_in = false, trigger_anti_Z_in = false;

		int trigger_reverse_X = 0, trigger_reverse_Y = 0, trigger_reverse_Z = 0;
		int trigger_anti_X = 0, trigger_anti_Y = 0, trigger_anti_Z = 0;
		deque<char> result_minimization1;
		for (int i = 0; i < result_minimization.size(); i++)
		{
			if (result_minimization[i] == 'X' && result_minimization[i + 1] == '1' || result_minimization[i] == 'X' && result_minimization[i + 1] == '2' || result_minimization[i] == 'X' && result_minimization[i + 1] == '3' || result_minimization[i] == '+' || result_minimization[i] == '*' || result_minimization[i] == '(' || result_minimization[i] == ')')
			{
				if (result_minimization[i] == 'X' && result_minimization[i + 1] == '1')
				{
					trigger_reverse_X = i;
					result_minimization1.push_back(result_minimization[i]);
					result_minimization1.push_back(result_minimization[i + 1]);
					trigger_X_in = true;
					i++;
				}
				else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '2')
				{
					trigger_reverse_Y = i;
					result_minimization1.push_back(result_minimization[i]);
					result_minimization1.push_back(result_minimization[i + 1]);
					trigger_Y_in = true;
					i++;
				}
				else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '3')
				{
					trigger_reverse_Z = i;
					result_minimization1.push_back(result_minimization[i]);
					result_minimization1.push_back(result_minimization[i + 1]);
					trigger_Z_in = true;
					i++;
				}
				else
				{
					result_minimization1.push_back(result_minimization[i]);
					continue;
				}
			}


			if (result_minimization[i] == ' ')
			{
				result_minimization1.push_back(result_minimization[i]);
				continue;
			}

			if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '1')
			{
				result_minimization1.push_back(result_minimization[i]);
				result_minimization1.push_back(result_minimization[i + 1]);
				result_minimization1.push_back(result_minimization[i + 2]);
				trigger_anti_X = i;
				i += 2;
				trigger_anti_X_in = true;
			}
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '2')
			{
				result_minimization1.push_back(result_minimization[i]);
				result_minimization1.push_back(result_minimization[i + 1]);
				result_minimization1.push_back(result_minimization[i + 2]);
				trigger_anti_Y = i;
				i += 2;
				trigger_anti_Y_in = true;
			}
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '3')
			{
				result_minimization1.push_back(result_minimization[i]);
				result_minimization1.push_back(result_minimization[i + 1]);
				result_minimization1.push_back(result_minimization[i + 2]);
				trigger_anti_Z = i;
				i += 2;
				trigger_anti_Z_in = true;
			}

			if (trigger_reverse_X != 0 && trigger_X_in && trigger_anti_X_in) //стираем инвериторавние
			{
				result_minimization1[trigger_anti_X] = 'O';
				result_minimization1[trigger_anti_X + 1] = 'O';
				result_minimization1[trigger_anti_X + 2] = 'O';
				result_minimization1[trigger_reverse_X] = 'O';
				result_minimization1[trigger_reverse_X + 1] = 'O';
				trigger_X_in = trigger_anti_X_in = false;

			}
			else if (trigger_reverse_Y != 0 && trigger_Y_in && trigger_anti_Y_in)
			{
				result_minimization1[trigger_anti_Y] = 'O';
				result_minimization1[trigger_anti_Y + 1] = 'O';
				result_minimization1[trigger_anti_Y + 2] = 'O';
				result_minimization1[trigger_reverse_Y] = 'O';
				result_minimization1[trigger_reverse_Y + 1] = 'O';
				trigger_Y_in = trigger_anti_Y_in = false;
			}
			else if (trigger_reverse_Z != 0 && trigger_Z_in && trigger_anti_Z_in)
			{
				result_minimization1[trigger_anti_Z] = 'O';
				result_minimization1[trigger_anti_Z + 1] = 'O';
				result_minimization1[trigger_anti_Z + 2] = 'O';
				result_minimization1[trigger_reverse_Z] = 'O';
				result_minimization1[trigger_reverse_Z + 1] = 'O';
				trigger_Z_in = trigger_anti_Z_in = false;

			}
		}
		if (check) print_deque(result_minimization1);

		bool first_X = false, first_Y = false, first_Z = false;
		bool anti_first_X = false, anti_first_Y = false, anti_first_Z = false;
		for (int i = 0; i < result_minimization1.size(); i++)//склеиваем одинаковые импликанты
		{
			

			if (first_X && result_minimization1[i] == 'X' && result_minimization1[i + 1] == '1')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
			}

			else if (anti_first_X && result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '1')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';

			}

			else if (first_Y && result_minimization1[i] == 'X' && result_minimization1[i + 1] == '2')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
			}

			else if (anti_first_Y && result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '2')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';

			}

			else if (first_Z && result_minimization1[i] == 'X' && result_minimization1[i + 1] == '3')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
			}

			else if (anti_first_Z && result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '3')
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';

			}

			if (result_minimization1[i] == 'X' && result_minimization1[i + 1] == '1')
			{
				first_X = true;
				continue;
			}
			else if (result_minimization1[i] == 'X' && result_minimization1[i + 1] == '2')
			{
				first_Y = true;
				continue;
			}
			else if (result_minimization1[i] == 'X' && result_minimization1[i + 1] == '3')
			{
				first_Z = true;
				continue;
			}
			else if (result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '1')
			{
				anti_first_X = true;
				continue;
			}
			else if (result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '2')
			{
				anti_first_Y = true;
				continue;
			}
			else if (result_minimization1[i] == '!' && result_minimization1[i + 1] == 'X' && result_minimization1[i + 2] == '3')
			{
				anti_first_Z = true;
				continue;
			}
		}
		if (check) print_deque(result_minimization1);

		for (int i = 0; i < result_minimization1.size(); i++)//deleting 0
		{
			if (!(status_of_calls) && (result_minimization1[i] == 'O' || result_minimization1[i] == '*'  && (!(result_minimization1[i + 2] == '!' || result_minimization1[i + 2] == 'X') || !(result_minimization1[i - 2] == '!' || (result_minimization1[i - 2] == '1' || result_minimization1[i - 2] == '2' || result_minimization1[i - 2] == '3')))))
			{
				result_minimization1.erase(result_minimization1.begin() + i);
				i--;
			}
			else if (status_of_calls && (result_minimization1[i] == 'O' || result_minimization1[i] == '+' && (!(result_minimization1[i + 2] == '!' || result_minimization1[i + 2] == 'X') || !(result_minimization1[i - 2] == '!' || (result_minimization1[i - 2] == '1' || result_minimization1[i - 2] == '2' || result_minimization1[i - 2] == '3')))))
			{
				result_minimization1.erase(result_minimization1.begin() + i);
				i--;
			}
			
		}

		if (check) print_deque(result_minimization1);
		for (int i = 0; i < result_minimization1.size(); i++)//deleting " "
		{
			if (i == result_minimization1.size() - 1) break;
			if (result_minimization1[i] == ' ' && result_minimization1[i + 1] == ' ' || result_minimization1[i] == ' ' && result_minimization1[i + 1] == ')')
			{
				result_minimization1.erase(result_minimization1.begin() + i);
				i--;
			}
			if (result_minimization1[i] == '(' && result_minimization1[i + 1] == ' ')
			{
				result_minimization1.erase(result_minimization1.begin() + i + 1);
				i--;
			}

		}
		if (check) print_deque(result_minimization1);
		//additional proccesing
		for (int i = 0; i < result_minimization1.size(); i++)//deleting " "
		{
			if (!(status_of_calls) && (result_minimization1[i] == '+' && result_minimization1[i + 2] == '(' && result_minimization1[i + 3] == ')' && i + 5 == result_minimization1.size()))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				i += 3;

			}

			if ((status_of_calls) && (result_minimization1[i] == '*' && result_minimization1[i + 2] == '(' && result_minimization1[i + 3] == ')' && i + 5 == result_minimization1.size()))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				i += 2;

			}

			if (!(status_of_calls) && (i< result_minimization1.size() - 4) && (result_minimization1[i] == '(' && result_minimization1[i + 1] == '!' && result_minimization1[i + 2] == ')'  && result_minimization1[i + 4] == '+'))
			{
					result_minimization1[i] = 'O';
					result_minimization1[i + 1] = 'O';
					result_minimization1[i + 2] = 'O';
					result_minimization1[i + 3] = 'O';
					result_minimization1[i + 4] = 'O';
					result_minimization1[i + 5] = 'O';
					i += 5;

			}

			if ((status_of_calls) && (i < result_minimization1.size() - 4) && (result_minimization1[i] == '(' && result_minimization1[i + 1] == '!' && result_minimization1[i + 2] == ')' && result_minimization1[i + 4] == '*'))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				result_minimization1[i + 4] = 'O';
				result_minimization1[i + 5] = 'O';
				i += 5;

			}
			//if (i == result_minimization1.size() - 6) break;

			if (!(status_of_calls) && (i < result_minimization1.size() - 6) && (result_minimization1[i] == '(' && result_minimization1[i + 1] == ')' && result_minimization1[i + 3] == '+' && (result_minimization1[i + 6] == 'X' || result_minimization1[i + 6] == '!' || result_minimization1[i + 6] == ')')))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				result_minimization1[i + 4] = 'O';
				i += 4;
			}

			

			if ((status_of_calls) && (i < result_minimization1.size() - 6) && (result_minimization1[i] == '(' && result_minimization1[i + 1] == ')' && result_minimization1[i + 3] == '*' && (result_minimization1[i + 6] == 'X' || result_minimization1[i + 6] == '!' || result_minimization1[i + 6] == ')')))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				result_minimization1[i + 4] = 'O';
				i += 4;
				
			}

			


		}
		for (int i = 0; i < result_minimization1.size(); i++)//deleting 0
		{
			if (result_minimization1[i] == 'O')
			{
				result_minimization1.erase(result_minimization1.begin() + i);
				i--;
			}

		}
		if (check) print_deque(result_minimization1);
		if (status_of_calls)
		{
			for (int i = 0; i < result_minimization1.size(); i++)
			{
				TKNF += result_minimization1[i];
			}
		}
		else
		{
			for (int i = 0; i < result_minimization1.size(); i++)
			{
				TDNF += result_minimization1[i];
			}
		}
		
	}

	void SDNF_and_SKNF()
	{
		bool SDNF_trigger = false, last_in = false;
		int count_SDNF = 1, count_SKNF = 1;
		for (int i = 0; i < numbr_of_column; i++)
		{
			if (spreadsheet_truth[bit_depth][i] == 1) number_of_terms_SDNF++;
			else number_of_terms_SKNF++;
		}

		for (int j = 0; j < numbr_of_column; j++)
		{
			SDNF_trigger = false;

			if (spreadsheet_truth[bit_depth][j] == 1) SDNF_trigger = true;

			for (int i = 0; i < bit_depth; i++)
			{
				if (SDNF_trigger)
				{
					if (i == 0) SDNF_rez += " (";
					if (i == 0 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!X1 *";
					else if (i == 1 && spreadsheet_truth[i][j] == 0) SDNF_rez += " !X2 *";
					else if (i == 2 && spreadsheet_truth[i][j] == 0) SDNF_rez += " !X3";
					else if (i == 3 && spreadsheet_truth[i][j] == 0) SDNF_rez += " * !X4";
					else if (i == 0) SDNF_rez += "X1 *";
					else if (i == 1) SDNF_rez += " X2 *";
					else if (i == 2) SDNF_rez += " X3";
					else if (i == 3) SDNF_rez += " * X4";
					if (i == bit_depth - 1) SDNF_rez += ") ";
					if (count_SDNF != number_of_terms_SDNF && i == bit_depth - 1)
					{
						SDNF_rez += " + ";
						count_SDNF++;
					}
				}

				else
				{
					if (i == 0) SKNF_rez += " (";
					if (i == 0 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X1 + ";
					else if (i == 1 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X2 + ";
					else if (i == 2 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X3";
					else if (i == 3 && spreadsheet_truth[i][j] == 1) SKNF_rez += " + !X4";
					else if (i == 0) SKNF_rez += "X1 + ";
					else if (i == 1) SKNF_rez += "X2 + ";
					else if (i == 2) SKNF_rez += "X3";
					else if (i == 3) SKNF_rez += " + X4";
					if (i == bit_depth - 1) SKNF_rez += ") ";
					if (count_SKNF != number_of_terms_SKNF && i == bit_depth - 1)
					{
						SKNF_rez += " * ";
						count_SKNF++;
					}
				}
			}
		}
		cout << "SDNF form: " << SDNF_rez << "\n";
		cout << "SKNF form: " << SKNF_rez << "\n";
	}

	deque<bool> processing(deque<char> dq)
	{
		deque<bool>  result_container;
		bool X, Y, Z, reverse = false;
		int str = 0;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'X' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'X' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'R' || dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'R')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{
					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					result_container.push_back(X + X);
				}
				i += 2;
			}

			else if (dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'X' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'X' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'R' || dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'R')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{
					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					result_container.push_back(X * X);
				}
				i += 2;
			}
			else if (dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'Y' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'Y' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'F' || dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'F')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{

					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					Y = spreadsheet_truth[str + 1][column];
					if (dq[i + 2] == 'F') Y = !Y;
					result_container.push_back(X + Y);
				}
			}
			else if (dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'Z' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'Z' || dq[i] == 'R' && dq[i + 1] == '+' && dq[i + 2] == 'L' || dq[i] == 'X' && dq[i + 1] == '+' && dq[i + 2] == 'L')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{
					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					Z = spreadsheet_truth[str + 2][column];
					if (dq[i + 2] == 'Z') Z = !Z;
					result_container.push_back(X + Z);
				}
			}
			else if (dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'Y' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'Y' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'F' || dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'F')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{
					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					Y = spreadsheet_truth[str + 1][column];
					if (dq[i + 2] == 'F') Y = !Y;
					result_container.push_back(X * Y);
				}
			}
			else if (dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'Z' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'Z' || dq[i] == 'R' && dq[i + 1] == '*' && dq[i + 2] == 'L' || dq[i] == 'X' && dq[i + 1] == '*' && dq[i + 2] == 'L')
			{
				for (int column = 0; column < numbr_of_column; column++)
				{
					X = spreadsheet_truth[str][column];
					if (dq[i] == 'R') X = !X;
					Z = spreadsheet_truth[str + 2][column];
					if (dq[i + 2] == 'L') Z = !Z;
					result_container.push_back(X * Z);
				}
			}


			else if (dq[i] == '+' && dq[i + 1] == 'X' || dq[i] == '+' && dq[i + 1] == 'R')
			{
				for (int j = 0; j < bit_depth; j++)
				{
					X = spreadsheet_truth[str][j];
					result_container[j] = result_container[j] + X;
				}

			}
			else if (dq[i] == '+' && dq[i + 1] == 'Y' || dq[i] == '+' && dq[i + 1] == 'F')
			{

				for (int j = 0; j < bit_depth; j++)
				{
					Y = spreadsheet_truth[str + 1][j];
					if (dq[i + 1] == 'F') Y = !Y;
					result_container[j] = result_container[j] + Y;
				}
			}
			else if (dq[i] == '+' && dq[i + 1] == 'Z' || dq[i] == '+' && dq[i + 1] == 'L')
			{
				for (int j = 0; j < bit_depth; j++)
				{
					Z = spreadsheet_truth[str + 2][j];
					if (dq[i + 1] == 'L') Z = !Z;
					result_container[j] = result_container[j] + Z;
				}
			}
			else if (dq[i] == '*' && dq[i + 1] == 'X' || dq[i] == '*' && dq[i + 1] == 'R')
			{
				for (int j = 0; j < bit_depth; j++)
				{
					X = spreadsheet_truth[str][j];
					if (dq[i + 1] == 'R') X = !X;
					result_container[j] = result_container[j] * X;
				}
			}
			else if (dq[i] == '*' && dq[i + 1] == 'Y' || dq[i] == '*' && dq[i + 1] == 'F')
			{
				for (int j = 0; j < bit_depth; j++)
				{
					Y = spreadsheet_truth[str + 1][j];
					if (dq[i + 1] == 'F') Y = !Y;
					result_container[j] = result_container[j] * Y;
				}
			}
			else if (dq[i] == '*' && dq[i + 1] == 'Z' || dq[i] == '*' && dq[i + 1] == 'L')
			{
				for (int j = 0; j < bit_depth; j++)
				{
					Z = spreadsheet_truth[str + 2][j];
					if (dq[i + 1] == 'L') Z = !Z;
					result_container[j] = result_container[j] * Z;
				}
			}
		}


		return result_container;
	}

	string get_SDNF_rez() { return SDNF_rez; }

	string get_SKNF_rez() { return SKNF_rez; }

	string get_TDNF_rez() { return TDNF; }

	string get_TKNF_rez() { return TKNF; }

private:
	int bit_depth = 0;
	int numbr_of_column = 0;
	int number_of_terms_SDNF = 0;
	int number_of_terms_SKNF = 0;
	string SDNF_rez = "";
	string SKNF_rez = "";
	string TDNF_rez = "";
	string TKNF_rez = "";
	string TDNF = "";
	string TKNF = "";
	static const int number_of_strings = 5;
	static const int number_of_columns = 16;
	bool spreadsheet_truth[number_of_strings][number_of_columns];
	bool status_of_calls = false;
	bool check = true;
	bool check_mass = true;

};

void main()
{
	deque<char> analyzing_function;
	int choose, max_number_input = 256, numbr_of_input = 100;
	deque<int> function;
	static const int null = 0;
	static const int max_number_input_user = 7;
	bool reset = true, checker = false, second_task = false;
	Logic_function exmpl;
	while (reset)
	{
		second_task = false;
		cout << "Input function one from 3 forms:\n";
		cout << "1: F(0,1,3,7,8,9,11,15)\n";
		cout << "2: F(X1, X2, X3, Xn)\n";
		cout << "3: F(!X + Y * Z)\n";
		cout << "0: Complete program\n";
		cin >> choose;
		if (choose == 2)
		{
			choose--;
			second_task = true;
		}
		switch (choose)
		{
		case 0:
		{
			reset = false;
			break;
		}
		case 1:
		{
			try
			{
				checker = false;
				int j = 0;
				int num = 0;
				if (second_task)
				{
					checker = true;
					cout << "Input i function: ";
					cin >> num;
					if (num >= max_number_input) throw 2;

				}
				else
				{
					function.clear();
					int num = 0, size = 0;
					cout << "Input size function: ";
					cin >> size;
					if (!(size >= null && size <= numbr_of_input)) throw 2;
					cout << "Input function: ";

					for (int i = 0; i < size; i++)
					{
						cin >> num;
						function.push_back(num);
						if (!(num >= null && num <= max_number_input_user)) throw 2;
					}

				}

				exmpl.analysis_input(function, checker, num);
			}

			catch (int error)
			{
				if (error == 2) cout << "Uncorrect unput!\n";
			}
			break;
		}
		case 3:
		{
			try {
				analyzing_function.clear();
				char symbol = 0;
				int number_of_breckets = 0;
				cout << "Input function, for stopping input tape (#): ";
				for (int i = 0; i < numbr_of_input; i++)
				{
					cin >> symbol;
					if (symbol == '#') break;
					if (symbol == '(') number_of_breckets++;
					if (symbol != 'X' && symbol != 'Y' && symbol != 'Z' && symbol != '(' && symbol != ')' && symbol != '*' && symbol != '+' && symbol != '!') throw 1;
					else if (symbol == ')') number_of_breckets--;

					analyzing_function.push_back(symbol);
				}
				if (number_of_breckets != 0) throw 1;
				exmpl.analysis_input_logical_form(analyzing_function);
			}
			catch (int error)
			{
				if (error == 1) cout << "Uncorrect unput!\n";
			}
			break;
		}

		default:
		{
			cout << "No such this case!\n";
			break;
		}
		}
		system("pause");
		system("cls");
	}
}
