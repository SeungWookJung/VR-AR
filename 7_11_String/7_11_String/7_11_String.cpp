#include <iostream>

using namespace std;

int main()
{

	//비교시 다르면 -1
	//같으면 0,크다 1
	string str1 = "ABC";
	string str2 = "ABC";
	cout << "str1 : " << str1 <<" str2 : "<< str2<<endl;

	cout<<str1.compare(str2)<<endl;

	if (str1.compare(str2) == 0)
	{
		cout << "두 문자열은 같습니다" << endl;
	}
	if (str1 == str2)
	{
		cout << "@@@두 문자열은 같습니다" << endl;
	}

	str1.clear();
	str1 = "DEF";
	str2.clear();
	str2 = "DEF";

	cout << "str1 : " << str1 << " str2 : " << str2 << endl;

	cout << str1.compare(str2) << endl;

	return 0;
}
