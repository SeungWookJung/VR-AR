#include <iostream>

using namespace std;

int Score(int input); //성적판별 함수

//성적을 A ~ F 로 판별하는 기능 구현
int main() 
{
	int input = 0;
	cout << "시험성적을 입렵하여 주세요\t"; 
	cin >> input;  //입력값

	input = Score(input);  //성적판별 함수 호출
	
	return 0;
}

int Score(int input)
{
	if ((input >= 90) && (input<=100))
	{
		cout << "성적은 A 입니다." << endl;
	}
	else if ((input >= 80) && (input <= 89))
	{
		cout << "성적은 B 입니다. " << endl;
	}
	else if ((input >= 70) && (input <= 79))
	{
		cout << "성적은 C 입니다. " << endl;
	}
	else if ((input >= 60) && (input <= 69))
	{
		cout << "성적은 D 입니다." << endl;
	}
	else
		cout << "성적은 F 입니다." << endl;   //나머지 성적은 F

	return input;  //입력 값 반환
}