#include <iostream>

using namespace std;

int main()
{
	string name = "이름";
	string language = "C++";

	int x = 10;
	int y = 10;

	if (name != language)
		cout << "두 문장은 같지 않습니다." << endl;
	else
		cout << "두 문장은 같습니다." << endl;
	if(x>=y)
		cout << "x는 y와 크거나 같습니다." << endl;
	else
		cout << "x는 보다 크거나 같지 않습니다." << endl;

	if (x >= y)
		cout << "x는 y보다 크거나 같습니다" << endl;
	else
		cout << "x는 y보다 크거나 같지 않습니다" << endl;

	if (x >= y)
		cout << "x는 20보다 작거나 같습니다" << endl;
	else
		cout << "x는 20보다 작거나 같지 않습니다." << endl;

	return 0;
}