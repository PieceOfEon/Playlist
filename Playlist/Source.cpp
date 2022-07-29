#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>
#include <algorithm>

using namespace std;

class Playlist
{
private:

	vector <string> uList;
	vector<string> stdList;
	vector<string>plusList;

public:

	Playlist()
	{
		ListSTD();
	}

	vector <string> getUlist()
	{
		return uList;
	}

	vector<string> getstdList()
	{
		return stdList;
	}

	vector<string> getplusList()
	{
		return plusList;
	}

	void createList()
	{
		string m;
		string n;

		cin.ignore();
		do
		{
			cout << "Enter artist song:\n";
			getline(cin, m);
			if (m[0] != '0')
			{
				cout << "Enter name song:\n";
				getline(cin, n);
				if (n[0] != '0')
				{
					m += "  -  ";
					m += n;
					uList.push_back(m);
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}

		} while (m[0] != '0' || n[0] != '0');
		
	}

	void add()
	{
		Print(stdList);
		string m;
		string n;
		do
		{
			cout << "Enter artist song:\n";
			getline(cin, m);
			if (m[0] != '0')
			{
				cout << "Enter name song:\n";
				getline(cin, n);
				if (n[0] != '0')
				{
					m += "  -  ";
					m += n;
					stdList.push_back(m);
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}

		} while (m[0] != '0' || n[0] != '0');
		Print(stdList);
		
	}

	void del()
	{
		for (int i = 0; i < uList.size();i++)
		{
			cout << i << ":\t" << uList[i] << "\n";
		}
		int j;
		cout << "Enter del elem: ";
		cin >> j;
		uList.erase(uList.begin()+j);
		Print(uList);
	}

	void del2()
	{
		for (int i = 0; i < stdList.size(); i++)
		{
			cout << i << ":\t" << stdList[i] << "\n";
		}
		int j;
		cout << "Enter del elem: ";
		cin >> j;
		stdList.erase(stdList.begin() + j);
		Print(stdList);
	}

	void del3()
	{
		for (int i = 0; i < plusList.size(); i++)
		{
			cout << i << ":\t" << plusList[i] << "\n";
		}
		int j;
		cout << "Enter del elem: ";
		cin >> j;
		plusList.erase(plusList.begin() + j);
		Print(plusList);
	}

	void ListSTD()
	{
		string a;
		/*vector<string> stdList(10);*/
		a = "Egor Kreed - We Gotta Get Love";
		stdList.push_back(a);
		a = "Skriptonit, 104 - Ты это серъезно?";
		stdList.push_back(a);
		a = "Три Дня Дождя - Слабый человек";
		stdList.push_back(a);
		a = "HADES, Mingue - Drugs";
		stdList.push_back(a);
		a = "Bakhtin - Молодой";
		stdList.push_back(a);
		a = "10AGE - Мандариновые горы";
		stdList.push_back(a);
		a = "Mnogocnaal - Антигерой";
		stdList.push_back(a);
		a = "Clonnex,  Вышел покурить - Беспредел Remix";
		stdList.push_back(a);
		a = "miroshland, Aikko - Все сказал";
		stdList.push_back(a);
		a = "STED.D - ФИНИТА";
		stdList.push_back(a);

	}

	void search()
	{
		string a;
		cout << "Enter search name:\n";
		getline(cin, a);
		

		/*vector<string>::iterator it = find(stdList.begin(), stdList.end(), a);*/
		
		vector<string>::iterator it = find(stdList.begin(), stdList.end(), a);
			
			if (it == stdList.end())
			{
				cout << "Ne alo\n";
			}
			else
			{
				cout << "Alo\n";
			}
			
		
		
	}

	void Print(vector <string> List)
	{
		cout << setw(15) << "Number song" << setw(30) << "Artist and Name song\n\n";
		for (int i = 0; i < List.size(); i++)
		{
			cout << setw(15) << i + 1 << ":\t" << setw(5) << List[i] << "\n";
		}
	}

	void uniteList(vector<string> stdList, vector<string> uList)
	{
		plusList.clear();
		for (int i = 0; i < uList.size(); i++)
		{
			plusList.push_back(uList[i]);
		}
		for (int i = 0; i < stdList.size(); i++)
		{
			plusList.push_back(stdList[i]);
		}
		
	}

	~Playlist()
	{

	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	Playlist PL;
	
	char vvod;
	do
	{
		cout << "1 - Create Playlist:\n";
		cout << "2 - std PlayList\n";
		cout << "3 - List+List\n";
		cout << "4 - Del MyPlaylist song\n";
		cout << "5 - Del stdPlaylist song\n";
		cout << "6 - Del List+List song\n";
		cout << "7 - Add song\n";
		cout << "Exit - Esc\n";
		vvod = _getch();
		switch (vvod)
		{
		case'1':
		{
			PL.createList();
			cout << "\n";
			PL.Print(PL.getUlist());
			cout << "\n";
			system("pause");
			break;

		}
		case'2':
		{
			
			PL.Print(PL.getstdList());
			cout << "\n";
			system("pause");
			break;
		}
		case'3':
		{
			PL.uniteList(PL.getUlist(), PL.getstdList());
			cout << "\n";
			PL.Print(PL.getplusList());
			cout << "\n";
			system("pause");
			break;

		}
		case'4':
		{
			int a;
			PL.del();
			cout << "\n";
			system("pause");
			break;

		}
		case'5':
		{
			PL.del2();
			cout << "\n";
			system("pause");
			break;

		}
		case'6':
		{
			PL.del3();
			cout << "\n";
			system("pause");
			break;
		}
		case'7':
		{

			PL.add();
			cout << "\n";
			system("pause");
			break;
		}
		case'8':
		{

			PL.search(PL.getstdList());
			cout << "\n";
			system("pause");
			break;
		}
		}


	
	} while (vvod != 27);


}