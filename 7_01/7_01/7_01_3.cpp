#include <iostream>

using namespace std;

int Result(int input);

//홀수와 짝수를 구현하라
int main()
{
	int input,result = 0;
	cout << "판별할 숫자를 입력하세요 : "; //숫자 입력 받음
	cin >> input;

	result = Result(input);
	cout << result << "  판별완료" << endl; //판별 완료문

	return 0;
}

//판별해주는 함수
int Result(int input)
{
	if (input % 2 == 0) //홀짝 기준 판별 식
	{
		cout << "짝수 입니다." << endl;  //짝수일때
	}
	else
		cout << "홀수 입니다." << endl; // 홀수 일때
	return input;
}