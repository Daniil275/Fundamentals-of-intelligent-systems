#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl cout << "\n";

class Dictionary
{
private:
	struct hesh
	{
		string id;
		string data;
		int value;
		int hesh_code;
		hesh* next = NULL;
	};
	vector <hesh> table;
	int alphavit(char symbol)
	{
		if (symbol == 'Q' || symbol == 'q')
		{
			return 1;
		}
		else if (symbol == 'W' || symbol == 'w')
		{
			return 2;
		}
		else if (symbol == 'E' || symbol == 'e')
		{
			return 3;
		}
		else if (symbol == 'R' || symbol == 'r')
		{
			return 4;
		}
		else if (symbol == 'T' || symbol == 't')
		{
			return 5;
		}
		else if (symbol == 'Y' || symbol == 'y')
		{
			return 6;
		}
		else if (symbol == 'u' || symbol == 'U')
		{
			return 7;
		}
		else if (symbol == 'I' || symbol == 'i')
		{
			return 8;
		}
		else if (symbol == 'O' || symbol == 'o')
		{
			return 9;
		}
		else if (symbol == 'P' || symbol == 'p')
		{
			return 10;
		}
		else if (symbol == 'A' || symbol == 'a')
		{
			return 11;
		}
		else if (symbol == 'S' || symbol == 's')
		{
			return 12;
		}
		else if (symbol == 'D' || symbol == 'd')
		{
			return 13;
		}
		else if (symbol == 'F' || symbol == 'f')
		{
			return 14;
		}
		else if (symbol == 'g' || symbol == 'G')
		{
			return 15;
		}
		else if (symbol == 'h' || symbol == 'H')
		{
			return 16;
		}
		else if (symbol == 'J' || symbol == 'j')
		{
			return 17;
		}
		else if (symbol == 'k' || symbol == 'K')
		{
			return 18;
		}
		else if (symbol == 'L' || symbol == 'l')
		{
			return 19;
		}
		else if (symbol == 'X' || symbol == 'x')
		{
			return 20;
		}
		else if (symbol == 'Z' || symbol == 'z')
		{
			return 21;
		}
		else if (symbol == 'C' || symbol == 'c')
		{
			return 22;
		}
		else if (symbol == 'V' || symbol == 'v')
		{
			return 23;
		}
		else if (symbol == 'B' || symbol == 'b')
		{
			return 24;
		}
		else if (symbol == 'N' || symbol == 'n')
		{
			return 25;
		}
		else if (symbol == 'M' || symbol == 'm')
		{
			return 26;
		}
		else
		{
			return 1000000;
		}
	}
	int get_value(string str)
	{
		int value = 0;
		int range = 2;
		if (str.size() >= 2)
		{
			range = 2;
		}
		else
		{
			range = str.size();
		}
		for (size_t i = 0; i < range; i++)
		{
			value += 33 * alphavit(str[i]);
		}
		return value;
	}
	int get_hesh(int V, int B)
	{
		int val = V % 10 + B;
		return val;
	}

public:
void add_info(string id, string data)
{
	try {
		if (alphavit(id[0]) < 1 || alphavit(id[0]) > 26) throw 1;
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].id == id) throw 2;
		}
		int val = get_value(id);
		int hsh = get_hesh(val, table.size());
		hesh boof;
		bool simple_add = true;
		for (size_t i = 0; i < table.size(); i++)
		{
			if (hsh == table[i].hesh_code)
			{
				hesh* tmp = &table[i];

				while (tmp->next != NULL)
				{
					tmp = tmp->next;
				}
				
				tmp->next = &boof;
				boof.data = data;
				boof.next = NULL;
				boof.id = id;
				boof.value = val;
				boof.hesh_code = hsh;
				table.push_back(boof);
				
				simple_add = false;
				break;
			}
		}
		if (simple_add)
		{
			boof.data = data;
			boof.id = id;
			boof.value = val;
			boof.hesh_code = hsh;
			table.push_back(boof);
		}
	}
	catch (int exp)
	{
		if (exp == 1) cout << "Undefined symbol!!!\n";
		if (exp == 2) cout << "People with this name has in hash-table!!!\n";
	}
}
bool del_info(string id)
{

	int number_off_collision = 0;
	int hash_deliting_alement = 0;
	if(is_empty()) return false;

	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].id == id)
		{
			table.erase(table.begin() + i);
			if (is_empty()) return false;
			hash_deliting_alement = table[i].hesh_code;
		}
	}

	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].hesh_code == hash_deliting_alement)
		{
			number_off_collision++;
		}
	}

	return true;
}
bool is_empty()
{
	if (table.size() == 0)
	{
		return true;
	}
	else return false;

}
bool print_search_info(string id)
{
	bool have_in_table = false;
	if (is_empty()) return false;
	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].id == id)
		{
			cout << "\tThe person you are looking for is in a group (";
			cout << table[i].data;
			cout << ")\n\n";
			have_in_table = true;
		}

	}

	return have_in_table;
}
void print_table()
{	
	cout << "List hash-table: \n";
	cout << "|	Id	|	  data 	        |	value	|   hash_code   |\n";
	for (size_t i = 0; i < table.size(); i++)
	{
		cout <<"|	" << table[i].id << "	|	" << table[i].data << "	|	" << table[i].value << "	|	" << table[i].hesh_code << "	|\n";
	}
	endl
	
	cout << "List collisions: \n";
	cout << "|	Id	|	  data 	        |	value	|   hash_code   |\n";
	for (size_t i = 0; i < table.size(); i++)
	{
		hesh* tmp = &table[i];
		if (tmp->next != nullptr)
		{
			cout << "|	" << tmp->id << "	|	" << tmp->data << "	|	" << tmp->value << "	|	" << tmp->hesh_code << "	|\n";
			tmp = tmp->next;
		}
	}
	endl
}
vector <hesh> getTable()
{
	return table;
}

};


void main()
{
	setlocale(LC_ALL, "Russian");
	Dictionary example;
	example.add_info( "Vlad", "02824924");
	example.add_info( "Liza", "23239502");
	example.add_info( "Marya","23792353");
	example.add_info( "Mike", "38923935");
	example.print_table();

	endl 
	endl 
		example.del_info("Vlad");
	endl
	endl
	example.print_table();
	
}



