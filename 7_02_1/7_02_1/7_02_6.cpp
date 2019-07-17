#include <iostream>

using namespace std;

void Test_setprecision()
{
	float num1 = 3.1423f;
	float num2 = 5.4575635f;

	//cout << setprecision(5);
	//cout << setw(5)<< num1 << endl;
	cout << num2 << endl;

}

void Test_setfill()
{
	int num1 = 32;
	int num2 = 834;

	cout << "|" << num1 << "|" << endl;
	cout << "|" << num2 << "|" << endl;
}

int main()
{
	//Test_setfill();
	Test_setprecision();

	return 0;
}
