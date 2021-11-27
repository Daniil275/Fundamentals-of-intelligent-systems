#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl cout<<"\n";

class Asoc_memory
{
private:
	vector<vector<bool>> table;
	vector<vector<bool>> buff;
	unsigned int size = 16;
	unsigned int converter = 3;
	vector<bool> addition(vector<bool>& first, vector<bool>& second)
	{
		vector <bool> res;
		bool trans = false;
		for (size_t i = first.size(); i > 0; i--)
		{
			if (first[i - 1] == 0 && second[i - 1] == 0 && trans == false)
			{
				res.emplace(res.begin(), 0);
				trans = false;
			}
			else if (first[i - 1] == 0 && second[i - 1] == 0 && trans == true)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first[i - 1] == 1 && second[i - 1] == 0 && trans == false)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first[i - 1] == 1 && second[i - 1] == 0 && trans == true)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first[i - 1] == 0 && second[i - 1] == 1 && trans == false)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first[i - 1] == 0 && second[i - 1] == 1 && trans == true)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first[i - 1] == 1 && second[i - 1] == 1 && trans == false)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first[i - 1] == 1 && second[i - 1] == 1 && trans == true)
			{
				res.emplace(res.begin(), 1);
				trans = true;
			}
		}
		return res;
	}
public:
	Asoc_memory()
	{
		vector<bool> nl;
		for (size_t i = 0; i < size; i++)
		{
			nl.push_back(0);
		}
		for (size_t i = 0; i < size; i++)
		{
			table.push_back(nl);
			buff.push_back(nl);
		}
	}
	void print_table()
	{
		cout << " \tASSOCIATIVE	MEMORY\n";
		cout << "\t____________________\n";
		for (size_t i = 0; i < size; i++)
		{
			cout << "\t| ";
			for (size_t j = 0; j < size; j++)
			{
				cout << table[i][j];
			}
			cout << " |";
			endl
		}
		cout << "\t____________________\n";
	}
	void add_element(string word)
	{
		try {
			if (word.length() > 16) throw 1;
			vector<bool> bool_word;
			for (size_t i = 0; i < size - word.size(); i++)
			{
				bool_word.insert(bool_word.begin() + i, 0);
			}
			for (size_t i = size - word.size(); i < size; i++)
			{
				if (word[i - size + word.size()] == '1')
				{
					bool_word.insert(bool_word.begin() + i, 1);
				}
				else
				{
					bool_word.insert(bool_word.begin() + i, 0);
				}
			}
			if (bool_word.size() < 16) throw 2;
			buff.insert(buff.begin(), bool_word);
			buff.pop_back();
			table.clear();

			vector<bool> nl;
			for (size_t i = 0; i < size; i++)
			{
				nl.push_back(0);
			}
			for (size_t i = 0; i < size; i++)
			{
				table.push_back(nl);
			}
			size_t offset = 0;
			for (size_t i = 0; i < size; i++)
			{
				int _i = 0 - offset;
				if (_i < 0)
				{
					_i = size + _i;
				}
				else
				{
					_i = i;
				}
				for (size_t j = 0; j < size; j++)
				{
					table[j][i] = buff[_i][j];
					_i++;
					if (_i > 15)
					{
						_i = 0;
					}
				}
				offset++;
			}
		}
		catch (int exp) {
			if (exp == 1) cout << "Incorrect size of word!!!\n";
			else  if (exp == 2) cout << "Incorrect input!!!\n";
		}
	}
	string get_element(size_t numb)
	{
		string out = "";
		for (size_t i = 0; i < size; i++)
		{
			out += to_string(buff[numb][i]);
		}
		return out;
	}
	void F1_and_F14(size_t i, size_t j)
	{
		string str_i = get_element(i);
		string str_j = get_element(j);
		vector<bool> bool_i;
		vector<bool> bool_j;
		vector<bool> _bool_j;
		vector<bool> res;
		string str_res = "";

		for (size_t i = 0; i < str_i.size(); i++)
		{
			if (str_i[i] == '1')
			{
				bool_i.push_back(1);
			}
			else
			{
				bool_i.push_back(0);
			}
		}
		for (size_t i = 0; i < str_i.size(); i++)
		{
			if (str_i[i] == '1')
			{
				bool_i.push_back(1);
			}
			else
			{
				bool_i.push_back(0);
			}
		}

		for (size_t i = 0; i < bool_j.size(); i++)
		{
			_bool_j.push_back(!bool_j[i]);
		}

		res = addition(_bool_j, bool_j);
		for (size_t i = 0; i < res.size(); i++)
		{
			str_res += to_string(res[i]);
		}
		add_element(str_res);
	}
	void F3_and_F12(size_t i, size_t j)
	{
		vector <bool> one = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
		vector <bool> zero = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		vector <bool> res;
		string str_res = "";

		res = addition(one, zero);
		for (size_t i = 0; i < res.size(); i++)
		{
			str_res += to_string(res[i]);
		}
		add_element(str_res);
	}
	void matching_search(string wrd)
	{
		vector <vector <bool>> best_matches;
		vector <size_t> best_mutch_numb;
		size_t best_mutch_discharge = 0;
		size_t current_best_mutch_discharge;
		vector <bool> word;

		for (size_t i = 0; i < wrd.size(); i++)
		{
			if (wrd[i] == '1')
			{
				word.push_back(1);
			}
			else
			{
				word.push_back(0);
			}
		}

		for (size_t each_word = 0; each_word < table.size(); each_word++)
		{
			if (word != table[each_word])
			{
				current_best_mutch_discharge = 0;
				for (size_t each_letter = 0; each_letter < word.size(); each_letter++)
				{
					if (word[each_letter] == table[each_word][each_letter])
					{
						current_best_mutch_discharge = each_letter + 1;
					}
					else
					{
						each_letter = table[each_word].size() + 1;
					}
				}
				if (current_best_mutch_discharge > best_mutch_discharge)
				{
					best_mutch_discharge = current_best_mutch_discharge;
					best_mutch_numb.clear();
					best_matches.clear();
					best_mutch_numb.push_back(each_word);
					best_matches.push_back(table[each_word]);
				}
				else if (current_best_mutch_discharge == best_mutch_discharge)
				{
					best_mutch_numb.push_back(each_word);
					best_matches.push_back(table[each_word]);
				}
			}
		}

		for (size_t each_word = 0; each_word < best_matches.size(); each_word++)
		{
			cout << "[" << best_mutch_numb[each_word] << "] ";
			for (size_t each_letter = 0; each_letter < best_matches[each_word].size(); each_letter++)
			{
				if (best_mutch_discharge == 0) cout << best_matches[each_word][each_letter];
				else cout << word[each_letter];
			}
			endl
			break;
		}
	}
	void ariphmetics()
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (int(table[i][0]) + int(table[i][1]) + int(table[i][2]) < 3)
			{
				vector <bool> A;
				A.push_back(table[i][0]);
				A.push_back(table[i][1]);
				A.push_back(table[i][2]);
				A.push_back(table[i][3]);

				vector <bool> B;
				B.push_back(table[i][4]);
				B.push_back(table[i][5]);
				B.push_back(table[i][6]);
				B.push_back(table[i][7]);

				vector <bool> S = addition(A, B);
				for (size_t j = 0; j < 5 - S.size(); j++)
				{
					S.push_back(0);
				}

				vector <bool> new_vect;

				for (size_t j = 0; j < converter; j++)
				{
					new_vect.push_back(table[i][j]);
				}
				for (size_t j = 0; j < converter + 1; j++)
				{
					new_vect.push_back(A[j]);
				}
				for (size_t j = 0; j < converter + 1; j++)
				{
					new_vect.push_back(B[j]);
				}
				for (size_t j = 0; j < converter + 2; j++)
				{
					new_vect.push_back(S[j]);
				}
				table[i] = new_vect;
			}
		}
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	endl
	Asoc_memory tb;
	tb.print_table();
	tb.add_element("1111111111111111");
	endl
	tb.print_table();
	tb.add_element("1010101011010101");
	endl
	tb.print_table();
	tb.ariphmetics();
	endl
	tb.print_table();
	system("pause");
}
