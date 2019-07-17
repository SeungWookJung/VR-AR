#include <iostream>

using namespace std;

int main()
{
	int score = 0;
	int result = 0;

	while (1)
	{
		cout << "시험점수를 입력하세요 : ";
		cin >> score;
		result += score;
		if (score == 0)
		{
			break;
		}
	}
	cout << "시험 점수의 합계는 " << result << " 점 입니다." << endl;
	return 0;
}
