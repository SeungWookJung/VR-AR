#include <iostream>

using namespace std;

int main()
{
	int num1 = 0;
	int num2 = 0;

	cout << "2개의 정수를 입력하십시오." << endl;
	cin >> num1;
	cin >> num2;

	if (num1 > num2)
	{
		cout << num2 << " 보다 " << num1 << " 이 큽니다." << endl;
	}
	else if (num2 > num1)
	{
		cout << num1 << " 보다 " << num2 << " 이 큽니다." << endl;
	}
	else
	{
		cout << num1 << " 과 " << num1 << " 가 같습니다." << endl;
	}
	return 0;
}
