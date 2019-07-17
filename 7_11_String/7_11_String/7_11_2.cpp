#include <iostream>

using namespace std;

int main()
{
	while (1)
	{
		int num = 0;

		cout << "정수를 입력하세요 :";
		cin >> num;

		if (cin.fail())
		{
			cout << "잘못 입력하셨습니다\n";
			cin.clear();
			cin.ignore();

			continue;
		}

		cout << "\n입력한수 =" << num << "\n";
	}
	return 0;
}
