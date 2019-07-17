#include <iostream>

using namespace std;

int main()
{
	// && 연산자는 두 조건을 둘다 만족하는 경우
	// || 연산자는 두 조건 중 하나만 만족해도 포함되는 경우

	bool flag = true;


	if (flag)
		cout << "참을 상징합니다." << endl;

	else
		cout << "거짓을 상징 합니다." << endl;


	return 0;
}