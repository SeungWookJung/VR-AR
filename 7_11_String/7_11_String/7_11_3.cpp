#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("1.txt");
	if (fout.fail())
	{
		cout << "fail...\n";
	}

	fout << 3 << " abx" << endl;

	fout.close();

	ifstream fin;
	fin.open("1.txt");
	if (fin.fail())
	{
		cout << "fail...\n";
	}

	int num;
	string str;
	fin >> num >> str;

	cout << num << endl << str << endl;

	fin.close();

	return 0;
}
