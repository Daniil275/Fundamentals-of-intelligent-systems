#include <iostream>
#include <deque>
using namespace std;
#define endl cout << "\n";

class Digital_machine
{
public:
	Digital_machine()
	{
		for (size_t i = 0; i < number_of_strings; i++)
		{
			for (size_t j = 0; j < number_of_columns; j++)
			{
				spreadsheet_truth[i][j] = 0;
			}
		}
	}
	void print_array_scheme(const int(&array)[10][16])
	{
		for (int i = 0; i < number_of_strings; i++)
		{
			if (i == 3) cout << "Vi:  ";
			else if (i < 3) cout << "q*" << i + 1 << ": ";
			else if (i > 3 && i < 7) cout << "q" << i - 3 << ":  ";
			else if (i >= 7 && i <= 9) cout << "h" << i - 6 << ":  ";
			for (int j = 0; j < number_of_columns; j++)
				cout << array[i][j] << " ";
			endl
			if (i + 1 == 3) endl
			else if (i + 1 == 4) endl
			else if (i + 1 == 7) endl
		}
	}
	void converter(int number)
	{
		int num = 0, length = 8, count = 0;
		deque<int> bit_box;
		try
		{
			if(number > 8 || number < 0) throw 1;
		}
		catch (int exp)
		{
			if (exp == 1) cout << "Incorrect input!!!\n";
		}
		
		for (size_t i = 0; i < length; i++)
		{
			bit_box.clear();
			num = i;
			while (num >= 1)
			{
				bit_box.push_front(num % 2);
				num /= 2;
			}
			
			if (bit_box.size() < 3)
			{
				while (bit_box.size() != 3) bit_box.push_front(0);
			}

			num = count;
			while (count < num + 2)
			{
				spreadsheet_truth[0][count] = bit_box[0];
				spreadsheet_truth[1][count] = bit_box[1];
				spreadsheet_truth[2][count] = bit_box[2];
				if (count != 0)
				{
					spreadsheet_truth[4][count - 1] = bit_box[0];
					spreadsheet_truth[5][count - 1] = bit_box[1];
					spreadsheet_truth[6][count - 1] = bit_box[2];
				}
				count % 2 == 0 ? spreadsheet_truth[3][count] = 0 : spreadsheet_truth[3][count] = 1;
				count++;
			}
		}

		for (size_t i = 0; i < number_of_columns; i++)
		{
			spreadsheet_truth[0][i] == spreadsheet_truth[4][i] ? spreadsheet_truth[7][i] = 0 : spreadsheet_truth[7][i] = 1;
			spreadsheet_truth[1][i] == spreadsheet_truth[5][i] ? spreadsheet_truth[8][i] = 0 : spreadsheet_truth[8][i] = 1;
			spreadsheet_truth[2][i] == spreadsheet_truth[6][i] ? spreadsheet_truth[9][i] = 0 : spreadsheet_truth[9][i] = 1;
		}
		print_array_scheme(spreadsheet_truth);

		cout << "\nh1:\n";
		SDNF_and_SKNF(spreadsheet_truth, 7, number * 2);
		cout << "TDF: Q2*Q1*V\n";
		
		cout << "\nh2:\n";
		SDNF_and_SKNF(spreadsheet_truth, 8, number * 2);
		cout << "TDF: Q1*V\n";

		cout << "\nh3:\n";
		SDNF_and_SKNF(spreadsheet_truth, 9, number * 2);
		cout << "TDF: V";
		endl
	}
	void SDNF_and_SKNF(int (&spreadsheet_truth)[10][16], int number_of_string, int number_of_columns)
	{
		SDNF_rez.clear();
		SKNF_rez.clear();
		bool SDNF_trigger = false;
		int count_SDNF = 1, count_SKNF = 1, number_of_string_for_process = 4, number_of_terms_SDNF = 0, number_of_terms_SKNF = 0;

		for (int i = 0; i < number_of_columns; i++)
		{
			if (spreadsheet_truth[number_of_string][i] == 1) number_of_terms_SDNF++;
			else number_of_terms_SKNF++;
		}
		

		for (int j = 0; j < number_of_columns; j++)
		{
			SDNF_trigger = false;
			if (spreadsheet_truth[number_of_string][j] == 1) SDNF_trigger = true;

			for (int i = 0; i < number_of_string_for_process; i++)
			{
				if (SDNF_trigger)
				{
					if (i == 0) SDNF_rez += "(";
					if (i == 0 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!Q1*";
					else if (i == 1 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!Q2*";
					else if (i == 2 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!Q3";
					else if (i == 3 && spreadsheet_truth[i][j] == 0) SDNF_rez += "*!V";
					else if (i == 0) SDNF_rez += "Q1*";
					else if (i == 1) SDNF_rez += "Q2*";
					else if (i == 2) SDNF_rez += "Q3";
					else if (i == 3) SDNF_rez += "*V";
					if (i == number_of_string_for_process - 1) SDNF_rez += ")";
					if (count_SDNF != number_of_terms_SDNF && i == number_of_string_for_process - 1)
					{
						SDNF_rez += "+";
						count_SDNF++;
					}
				}
				else
				{
					if (i == 0) SKNF_rez += "(";
					if (i == 0 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!Q1+";
					else if (i == 1 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!Q2+";
					else if (i == 2 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!Q3";
					else if (i == 3 && spreadsheet_truth[i][j] == 1) SKNF_rez += "+!V";
					else if (i == 0) SKNF_rez += "Q1+";
					else if (i == 1) SKNF_rez += "Q2+";
					else if (i == 2) SKNF_rez += "Q3";
					else if (i == 3) SKNF_rez += "+V";
					if (i == number_of_string_for_process - 1) SKNF_rez += ")";
					if (count_SKNF != number_of_terms_SKNF && i == number_of_string_for_process - 1)
					{
						SKNF_rez += "*";
						count_SKNF++;
					}
				}
			}
		}
		cout << "SDNF form: " << SDNF_rez << "\n";
		cout << "SKNF form: " << SKNF_rez << "\n";
	}
	string get_SDNF_rez() { return SDNF_rez; }
	string get_SKNF_rez() { return SKNF_rez; }

private:
	string SDNF_rez;
	string SKNF_rez;
	static const int number_of_strings = 10;
	static const int number_of_columns = 16;
	int spreadsheet_truth[number_of_strings][number_of_columns];
};

void main()
{
	int choose;
	bool reset = true;
	Digital_machine exmpl;
	while (reset)
	{
		cout << "Input number task:\n";
		cout << "1: Create digital machine\n";
		cout << "0: Complete program\n";
		cin >> choose;
		switch (choose)
		{
		case 0:
		{
			reset = false;
			break;
		}
		case 1:
		{
			int number = 0;
			cout << "Input number of status: ";
			cin >> number;
			exmpl.converter(number);
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
