#include <iostream>
#include <string>


using namespace std;

int main()
{
	string str1 = "Hello";
	string str2 = "World";


	//cout << str1.capacity() << endl;
	//cout << str2.capacity() << endl;

	//string msg = "";
	//msg= str1.append(str2);
	//msg = str1 + str2;
	//cout << msg << endl;

	cout << str1.at(0) << endl;


	//.compare는 두문자열이 같은 경우  => 0
	// 다른경우 => -1
	cout << str2.compare(str1)<< endl;

	return 0;
}