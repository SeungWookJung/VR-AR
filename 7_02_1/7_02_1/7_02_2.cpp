#include <iostream>

using namespace std;


int GetRand(int max = 3)
{
	int num = rand() % (max + 1);
	return (num);
}

string Convert(int codeNum)
{
	string msg = "";
	if (codeNum == 0)
		msg = "가위";
	else if (codeNum == 1)
		msg = "바위";
	else if (codeNum == 2)
		msg = "보";
	return msg;
}

// (가위=0, 바위=1, 보=2)
// ( 1 승리 , 0 무승부 , -1 패배 )
int PlayGame(int player, int computer)
{
	cout << "player  : " << Convert(player) << endl;
	cout << "computer: " << Convert(computer) << endl;

	if (player == computer)	// 무승부
	{
		cout << "비겼습니다." << endl;
		return 0;
	}
	else if (player == 0)	// 승리 1
	{
		if (computer == 2)
			return 1;
	}
	else if (player == 1)	// 승리 2
	{
		if (computer == 0)
			return 1;
	}
	else if (player == 2)	// 승리 3
	{
		if (computer == 1)
			return 1;
	}
	else
	{
		cout << "패배했습니다." << endl;
		return -1;
	}
}

bool IsEnd(int numPlayer)
{
	if (numPlayer == -1)
	{
		cout << "프로그램을 종료합니다." << endl;
		exit(0);
	}
}

bool IsRange(int numPlayer)
{
	if ((numPlayer > 2) || (numPlayer < 0))
	{
		cout << "잘못 입력하셨습니다." << endl;

		return true;
	}
	else
	{
		return false;
	}
	return false;
}

int main()
{

	while (true)
	{
		int numComputer = GetRand();
		int numPlayer = -1;

		cout << "(가위=0, 바위=1, 보=2) 종료= -1 \n"
			<< "Player: ";
		cin >> numPlayer;

		// 종료 확인
		IsEnd(numPlayer);
		//조건확인
		IsRange(numPlayer);

		//	(1 승리, 0 무승부, -1 패배)
		int result = PlayGame(numPlayer, numComputer);
		switch (result)
		{
		case -1:
			cout << "패배했습니다.\n";
			break;
		case 0:
			cout << "비겼습니다.\n";
			break;
		case 1:
			cout << "이겼습니다.\n";
			break;
		}

		cout << "\n\n";
	}


	return 0;
}
