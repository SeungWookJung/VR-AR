#include <iostream>

using namespace std;

bool Func();

int Func(int num)
{
	if (num > 3)
	{
		//cout << num << endl;
		return true;
	}
	else
	{
		//cout << num << endl;
		return false;
	}
}

int main()
{
	bool flag = false;

	flag = Func(5);

	//ture = 1, false = 0
	cout << flag << endl;

	return 0;
}