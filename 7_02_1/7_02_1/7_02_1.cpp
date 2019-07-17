#include <iostream>
#include <string>

using namespace std;

bool IsEnd(int numPlayer)
{
	if (numPlayer == -1)
	{
		cout << "프로그램을 종료합니다." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool IsRange(int numPlayer)
{
	if ((numPlayer > 2) || (numPlayer < 0))
	{
		cout << "w잘못 입력하셨습니다." << endl;

		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int numPlayer = -1;
	cout << "(가위 = 0, 바위 = 1, 보 = 2)";
}