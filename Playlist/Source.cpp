#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>
#include<fstream>

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
		a = "Egor Kreed - We Gotta Get Love";
		stdList.push_back(a);
		a = "Skriptonit, 104 - ti eto serezno?";
		stdList.push_back(a);
		a = "Tri dnya dojdya - slabiy chelovek";
		stdList.push_back(a);
		a = "HADES, Mingue - Drugs";
		stdList.push_back(a);
		a = "Bakhtin - molodoy";
		stdList.push_back(a);
		a = "10AGE - Mandarinovie gory";
		stdList.push_back(a);
		a = "Mnogocnaal - Antigeroi";
		stdList.push_back(a);
		a = "Clonnex,  vishel pokurit - Bespredel Remix";
		stdList.push_back(a);
		a = "Miroshland, Aikko - Vse skazal";
		stdList.push_back(a);
		a = "STED.D - FINITA";
		stdList.push_back(a);

	}

	void search(vector <string> List)
	{
		string a;
		cout << "Enter search name:\n";
		cin.ignore();
		getline(cin, a);
		bool b=false;
		for (int i = 0; i < List.size(); i++)
		{
			
			if (!List[i].find(a))
			{
				cout <<i+1<<"\t" << List[i] << "\n";
				b = true;
			}
		}
		if (b == false)
		{
			cout << "Ne nashlos'\n";
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

	void WriteSave(vector <string> List)
	{
		ofstream outfile("PlayList2.txt", ios::app);
		for (int i = 0; i < List.size(); i++)
		{
			outfile << List[i]<<"\n";
		}
		cout << "\n";
		outfile.close();
	}

	void Write(vector <string> List)
	{
		ofstream outfile("PlayList2.txt");
		for (int i = 0; i < List.size(); i++)
		{
			outfile << List[i] << "\n";
		}
		cout << "\n";
		outfile.close();
	}

	void Read()
	{
		string s;
		ifstream outfile("PlayList2.txt");
		if (outfile.is_open())
		{
			int i = 0;
			while (!outfile.eof())
			{
				getline(outfile, s);
				
				if (s.size() > 0) // ubiraem lishniy \n pri schitivanii
				{
					plusList.resize(i + 1);
					plusList[i] = s;
					i++;
				}
			}
		}
		outfile.close();
		cout << "\n";
	}

	void ReadPrint()
	{
		for (int i = 0; i < plusList.size(); i++)
		{
			cout << i + 1<<": " << plusList[i] << "\n";
		}
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	Playlist PL;
	int vvod;
	do
	{
		system("cls");
		cout << "1 - Create Playlist:\n";
		cout << "2 - std PlayList\n";
		cout << "3 - List+List\n";
		cout << "4 - Del MyPlaylist song\n";
		cout << "5 - Del stdPlaylist song\n";
		cout << "6 - Del List+List song\n";
		cout << "7 - Add to std\n";
		cout << "8 - Search\n";
		cout << "9 - WriteSave\n";
		cout << "10 - Write Create List\n";
		cout << "11 - Read plus list\n";
		cout << "12 - PrintMy\n";
		cout << "13 - Print+\n";
		cout << "14 - PrintSTD\n";
		cout << "Exit - Enter 0\n";
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			PL.createList();
			cout << "\n";
			PL.Print(PL.getUlist());
			cout << "\n";
			system("pause");
			break;

		}
		case 2:
		{
			PL.Print(PL.getstdList());
			cout << "\n";
			system("pause");
			break;
		}
		case 3:
		{
			PL.uniteList(PL.getUlist(), PL.getstdList());
			cout << "\n";
			PL.Print(PL.getplusList());
			cout << "\n";
			system("pause");
			break;

		}
		case 4:
		{
			int a;
			PL.del();
			cout << "\n";
			system("pause");
			break;
		}
		case 5:
		{
			PL.del2();
			cout << "\n";
			system("pause");
			break;
		}
		case 6:
		{
			PL.del3();
			cout << "\n";
			system("pause");
			break;
		}
		case 7:
		{
			PL.add();
			cout << "\n";
			system("pause");
			break;
		}
		case 8:
		{
			PL.search(PL.getstdList());
			cout << "\n";
			system("pause");
			break;
		}
		case 9:
		{
			PL.WriteSave(PL.getplusList());
			cout << "\n";
			system("pause");
			break;
		}
		case 10:
		{
			PL.Write(PL.getUlist());
			cout << "\n";
			system("pause");
			break;
		}
		case 11:
		{
			PL.Read();
			PL.ReadPrint();
			cout << "\n";
			system("pause");
			break;
		}
		case 12:
		{
			PL.Print(PL.getUlist());
			cout << "\n";
			system("pause");
			break;
		}
		case 13:
		{
			PL.Print(PL.getplusList());
			cout << "\n";
			system("pause");
			break;
		}
		case 14:
		{
			PL.Print(PL.getstdList());
			cout << "\n";
			system("pause");
			break;
		}
		}
	} while (vvod != 0);
}