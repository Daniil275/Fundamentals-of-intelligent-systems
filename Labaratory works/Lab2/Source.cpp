#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
#define endl cout << "\n";
//������� ��� ��������� ��������
/*
1) ����������(�,&,^,*) "���� ���������"
  | A | B | A * B |                            
  | 1 | 1 |   1   |
  | 1 | 0 |   0   |
  | 0 | 1 |   0   |
  | 0 | 0 |   0   |

 2) ����������(���,|,+,V) "���� ��������"
  | A | B | A + B |
  | 1 | 1 |   1   |
  | 1 | 0 |   1   |
  | 0 | 1 |   1   |
  | 0 | 0 |   0   |

  3) ����������(����, ��,->) "���� ��� ������"
  | A | B | A + B |
  | 1 | 1 |   1   |
  | 1 | 0 |   1   |
  | 0 | 1 |   1   |
  | 0 | 0 |   0   |

  4) ������������(=,<->) "���� ��� �����������(==)"
  | A | B | A + B |
  | 1 | 1 |   1   |
  | 1 | 0 |   1   |
  | 0 | 1 |   1   |
  | 0 | 0 |   0   |

  4) ������������(=,<->) "���� ��� �����������(==)"
  | A | -A  |
  | 1 |  0  |   
  | 0 |  1  |   
 
 (0,1,3,7,8,9,11,15) 
*/
class Logic_function
{
public:

	static void print_array(const bool(&Array)[5][16])
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
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
		container.clear();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 16; j++)               //������������� �������
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
			number_of_terms_SDNF = count;
		}

		else
		{
			int max_num = 0;
			for (auto i : function)
			{
				if (max_num < i) max_num = i;
			}
			number_of_terms_SDNF = function.size();

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
						if (function[q] == num) num_have_in_column = true; //���� ����� ����� ���� � ����� ������� ������ ��� ��� � �������� ������
					}
				}

				while (num >= 1)
				{
					container.push_front(num % 2);                       //������������ ��� ����� � �������� ���� ���� �� ����� �� ���������� � �������
					num /= 2;
				}

				if (container.size() < bit_depth)
				{
					while (container.size() != bit_depth)
					{
						container.push_front(0);                      //���������� �.� ����� �� ������� �����
					}
				}

				for (int s = 0; s < bit_depth; s++)
				{
					spreadsheet_truth[s][j] = container[s];
					if (num_have_in_column) spreadsheet_truth[bit_depth][j] = true;
				}
				container.clear();
			}
			number_of_terms_SKNF = abs(numbr_of_column - number_of_terms_SDNF);
			Logic_function::print_array(spreadsheet_truth);
			endl
		SDNF_and_SKNF();
	}

	void analysis_input_formal_function(const deque<char>& function)
	{

	}

	void SDNF_and_SKNF()
	{
		bool SDNF_trigger = false, last_in = false;
		int count_SDNF = 1, count_SKNF = 1;

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

	string get_SDNF_rez() { return SDNF_rez; }

	string get_SKNF_rez(){ return SKNF_rez; }

private:
	bool spreadsheet_truth[5][16];
	int bit_depth = 0;
	int numbr_of_column = 0;
	int number_of_terms_SDNF = 0;
	int number_of_terms_SKNF = 0;
	string SDNF_rez = "";
	string SKNF_rez = "";
};

void main()
{
	deque<char> analyzing_function;
	int choose;
	deque<int> function;
	bool reset = true, checker = false, second_task = false;
	Logic_function exmpl;
	while (reset)
	{	
		second_task = false;
		cout << "Input function one from 3 forms:\n";
		cout << "1: F(0,1,3,7,8,9,11,15)\n";
		cout << "2: F(X1, X2, X3, Xn)\n";
		cout << "3: F(!X1 + X2 * X3)\n";
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
			checker = false;
			int num = 0;
			if (second_task)
			{
				checker = true;
				cout << "Input i function: ";
				cin >> num;
			}
			else
			{
				function.clear();
				int num, size = 0;
				cout << "Input size function: ";
				cin >> size;
				cout << "Input function: ";
				for (int i = 0; i < size; i++)
				{
					cin >> num;
					function.push_back(num);
				}
			}
			exmpl.analysis_input(function, checker, num);
			break;
		}
		case 3:
		{
			
			char symbol = 0;
			cout << "Input function: ";
			for (int i = 0; i < 100; i++)
			{
				cin >> symbol;
				analyzing_function.push_back(symbol);
			}
			Logic_function::print_deque(analyzing_function);
			//exmpl.analysis_input(function, checker, symbol);
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
