#include "stdafx.h"
#include <fstream> 
#include <iostream> 
#include <map>
#include <algorithm>  
#include <string>
#include <iomanip>
#include <functional>
#include <iterator>

using namespace std;

template <typename map, typename F>
void delmap(map& my_map, F pred)
{
	typename map::iterator i = my_map.begin();
	while ((i = find_if(i, my_map.end(), pred)) != my_map.end())
		my_map.erase(i++);
}

template <class InputIterator, class Predicate>

void search(InputIterator first, InputIterator last, Predicate Pred, const string& Str) //��� ������
{

	auto p = find_if(first, last, Pred);

	if (p == last) {
		cout << Str << "������ ��������� ��� \n" << endl;
	}
	else {
		cout << "������� ������ \n";
	}
}

bool IsEven(const pair<int, char> &p) { return p.first % 2 == 0; }; //������� (����� ��������� ������ ������ map1)

int main()
{
	ofstream f;
	f.open("map.txt");

	map<int, char> map1;
	map<int, char> map2;
	map<int, char> map3;

	int key = 0, score = 0, variant = 0, exit = 0;
	char val;

	map<int, char>::iterator it;

	setlocale(LC_ALL, "Russian");

	while (exit == 0)
	{
		cout << " 1. �������� ����� ������� � map1 \n 2. �������� ����� ������� � map2";
		cout << "\n 3. �������� map 1 (�� ��������)  \n 4. ����������� ��������� � �������� \n 5. ������� map1,2 � map3";
		cout << "\n 6. ������� ��������� map3, ��������������� ������� ";
		cout << "\n 7. ����� �������� � �������� " << endl;
		cin >> variant;
		switch (variant)
		{
		case 1:
			system("cls");
			cout << "������� ����" << endl;
			cin >> key;
			cout << "������� ��������" << endl;
			cin >> val;
			map1.insert(pair<int, char>(key, val));
			break;

		case 2:
			system("cls");
			cout << "������� ����" << endl;
			cin >> key;
			cout << "������� ��������" << endl;
			cin >> val;
			map2.insert(pair<int, char>(key, val));
			break;

		case 3:
			system("cls");
			cout << "������ map" << endl;
			for (auto it = map1.rbegin(); it != map1.rend(); ++it)
			{
				cout << it->first << " => " << it->second << endl;
			}
			break;

		case 4:
			system("cls");
			copy_if(map1.begin(), map1.end(), inserter(map2, map2.end()),
				[](const pair<int, char> &p) { return p.first % 2 == 0; });
			delmap(map1, IsEven);
			cout << "������ map" << endl;
			for (auto it = map1.begin(); it != map1.end(); ++it)
			{
				cout << it->first << " => " << it->second << endl;
			}
			cout << "������ map" << endl;
			for (auto it = map2.begin(); it != map2.end(); ++it)
			{
				cout << it->first << " => " << it->second << endl;
			}
			break;

		case 5:
			system("cls");
			merge(map1.begin(), map1.end(), map2.begin(), map2.end(), inserter(map3, map3.begin()));
			for (auto it = map3.begin(); it != map3.end(); ++it)
			{
				cout << it->first << " => " << it->second << endl;
			}
			break;

		case 6:
			system("cls");
			score = count_if(map3.begin(), map3.end(), IsEven);
			if (score != 0)
			{
				cout << "������������ " << score << " ��������� map3" << endl;
			}
			else
				cout << "� map3 ��� �������������� ���������" << endl;
			break;
		case 7:
			search(map3.begin(), map3.end(), IsEven, "Even");
			break;
		}
		f.close();
	}
}