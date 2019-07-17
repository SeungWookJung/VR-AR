#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "Hello World!";

	cout << str1 << endl;

	string str2;

	for (int i = 11; i >= 0; i--)
	{
		int add1 = str1[i];
		for (int j = 0; j < 12; j++)
		{
			str2[j] = add1;
		}
		cout << str2[i];
	}
	cout << "\n" << endl;

	string str3;

	for (int i = 0; i < 5; i++)
	{
		str3[i] = str1[i];
		int add1 = str1[i];
		//int add2 =;
		for (int j = 7; j < 12; j++)
		{
			
			str3[j] = add1;
		}
	}
	/*str3.a
	for (int i = 0; i < 12; i++)
	{
		cout << str3[i];
	}
	
	*/

	return 0;
}
