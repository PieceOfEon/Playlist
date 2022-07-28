#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

class Playlist
{
private:

	vector <string> uList;

public:

	void createList()
	{
		
		string m;
		cin.ignore();
		while (m[0] != '0')
		{
			cout << "Enter name song:\n";
			getline(cin, m);
			if(m[0]!='0')
			uList.push_back(m);
		
		} 
	
		int count = uList.size();
		
	}

	void Print()
	{
		for (int i = 0; i < uList.size(); i++)
		{
			cout<<i+1<<"\t" << uList[i] << "\n";
		}
	}

};

int main()
{
	Playlist PL;
	
	char vvod;
	do
	{
		cout << "1 - Create Playlist:\n";
		cout << "Exit - Esc\n";
		vvod = _getch();
		switch (vvod)
		{
		case'1':
		{
			PL.createList();
			cout << "\n";
			PL.Print();
			cout << "\n";
			system("pause");
			break;

		}
		}

	
	} while (vvod != 27);


}