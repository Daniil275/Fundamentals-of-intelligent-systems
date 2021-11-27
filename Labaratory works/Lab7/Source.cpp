#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl cout<<"\n";

struct Result_find
{
	bool trigger_right;
	bool trigger_left;
};

vector<bool> get_random_word()
{
	vector <bool> out;
	int word_lenght = 8;

	for (size_t i = 0; i < word_lenght; i++)
	{
		if (rand() % 2 == 1)
		{
			out.push_back(1);
		}
		else
		{
			out.push_back(0);
		}
	}
	return out;
}

Result_find recursive_find(string argument, vector<bool>& word, int i, int mask = 0) {
	Result_find temp;
	Result_find temp1;
	if (i + 1 == word.size() - mask)
	{
		temp1.trigger_right = false;
		temp1.trigger_left = false;
	}
	else
	{
		temp1 = recursive_find(argument, word, i + 1, mask);
	}
	if (temp1.trigger_right || (argument[i] == '0' && word[i] == 1 && !temp1.trigger_left))
		temp.trigger_right = true;
	else
		temp.trigger_right = false;
	if (temp1.trigger_left || (argument[i] == '1' && word[i] == 0 && !temp1.trigger_right))
		temp.trigger_left = true;
	else
		temp.trigger_left = false;
	return temp;
}

void matching_search(vector<vector<bool>>& book, vector<bool>& word)
{
	vector<vector<bool>> best_matches;
	vector<size_t> best_mutch_numb;
	size_t best_mutch_discharge = 0;
	size_t current_best_mutch_discharge;

	for (size_t each_word = 0; each_word < book.size(); each_word++)
	{
		if (word != book[each_word])
		{
			current_best_mutch_discharge = 0;
			for (size_t each_letter = 0; each_letter < word.size(); each_letter++)
			{
				if (word[each_letter] == book[each_word][each_letter])
				{
					current_best_mutch_discharge = each_letter + 1;
				}
				else
				{
					each_letter = book[each_word].size() + 1;
				}
			}
			if (current_best_mutch_discharge > best_mutch_discharge)
			{
				best_mutch_discharge = current_best_mutch_discharge;
				best_mutch_numb.clear();
				best_matches.clear();
				best_mutch_numb.push_back(each_word);
				best_matches.push_back(book[each_word]);
			}
			else if (current_best_mutch_discharge == best_mutch_discharge)
			{
				best_mutch_numb.push_back(each_word);
				best_matches.push_back(book[each_word]);
			}
		}
	}

	for (size_t each_word = 0; each_word < best_matches.size(); each_word++)
	{
		cout << "[" << best_mutch_numb[each_word] + 1 << "] ";
		for (size_t each_letter = 0; each_letter < best_matches[each_word].size(); each_letter++)
		{
			cout << best_matches[each_word][each_letter];
		}
		endl
	}
}

void gap_search(vector<vector<bool>>& book, vector<bool>& high, vector<bool>& low)
{
	for (size_t i = 0; i < book.size(); i++)
	{
		string temp = "";
		for (size_t j = 0; j < book[i].size(); j++)
		{
			temp += to_string(book[i][j]);
		}
		if (recursive_find(temp, high, 0, 0).trigger_right == 1 && recursive_find(temp, low, 0, 0).trigger_left == 0)
		{
			cout << "[" << i << "] ";
			for (size_t i = 0; i < book[i].size(); i++)
			{
				cout << book[i][i];
			}
			endl
		}
	}
}

string nearest(vector<vector<bool>>& book, vector<bool>& word)
{
	vector<vector<bool>> save;

	for (size_t i = 0; i < book.size(); i++)
	{
		string temp = "";
		for (size_t j = 0; j < book[i].size(); j++)
		{
			temp += to_string(book[i][j]);
		}
		
		if (recursive_find(temp, word, 0, 0).trigger_right == 0 && recursive_find(temp, word, 0, 0).trigger_left == 1)
		{
			save.push_back(book[i]);
		}
	}

	string min = "";
	for (size_t i = 0; i < save.size(); i++)
	{
		string temp = "";
		for (size_t j = 0; j < save[i].size(); j++)
		{
			temp += to_string(save[i][j]);
		}
		for (size_t each_word_j = i + 1; each_word_j < save.size(); each_word_j++)
		{

			if (recursive_find(temp, save[each_word_j], 0, 0).trigger_right == 1 && recursive_find(temp, save[each_word_j], 0, 0).trigger_left == 0)
			{
				min = temp;
			}
		}
	}
	save.clear();

	for (size_t i = 0; i < book.size(); i++)
	{
		string temp = "";
		for (size_t j = 0; j < book[i].size(); j++)
		{
			temp += to_string(book[i][j]);
		}
		if (recursive_find(temp, word, 0, 0).trigger_right == 0 && recursive_find(temp, word, 0, 0).trigger_left == 1)
		{
			save.push_back(book[i]);
		}
	}

	string max = "";
	for (size_t i = 0; i < save.size(); i++)
	{
		string temp = "";
		for (size_t j = 0; j < save[i].size(); j++)
		{
			temp += to_string(save[i][j]);
		}
		for (size_t each_word_j = i + 1; each_word_j < save.size(); each_word_j++)
		{

			if (recursive_find(temp, save[each_word_j], 0, 0).trigger_right == 0 && recursive_find(temp, save[each_word_j], 0, 0).trigger_left == 1)
			{
				max = temp;
			}
		}
	}
	cout << "Nearest from above: " << max << "\n";
	cout << "Nearest from below: " << min << "\n";
	return max;
}

void main()
{
	vector<vector<bool>> book;
	int number_of_words = 30;
	for (size_t i = 0; i < number_of_words; i++)
	{
		vector<bool> boof = get_random_word();
		book.push_back(boof);
		if (i < 9) cout << "[" << i + 1 << "]  ";
		else cout << "[" << i + 1 << "] ";
		for (size_t j = 0; j < boof.size(); j++)
		{
			cout << boof[j];
		}
		endl
	}
	endl

	string word;
	size_t mask;
	cout << "Enter a word to search: ";
	cin >> word;
	cout << "Enter mask: ";
	cin >> mask;
	for (size_t each_word = 0; each_word < book.size(); each_word++)
	{
		Result_find temp = recursive_find(word, book[each_word], 0, mask);
		cout << "[" << each_word + 1 << "] " << temp.trigger_right << " " << temp.trigger_left << "\n";
	}
	endl

	int val;
	cout << "Input number: ";
	cin >> val;
	nearest(book, book[val]);
	system("pause");
}
