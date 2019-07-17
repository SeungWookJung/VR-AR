#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void Game_(string input,string C_result);
string C_rand();

//컴퓨터와 랜덤 가위,바위,보를 하는 게임
int main()
{	
	srand((unsigned int)time(NULL));
	string C_result = C_rand(); //컴퓨터 랜덤 가위,바위 ,보
	

	string input;
	cout << "가위 바위 보 중에 하나를 입력하세요 : ";
	cin >> input;

	Game_(input,C_result); // 컴퓨터와 대결하는 함수로 보낸다. 컴퓨터의 랜덤 문자열 ,사람이 정한 문자열
	return 0;
}

//컴퓨터와 사용자가 대결하는 함수
void Game_(string input, string C_result)
{
	if ((input == "가위") && (C_result == "바위"))
	{
		cout << "컴퓨터가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else if ((input == "가위") && (C_result == "보"))
	{
		cout << "사용자가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else if ((input == "바위") && (C_result == "가위"))
	{
		cout << "사용자가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else if ((input == "바위") && (C_result == "보"))
	{
		cout << "컴퓨터가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else if ((input == "보") && (C_result == "가위"))
	{
		cout << "컴퓨터가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else if ((input == "보") && (C_result == "바위"))
	{
		cout << "사용자가 이겼습니다. \t" << "사람 = " << input << " 컴퓨터 = " << C_result << endl;
	}
	else
		cout<<"무승부 입니다."<< "사람 = " << input << " 컴퓨터 = " << C_result << endl;
}

//컴퓨터의 랜덤 가위바위 보를 뽑아 주는수
string C_rand() 
{
	string C_result;
	srand(time(NULL));
	int result = rand() % (3 + 1);
	
	if (result == 1)
	{
		C_result = "가위";
		return C_result;
	}
	else if (result == 2)
	{
		C_result = "바위";
		return C_result;
	}
	else
		C_result = "보";

	return C_result;
}