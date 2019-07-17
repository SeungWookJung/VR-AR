#include <iostream>

using namespace std;

int main()
{
	int num = 0;

	cout << "정수를 입력하십시오 : ";
	cin >> num;

	if (num % 2 == 0)
	{
		cout << num << "(은) 는 짝수 입니다" << endl;
	}
	else
	{
		cout << num << "(은) 는 홀수 입니다" << endl;
	}
	return 0;
}
