#include <iostream>

#include "Function.h"

using namespace std;
int main()
{
	int x, y, sum = 0;
	int count = 0;
	char z;

	while (1) {
		cout << "연산 선택 : ";
		cin >> z;



		switch (z)
		{
		case '+':
		{
			cout << "X 의 값 입력 :  ";
			cin >> x;

			cout << "Y 의 값 입력 :  ";
			cin >> y;

			sum = Add(x, y, sum);
			count += 1;
			cout << "X와 Y 의 더하기 값은" << sum << " 입니다." << endl;
			break;
		}

		case '-':
		{
			cout << "X 의 값 입력 :  ";
			cin >> x;

			cout << "Y 의 값 입력 :  ";
			cin >> y;

			sum = Min(x, y, sum);
			count += 1;
			cout << "X와 Y 의 빼기 값은" << sum << " 입니다." << endl;
			break;
		}
		case '*':
		{
			cout << "X 의 값 입력 :  ";
			cin >> x;

			cout << "Y 의 값 입력 :  ";
			cin >> y;

			sum = Mul(x, y, sum);
			count += 1;
			cout << "X와 Y 의 곱하기 값은" << sum << " 입니다." << endl;
			break;
		}
		case '/':
		{

			cout << "X 의 값 입력 :  ";
			cin >> x;

			cout << "Y 의 값 입력 :  ";
			cin >> y;

			sum = Div(x, y, sum);
			count += 1;
			cout << "X와 Y 의 나누기 값은" << sum << " 입니다." << endl;
			break;
		}
		case 'h':
		{
			if (count == 0)
			{
				cout << "아직 연산을 수행하지 않았습니다." << endl;
				break;
			}
			else
			{
				cout << "이때 까지 연산을" << count << "번 수행 했습니다" << endl;
				break;
			}
		}

		case 'q':
			{
			cout << "연산을 종료 합니다." << endl;
			break;
			}
		}
		if (z == 'q') {
			break;
		}
	}
}