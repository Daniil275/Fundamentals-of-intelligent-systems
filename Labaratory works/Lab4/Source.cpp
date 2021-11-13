#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;
#define endl cout << "\n";

class �ombinational_scheme
{
public:
	void print_array(const bool(&Array)[5][8])
	{
		for (int i = 0; i < number_of_strings; i++)
		{
			if (i == number_of_strings - 2) cout << "Fi:   ";
			else if (i == number_of_strings - 1) cout << "Fi+1: ";
			else cout << "X" << i + 1 << ":   ";

			for (int j = 0; j < number_of_columns; j++)
			{
				cout << Array[i][j];
			}
			endl
		}
	}

	void print_array_scheme(const int(&Array)[9][16])
	{
		for (int i = 0; i < number_of_strings_for_tetrad_scheme; i++)
		{
			if (i == 0) cout << "Num:";
			if(i!=0 && i < 5) cout << "X" << i << ": ";
			else if(i != 0 && i >= 5) cout << "Y" << i - 4 << ": ";
			
			for (int j = 0; j < number_of_columns_for_tetrad_scheme; j++)
			{
				if (j > 9 && i!=0)
				{
					cout << Array[i][j] << "  ";
					continue;
				}

				cout << Array[i][j]<<" ";
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

	void scheme_SDNF(deque<bool> out1, deque<bool> out2)
	{
		for (size_t i = 0; i < number_of_columns; i++)
		{
			spreadsheet_truth[3][i] = out1[i];
			spreadsheet_truth[4][i] = out2[i];
		}

		if (check_mass) print_array(spreadsheet_truth);
		endl
			is_sdnf = true;
			SDNF_and_SKNF(spreadsheet_truth, number_of_strings);
			calculation_method(SDNF_rez);
			clear_strings();
			endl
			SDNF_and_SKNF(spreadsheet_truth, number_of_strings + 1);
			is_sdnf = false;
			calculation_method(SDNF_rez);
		endl
	}

	void scheme_SKNF(deque<bool> out1, deque<bool> out2)
	{
		for (size_t i = 0; i < number_of_columns; i++)
		{
			spreadsheet_truth[3][i] = out1[i];
			spreadsheet_truth[4][i] = out2[i];
		}

		if (check_mass) print_array(spreadsheet_truth);
		endl
			status_of_calls = true;
			SDNF_and_SKNF(spreadsheet_truth, number_of_strings);
		calculation_method(SKNF_rez);
		endl
			clear_strings();
		SDNF_and_SKNF(spreadsheet_truth, number_of_strings + 1);
		calculation_method(SKNF_rez);
		status_of_calls = false;
		endl
	}

	void clear_strings()
	{
		SDNF_rez.clear();
		SKNF_rez.clear();
		TDNF.clear();
		TKNF.clear();
	}

	string gluingSKNF(string sourceString) {
		string gluingResult = "";
		vector<string> fragments = fragmentationAND2(sourceString);
		for (int i = 0; i < fragments.size(); i++)
		{
			for (int j = i + 1; j < fragments.size(); j++)
			{
				if (checkAreNeighboursSKNF(fragments[i], fragments[j]) != "")
					if (gluingResult == "")
					{
						gluingResult += checkAreNeighboursSKNF(fragments[i], fragments[j]);
					}
					else
					{
						gluingResult += "*" + checkAreNeighboursSKNF(fragments[i], fragments[j]);
					}
			}
		}
		return gluingResult;
	}

	string checkAreNeighboursSKNF(string s1, string s2) {
		vector<string> a = fragmentationOR(s1);
		vector<string> b = fragmentationOR(s2);
		string ret = "(";
		int k = 0;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] == b[j])
				{
					if (ret == "(")
					{
						ret += a[i];
					}
					else
					{
						ret += "+" + a[i];
					}
					break;
				}
				if (j == b.size() - 1 && a[i] != b[j])
				{
					k++;
				}
			}
			if (k > 1)
			{
				return "";
			}
		}
		ret += ")";
		return ret;
	}

	vector<string> fragmentationAND2(string sourceString) {
		vector<string> result;
		while (sourceString != "")
		{
			result.push_back(sourceString.substr(1, sourceString.find(")") - 1));
			sourceString.erase(0, sourceString.find(")") + 2);
		};
		return result;
	}

	string gluingSDNF(string sourceString) {
		string resultOfGluing = "";
		vector<string> fragments = fragmentationOR(sourceString);
		for (int i = 0; i < fragments.size(); i++)
		{
			for (int j = i + 1; j < fragments.size(); j++)
			{
				if (checkAreNeighboursSDNF(fragments[i], fragments[j]) != "")
				{
					if (resultOfGluing == "")
					{
						resultOfGluing += checkAreNeighboursSDNF(fragments[i], fragments[j]);
					}
					else
					{
						resultOfGluing += "+" + checkAreNeighboursSDNF(fragments[i], fragments[j]);
					}
				}
			}
		}
		return resultOfGluing;
	}

	vector<string> fragmentationAND(string sourceString) {
		vector<string> result;
		while (sourceString != "")
		{
			if (sourceString.find("*") == -1)
			{
				result.push_back(sourceString);
				sourceString = "";
			}
			else
			{
				result.push_back(sourceString.substr(0, sourceString.find("*")));
				sourceString.erase(0, sourceString.find("*") + 1);
			}
		};
		return result;
	}

	string checkAreNeighboursSDNF(string s1, string s2) {
		vector<string> a = fragmentationAND(s1);
		vector<string> b = fragmentationAND(s2);
		string minNeighboursResult = "";
		int k = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				if (a[i] == b[j]) {
					if (minNeighboursResult == "")
					{
						minNeighboursResult += a[i];
					}
					else
					{
						minNeighboursResult += "*" + a[i];
					}
					break;
				}
				if (j == b.size() - 1 && a[i] != b[j])
				{
					k++;
				}
			}
			if (k > 1)
			{
				return "";
			}
		}
		return minNeighboursResult;
	}

	vector<string> fragmentationOR(string sourceString) {
		if (sourceString[0] == '(')
		{
			sourceString = sourceString.substr(1, sourceString.length() - 2);
		}
		vector<string> fragments;
		while (sourceString != "")
		{
			if (sourceString.find("+") == -1)
			{
				fragments.push_back(sourceString);
				sourceString = "";
			}
			else
			{
				fragments.push_back(sourceString.substr(0, sourceString.find("+")));
				sourceString.erase(0, sourceString.find("+") + 1);
			}
		};
		return fragments;
	}

	void converter(int number)
	{
		int lenght = 16;
		int num = 0;
		int calculate_out = 0;
		deque<int> bit_box;
		deque<int> bit_box_for_out;
		for (size_t i = 0; i < lenght; i++)
		{
			num = i;
			calculate_out = i + number;
			spreadsheet_truth_for_tetrad_scheme[0][i] = i;
			while (num >= 1)
			{
				bit_box.push_front(num % 2);
				num /= 2;
			}
			while (calculate_out >= 1)
			{
				bit_box_for_out.push_front(calculate_out % 2);
				calculate_out /= 2;
			}
			if (bit_box.size() < 4)
			{
				while (bit_box.size() != 4) bit_box.push_front(0);
			}
			if (bit_box_for_out.size() < 4)
			{
				while (bit_box_for_out.size() != 4) bit_box_for_out.push_front(0);
			}

			spreadsheet_truth_for_tetrad_scheme[1][i] = bit_box[0];
			spreadsheet_truth_for_tetrad_scheme[2][i] = bit_box[1];
			spreadsheet_truth_for_tetrad_scheme[3][i] = bit_box[2];
			spreadsheet_truth_for_tetrad_scheme[4][i] = bit_box[3];
			spreadsheet_truth_for_tetrad_scheme[5][i] = bit_box_for_out[0];
			spreadsheet_truth_for_tetrad_scheme[6][i] = bit_box_for_out[1];
			spreadsheet_truth_for_tetrad_scheme[7][i] = bit_box_for_out[2];
			spreadsheet_truth_for_tetrad_scheme[8][i] = bit_box_for_out[3];
			
			bit_box.clear();
			bit_box_for_out.clear();
		}
		print_array_scheme(spreadsheet_truth_for_tetrad_scheme);

		cout << "Y1\n";
		SDNF_and_SKNF(spreadsheet_truth_for_tetrad_scheme, 5);
		endl
		TDNF = toTDF(gluingSDNF(SDNF_rez));
		TKNF = toTKF(gluingSKNF(SKNF_rez));
		cout << "TDNF: " << TDNF;
		endl
		cout << "TKNF: " << TKNF;
		//clear_strings();
		endl
		/*cout << "Y2\n";
		SDNF_and_SKNF(spreadsheet_truth_for_tetrad_scheme, 6);
		endl
		cout << "TDNF: " << toTDF(gluingSDNF(SDNF_rez));
		endl
		cout << "TKNF: " << toTKF(gluingSKNF(SKNF_rez));
		endl
		clear_strings();
		cout << "Y3\n";
		SDNF_and_SKNF(spreadsheet_truth_for_tetrad_scheme, 7);
		endl
		cout << "TDNF: " << toTDF(gluingSDNF(SDNF_rez));
		endl
		cout << "TKNF: " << toTKF(gluingSKNF(SKNF_rez));
		endl
		clear_strings();
		cout << "Y4\n";
		SDNF_and_SKNF(spreadsheet_truth_for_tetrad_scheme, 8);
		endl
		cout << "TDNF: " << toTDF(gluingSDNF(SDNF_rez));
		endl
		cout << "TKNF: " << toTKF(gluingSKNF(SKNF_rez));
		endl
		clear_strings();*/
	}

	string toTDF(string sourceString) {
		vector<string> r = fragmentationOR(sourceString);
		for (int i = 0; i < r.size(); i++)
		{
			if (checkExcess(r, i))
			{
				sourceString.erase(sourceString.find(r[i]), r[i].length() + 1);
			}
		}
		return sourceString;
	}

	string toTKF(string sourceString) {
		vector<string> r = fragmentationAND2(sourceString);
		for (int i = 0; i < r.size(); i++) {
			if (checkExcess2(r, i))
			{
				sourceString.erase(sourceString.find(r[i]), r[i].length() + 3);
			}
		}
		return sourceString;
	}

	bool checkExcess2(vector<string> s, int q) {
		vector<vector<string>> r;
		vector<string> d;

		for (int i = 0; i < s.size(); i++) {
			vector<string> t = fragmentationOR(s[i]);
			r.push_back(t);
		}
		vector<string> k = r[q];

		for (int i = 0; i < k.size(); i++)
		{
			for (int j = 0; j < r.size(); j++)
			{
				if (j != q)
				{
					if (find(r[j], reverse(k[i])))
					{
						r.erase(r.begin() + j);
					}
				}
			}
		}

		for (int i = 0; i < r.size(); i++)
		{
			if (i != q)
			{
				for (int j = 0; j < r[i].size(); j++)
				{
					if (!find(k, r[i][j]))
					{
						d.push_back(r[i][j]);
					}
				}
			}
		}

		for (int i = 0; i < d.size(); i++)
		{
			if (find(d, reverse(d[i])))
			{
				return true;
			}
		}

		return false;
	}

	bool checkExcess(vector<string> sourceConstituents, int q) {
		vector<vector<string>> fragmentedConstituents;
		vector<string> fragmentsAnalyzingVector;
		for (int i = 0; i < sourceConstituents.size(); i++)
		{
			vector<string> fragmentsAnalyzingVector = fragmentationAND(sourceConstituents[i]);
			fragmentedConstituents.push_back(fragmentsAnalyzingVector);
		}
		vector<string> k = fragmentedConstituents[q];
		for (int i = 0; i < k.size(); i++) {
			for (int j = 0; j < fragmentedConstituents.size(); j++)
			{
				if (j != q)
				{
					if (find(fragmentedConstituents[j], reverse(k[i])))
					{
						fragmentedConstituents.erase(fragmentedConstituents.begin() + j);
					}
				}
			}
		}

		for (int i = 0; i < fragmentedConstituents.size(); i++)
		{
			if (i != q)
			{
				for (int j = 0; j < fragmentedConstituents[i].size(); j++)
				{
					if (!find(k, fragmentedConstituents[i][j]))
					{
						fragmentsAnalyzingVector.push_back(fragmentedConstituents[i][j]);
					}
				}
			}
		}

		for (int i = 0; i < fragmentsAnalyzingVector.size(); i++)
		{
			if (!find(fragmentsAnalyzingVector, reverse(fragmentsAnalyzingVector[i])))
			{
				return false;
			}
		}
		return true;
	}

	bool find(vector<string> sourceString, string stringToFind) {
		for (int i = 0; i < sourceString.size(); i++) {
			if (sourceString[i] == stringToFind)
			{
				return true;
			}
		}
		return false;
	}

	string reverse(string sourceString) {
		if (sourceString[0] == '!')
		{
			return sourceString.substr(1, sourceString.length());
		}
		else
		{
			return "!" + sourceString;
		}
	}
	
	void calculation_method(string SDNF_rezult)
	{

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

			if (trigger_reverse_X != 0 && trigger_X_in && trigger_anti_X_in) //������� ��������������
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
		if (check) print_deque(result_minimization);

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

		for (int i = 0; i < result_minimization.size(); i++)//��������� ���������� ����������
		{
			if (result_minimization[i] == 'X' && result_minimization[i + 1] == '1') trigger_reverse_X++;
			else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '2') trigger_reverse_Y++;
			else if (result_minimization[i] == 'X' && result_minimization[i + 1] == '3') trigger_reverse_Z++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '1') trigger_anti_X++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '2') trigger_anti_Y++;
			else if (result_minimization[i] == '!' && result_minimization[i + 1] == 'X' && result_minimization[i + 2] == '3') trigger_anti_Z++;
		}

		function_processing(result_minimization);
		if (status_of_calls) cout << "TKNF: " << TKNF << "\n";
		else cout << "TDNF: " << TDNF << "\n";
	}

	void function_processing(deque<char> result_minimization)
	{
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

			if (trigger_reverse_X != 0 && trigger_X_in && trigger_anti_X_in) //������� ��������������
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
		for (int i = 0; i < result_minimization1.size(); i++)//��������� ���������� ���������� !(X+Y)+!Z#
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
			if (!(status_of_calls) && (result_minimization1[i] == 'O' || result_minimization1[i] == '*' && (!(result_minimization1[i + 2] == '!' || result_minimization1[i + 2] == 'X') || !(result_minimization1[i - 2] == '!' || (result_minimization1[i - 2] == '1' || result_minimization1[i - 2] == '2' || result_minimization1[i - 2] == '3')))))
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
		for (int i = 0; i < result_minimization1.size(); i++)//deleting " "
		{
			if (!(status_of_calls) && (i + 5 <= result_minimization1.size() && result_minimization1[i] == '+' && result_minimization1[i + 2] == '(' && result_minimization1[i + 3] == ')'))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				i += 3;

			}

			if ((status_of_calls) && (i + 5 <= result_minimization1.size() && result_minimization1[i] == '*' && result_minimization1[i + 2] == '(' && result_minimization1[i + 3] == ')'))
			{
				result_minimization1[i] = 'O';
				result_minimization1[i + 1] = 'O';
				result_minimization1[i + 2] = 'O';
				result_minimization1[i + 3] = 'O';
				i += 2;

			}

			if (!(status_of_calls) && (i < result_minimization1.size() - 4) && (result_minimization1[i] == '(' && result_minimization1[i + 1] == '!' && result_minimization1[i + 2] == ')' && result_minimization1[i + 4] == '+'))
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

	void SDNF_and_SKNF(bool (&spreadsheet_truth)[5][8], int number_of_strings)
	{
		bool SDNF_trigger = false, last_in = false;
		int depends = 0;
		if (number_of_strings == this->number_of_strings + 1) depends++;
		for (int j = 0; j < number_of_columns; j++)
		{
			SDNF_trigger = false;

			if (spreadsheet_truth[number_of_strings - 2][j] == 1) SDNF_trigger = true;
			

			for (int i = 0; i < number_of_strings - 2 - depends; i++)
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
					if (i == number_of_strings - 1) SDNF_rez += ") ";
					if (number_of_strings - 3 - depends== i && number_of_columns - 1 != j)
					{
						SDNF_rez += ") +";
					}
					if (number_of_strings - 3 - depends == i && number_of_columns - 1 == j)
					{
						SDNF_rez += ")";
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
					if (i == number_of_strings - 1) SKNF_rez += ") ";
					if (number_of_strings - 3 - depends  == i && number_of_columns - 2 != j)
					{
						SKNF_rez += ") *";
					}
					if (number_of_columns - 2 - depends == j && number_of_strings - 3 == i)
					{
						SKNF_rez += ")";
					}

				}
			}
		}
		if (SKNF_rez[SKNF_rez.size() - 1] == '*') SKNF_rez[SKNF_rez.size() - 1] = ' ';
		if(is_sdnf) cout << "SDNF form: " << SDNF_rez << "\n";
		else cout << "SKNF form: " << SKNF_rez << "\n";
	}

	void SDNF_and_SKNF(int (&spreadsheet_truth)[9][16], int number_of_strings)
	{
		
			bool SDNF_trigger = false, last_in = false;
			int count_SDNF = 1, count_SKNF = 1;
			for (int i = 0; i < number_of_columns_for_tetrad_scheme; i++)
			{
				if (spreadsheet_truth[number_of_strings][i] == 1) number_of_terms_SDNF++;
				else number_of_terms_SKNF++;
			}

			for (int j = 0; j < number_of_columns_for_tetrad_scheme; j++)
			{
				SDNF_trigger = false;

				if (spreadsheet_truth[number_of_strings][j] == 1) SDNF_trigger = true;

				for (int i = 1; i < number_of_strings; i++)
				{
					if (SDNF_trigger)
					{
						if (i == 1) SDNF_rez += "(";
						if (i == 1 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!X1*";
						else if (i == 2 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!X2*";
						else if (i == 3 && spreadsheet_truth[i][j] == 0) SDNF_rez += "!X3";
						else if (i == 4 && spreadsheet_truth[i][j] == 0) SDNF_rez += "*!X4";
						else if (i == 1) SDNF_rez += "X1*";
						else if (i == 2) SDNF_rez += "X2*";
						else if (i == 3) SDNF_rez += "X3";
						else if (i == 4) SDNF_rez += "*X4";
						if (i == number_of_strings - 1) SDNF_rez += ")";
						if (count_SDNF != number_of_terms_SDNF && i == number_of_strings - 1)
						{
							SDNF_rez += "+";
							count_SDNF++;
						}
					}

					else
					{
						if (i == 1) SKNF_rez += "(";
						if (i == 1 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X1+";
						else if (i == 2 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X2+";
						else if (i == 3 && spreadsheet_truth[i][j] == 1) SKNF_rez += "!X3";
						else if (i == 4 && spreadsheet_truth[i][j] == 1) SKNF_rez += "+!X4";
						else if (i == 1) SKNF_rez += "X1+";
						else if (i == 2) SKNF_rez += "X2+";
						else if (i == 3) SKNF_rez += "X3";
						else if (i == 4) SKNF_rez += "+X4";
						if (i == number_of_strings - 1) SKNF_rez += ")";
						if (count_SKNF != number_of_terms_SKNF && i == number_of_strings - 1)
						{
							SKNF_rez += "*";
							count_SKNF++;
						}
					}
				}
			}
			cout << "SDNF form: " << SDNF_rez << "\n";
			cout << "SKNF form: " << SKNF_rez << "\n";
			/*SDNF_rez.clear();
			SKNF_rez.clear();*/
	}

	string get_SDNF_rez() { return SDNF_rez; }

	string get_SKNF_rez() { return SKNF_rez; }

	string get_TDNF_rez() { return TDNF; }

	string get_TKNF_rez() { return TKNF; }

private:
	int number_of_terms_SDNF = 0;
	int number_of_terms_SKNF = 0;
	string SDNF_rez = "";
	string SKNF_rez = "";
	string TDNF = "";
	string TKNF = "";
	static const int number_of_strings = 5;
	static const int number_of_columns = 8;
	static const int number_of_strings_for_tetrad_scheme = 9;
	static const int number_of_columns_for_tetrad_scheme = 16;
	bool spreadsheet_truth[number_of_strings][number_of_columns]{
		{0,0,0,0,1,1,1,1},
		{0,0,1,1,0,0,1,1},
		{0,1,0,1,0,1,0,1},
	};
	int spreadsheet_truth_for_tetrad_scheme[number_of_strings_for_tetrad_scheme][number_of_columns_for_tetrad_scheme];
	bool status_of_calls = false;
	bool check = false;
	bool check_mass = true;
	bool is_sdnf = false;
};

void main()
{
	
	int choose, number_columns = 8;
	bool reset = true;
	�ombinational_scheme exmpl;
	while (reset)
	{
		cout << "Input number task:\n";
		cout << "1: Task1\n";
		cout << "2: Task2\n";
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
			try {
				deque<bool> out1, out2;
				int number;
				char type_representation = ' ';
				cout << "Input out 1: ";
				for (size_t i = 0; i < number_columns; i++)
				{
					cin >> number;
					if (number > 1 || number < 0) throw 1;
					out1.push_back(number);
				}

				cout << "Input out 2: ";
				for (size_t i = 0; i < number_columns; i++)
				{
					cin >> number;
					if (number > 1 || number < 0) throw 1;
					out2.push_back(number);
				}
				cout << "Input - (Y) if you want view SDNF representation, else each other symbol: ";
				cin >> type_representation;
				if(type_representation == 'y' || type_representation == 'Y') exmpl.scheme_SDNF(out1, out2);
				else exmpl.scheme_SKNF(out1, out2);
				break;
			}

			catch (int exp)
			{
				if (exp == 1) cout << "Uncorrected input!!!\n";
			}
			break;
		}
		case 2:
		{
			int number = 0;
			cout << "Input number 8421 + (n): ";
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
