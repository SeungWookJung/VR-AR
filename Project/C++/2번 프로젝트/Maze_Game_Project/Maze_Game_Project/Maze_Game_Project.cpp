#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

//////각 난이도의 크기/////

#define EASY_X 22
#define EASY_Y 22

#define NORMAL_X 28
#define NORMAL_Y 28

#define HARD_X 38
#define HARD_Y 38

ifstream scoreFile;
////////함수들///////////

void MainUi(); //메인 화면
void DifficultyMenu(); //난이도 조절 화면
void MenuScore();//저장된 스코어 표시
void Difficulty(); //난이도 조절함수
int Hp = 100;//cpp에서 체력이 안불러와져 임시
void setcolor(int color, int bgcolor); //색상 조절 함수


//난이도 별 미로 출력
void Map_Print_Easy(char Map_Easy[EASY_X][EASY_Y]);
void Map_Print_Normal(char Map_Normal[NORMAL_X][NORMAL_Y]);
void Map_Print_Hard(char Map_Hard[HARD_X][HARD_Y]);

//난이도별 플레이어 이동함수
void MovePlayer_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p, char input);
void MovePlayer_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p, char input);
void MovePlayer_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p, char input);

//난이도별 플레이어 이동 함수(상,하,좌,우)
void MoveUp_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p);
void MoveDown_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p);
void MoveLeft_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p);
void MoveRight_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p);

void MoveUp_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p);
void MoveDown_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p);
void MoveLeft_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p);
void MoveRight_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p);

void MoveUp_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p);
void MoveDown_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p);
void MoveLeft_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p);
void MoveRight_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p);

////////////////////////////
typedef struct PlayerScore
{
	string name;
	int score;
	string difficulty;
}one;


/*
수정자 : 정승욱
수정 날짜 : 2019-07-21
수정내용 : 맵 크기 조절, 점수 저장 텍스쳐에 색상 입히기
*/

int main()
{
	int Choice = 0;

	while (1)
	{
		MainUi(); //메인 UI
		cin >> Choice;

		if (Choice == 1)
		{
			Difficulty();
		}
		
		else if (Choice == 2)
		{
			MenuScore();
		}
		else if (Choice == 0)
		{
			cout << "\t\t 사용해주셔서 감사합니다." << endl;
			cout << "\t\t 종료 되었습니다." << endl;
			exit(1);
		}
		else
		{
			cout << "\t" << " 잘못 입렵하셨습니다. 다시입력해 주세요. " << endl;
			Choice = 0;
		}
	}

	return 0;
}



//메인 시작화면
void MainUi()
{
	cout << "\t\t------------------------------------------" << endl;

	cout << "\t\t*             1. 게임 시작               *" << endl;

	cout << "\t\t*             2. 점수 화면               *" << endl;

	cout << "\t\t*              0. 종  료                 *" << endl;

	cout << "\t\t*                                        *" << endl;

	cout << "\t\t------------------------------------------" << endl;
}

// 난이도 선택 메뉴판
void DifficultyMenu()
{
	cout << "\t\t------------------------------------------" << endl;

	cout << "\t\t*\t\t" << "1.  Easy  " << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "2.  Normal" << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "3.  Hard  " << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "0.  메인화면" << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "\t\t\t *" << endl;

	cout << "\t\t------------------------------------------" << endl;
}

//점수 출력 함수
void MenuScore()
{
	system("cls");

	cout << "\t\t*\t   스코어를 표시합니다.\n\n";

	cout<< "\t\t이름\t\t점수\t난이도\n" << endl;

	vector<PlayerScore> clas;

	PlayerScore ps;

	fstream op;

	string temp_name;
	int temp_score = 0;
	string temp_difficulty;
	
	string in_line;
	

	op.open("score.txt",ios::in);
	if (!op.is_open())
	{
		cout << "\t\t\t저장된 기록이 없습니다.\n";
		return;
		
	}
	while (op >> ps.name)
	{
		op >> ps.score;
		op >> ps.difficulty;
		clas.push_back(ps);
	}
	op.close();
	
	for (int i = 0; i < size(clas)-1; i++)
	{
		for (int j = i + 1; j < size(clas); j++)
		{
			if (clas[i].score < clas[j].score)
			{
				temp_name = clas[i].name;
				temp_score = clas[i].score;
				temp_difficulty = clas[i].difficulty;

				clas[i].name = clas[j].name;
				clas[i].score = clas[j].score;
				clas[i].difficulty = clas[j].difficulty;

				clas[j].name = temp_name;
				clas[j].score = temp_score;
				clas[j].difficulty = temp_difficulty;
			}
		}
	}

	op.open("score.txt", ios::out);

	for (int i = 0; i < size(clas); i++)
	{
		op << clas[i].name << "\t" << clas[i].score 
			<< "\t" << clas[i].difficulty << endl;
	}
	op.close();

	

	ifstream in("score.txt");

	while (getline(in, in_line)) 
	{
		cout <<"\t\t"<< in_line << endl;
	}
	in.close();

	
}



//색상 선택 함수
void setcolor(int color, int bgcolor)

{
	color &= 0xf;

	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//난이도 선택 함수
void Difficulty()
{
	char Map_Easy[EASY_X][EASY_Y];
	char Map_Normal[NORMAL_X][NORMAL_Y];
	char Map_Hard[HARD_X][HARD_X];


	int difficulty;

	while (1)
	{
		system("cls");
		DifficultyMenu();
		cin >> difficulty;

		if (difficulty == 0) //메인으로 돌아감
		{
			break;
		}

		if (difficulty == 1)// 난이도 쉬움
		{
			Map_Print_Easy(Map_Easy);
			break;
		}

		else if (difficulty == 2)// 난이도 중간
		{
			Map_Print_Normal(Map_Normal);
			break;
		}
		else if (difficulty == 3)// 난이도 어려움
		{
			Map_Print_Hard(Map_Hard);
			break;
		}
		else
			cout << "\t" << " 잘못 입렵하셨습니다. 다시입력해 주세요. " << endl;
	}

}

//난이도 Easy

void MoveUp_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() - 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(-1);
		}
	}
}
void MoveDown_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p)
{
	if (p.GetNow_Y() + 1 < 21)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() + 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(1);
		}
	}
}
void MoveLeft_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p)
{
	if (p.GetNow_X() - 1 < 21)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() - 1] != '0')
		{
			p.SetNow_X(-1);
		}
	}
}
void MoveRight_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p)
{
	if (p.GetNow_X() + 1 < 21)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() + 1] != '0')
		{
			p.SetNow_X(1);
		}
	}
}

void MovePlayer_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p, char input) //플레이어를 움직이는 함수
{
	switch (input)
	{
	case 'w':
	case 'W':
		MoveUp_Easy(Map_difficulty, p);
		break;
	case 's':
	case 'S':
		MoveDown_Easy(Map_difficulty, p);
		break;
	case 'a':
	case 'A':
		MoveLeft_Easy(Map_difficulty, p);
		break;
	case 'd':
	case 'D':
		MoveRight_Easy(Map_difficulty, p);
		break;
	}
}

/*맵
	0. 벽
	1. 통로
	2. 시작점
	3. 종료점s
*/

//난이도 Easy 맵
void Map_Print_Easy(char Map_Easy[EASY_X][EASY_Y])
{
	Player p;
	p.SetEnd(19, 19);

	clock_t start = 0, end = 0;
	start = clock(); //타이머 시작

	strcpy_s(Map_Easy[0], "000000000000000000000");
	strcpy_s(Map_Easy[1], "020111111111110111110");
	strcpy_s(Map_Easy[2], "010100000000010100010");
	strcpy_s(Map_Easy[3], "010101111101110111010");
	strcpy_s(Map_Easy[4], "010101010001000101010");
	strcpy_s(Map_Easy[5], "010101010111011101010");
	strcpy_s(Map_Easy[6], "010101010100000001010");
	strcpy_s(Map_Easy[7], "011101010101111111010");
	strcpy_s(Map_Easy[8], "000001010101000000010");
	strcpy_s(Map_Easy[9], "011101010101011111010");
	strcpy_s(Map_Easy[10], "000101010101000100010");
	strcpy_s(Map_Easy[11], "011101011101110111010");
	strcpy_s(Map_Easy[12], "010101000000010101010");
	strcpy_s(Map_Easy[13], "010101011111110101110");
	strcpy_s(Map_Easy[14], "010101000101000100000");
	strcpy_s(Map_Easy[15], "010101110101011111110");
	strcpy_s(Map_Easy[16], "010100010101000000010");
	strcpy_s(Map_Easy[17], "010101110101110111110");
	strcpy_s(Map_Easy[18], "010001000000010100000");
	strcpy_s(Map_Easy[19], "011111111111110111130");
	strcpy_s(Map_Easy[20], "000000000000000000000");

	while (1)
	{
		system("cls");

		for (int i = 0; i < EASY_X; i++)
		{
			for (int j = 0; j < EASY_Y; j++)
			{

				if (p.GetNow_X() == j && p.GetNow_Y() == i)
				{
					setcolor(10, 0);
					cout << "▼";

				}
				else if (Map_Easy[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "■";
				}
				else if (Map_Easy[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Easy[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "▽";
				}
				else if (Map_Easy[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "◎";
				}
			}

			cout << endl;
		}
		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y()) //종료 지점에 도착시 점수저장
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10); //점수 계산은 (걸린 시간 *100)+(체력 *10) 입니다.

			string name; //플레이어 이름

			p.SetScore(scoreResult);

			cout << "도착했습니다.  완료시간은 : " << endTime << " 초 입니다." << endl;
			cout << "점수는 " << p.GetScore() << " 점 입니다." << endl;
			cout << "점수 입력을 위해 이름을 입력해 주세요 : ";
			cin >> name;


			scoreFile.open("score.txt"); //파일을 읽어온다.

			if (!scoreFile) //만약 파일이 없을경우
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " EASY" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}
			else //있는경우 뒤에 붙여서 작성
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " EASY" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}

			p.clear(); //Player 클래스 초기화
			break;
		}

		cout << "W : 위  S : 아래  A : 왼쪽  D : 오른쪽" << endl;


		char input = _getch();
		MovePlayer_Easy(Map_Easy, p, input);
	}

}

//난이도 Normal

void MoveUp_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() - 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(-1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
	}
}
void MoveDown_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p)
{
	if (p.GetNow_Y() + 1 < 26)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() + 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
	}
}
void MoveLeft_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p)
{
	if (p.GetNow_X() - 1 < 26)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() - 1] != '0')
		{
			p.SetNow_X(-1);
		}
		 if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
	}
}
void MoveRight_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p)
{
	if (p.GetNow_X() + 1 < 26)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() + 1] != '0')
		{
			p.SetNow_X(1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
	}
}







void MovePlayer_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p, char input) //플레이어를 움직이는 함수
{
	switch (input)
	{
	case 'w':
	case 'W':
		MoveUp_Normal(Map_difficulty, p);
		
		break;
	case 's':
	case 'S':
		MoveDown_Normal(Map_difficulty, p);
		
		break;
	case 'a':
	case 'A':
		MoveLeft_Normal(Map_difficulty, p);
		
		break;
	case 'd':
	case 'D':
		MoveRight_Normal(Map_difficulty, p);
		
		break;
	}
}
//난이도 Normal 맵
void Map_Print_Normal(char Map_Normal[NORMAL_X][NORMAL_Y])
{
	Player p;
	p.SetEnd(24, 24);

	clock_t start = 0, end = 0;
	start = clock(); //타이머 시작

	strcpy_s(Map_Normal[0], "000000000000000000000000000");
	strcpy_s(Map_Normal[1], "021111011104111111011114110");
	strcpy_s(Map_Normal[2], "000001010100010004000000010");
	strcpy_s(Map_Normal[3], "011101010111110101110111110");
	strcpy_s(Map_Normal[4], "000101010000000100010100010");
	strcpy_s(Map_Normal[5], "011101010111011111010411010");
	strcpy_s(Map_Normal[6], "010001010101000100010101000");
	strcpy_s(Map_Normal[7], "040111010101110111110101110");
	strcpy_s(Map_Normal[8], "010100010100010001000001010");
	strcpy_s(Map_Normal[9], "011101110101011104111101040");
	strcpy_s(Map_Normal[10], "010001010104000100000101010");
	strcpy_s(Map_Normal[11], "010111010111010101111101010");
	strcpy_s(Map_Normal[12], "040100010001010100010000010");
	strcpy_s(Map_Normal[13], "010111041111410111010111110");
	strcpy_s(Map_Normal[14], "010000000100000001010100010");
	strcpy_s(Map_Normal[15], "011101410111011111010141010");
	strcpy_s(Map_Normal[16], "000101010001010000010001010");
	strcpy_s(Map_Normal[17], "010101011101011101411111010");
	strcpy_s(Map_Normal[18], "010101000100000100000000010");
	strcpy_s(Map_Normal[19], "010101110101110111410111010");
	strcpy_s(Map_Normal[20], "040104010101010000010101040");
	strcpy_s(Map_Normal[21], "010101010101010111110101010");
	strcpy_s(Map_Normal[22], "011101010101010101110101010");
	strcpy_s(Map_Normal[23], "010000010101010104000101010");
	strcpy_s(Map_Normal[24], "014111110111011101111101130");
	strcpy_s(Map_Normal[25], "000000000000000000000000000");




	while (1)
	{
		system("cls");

		for (int i = 0; i < NORMAL_X; i++)
		{
			for (int j = 0; j < NORMAL_Y; j++)
			{
				if (p.GetNow_X() == j && p.GetNow_Y() == i)
				{
					setcolor(10, 0);
					cout << "▼";
				}
				else if (Map_Normal[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "■";
				}
				else if (Map_Normal[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Normal[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "▽";
				}
				else if (Map_Normal[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "◎";
				}
				else if (Map_Normal[i][j] == '4')
				{			
					setcolor(13, 0);
					cout << "●";
				}

			}
			cout << endl;
		}

		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y())
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10)+(p.GetMonsterKill()*1000); //점수 계산은 (걸린 시간 *100)+(체력 *10) 입니다.

			string name; //플레이어 이름

			p.SetScore(scoreResult);

			cout << "도착했습니다.  완료시간은 : " << endTime << " 초 입니다." << endl;
			cout << "점수는 " << p.GetScore() << " 점 입니다." << endl;
			cout << "점수 입력을 위해 이름을 입력해 주세요 : ";
			cin >> name;


			scoreFile.open("score.txt"); //파일을 읽어온다.

			if (!scoreFile) //만약 파일이 없을경우
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " NORMAL" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}
			else //있는경우 뒤에 붙여서 작성
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " NORMAL" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}

			p.clear(); //Player 클래스 초기화
			break;
		}
		cout << "W : 위  S : 아래  A : 왼쪽  D : 오른쪽" << endl;

		cout << "노말난이도부터는 함정(●)이 등장합니다.\n";
		
		cout << "몬스터 처지 : " << p.GetMonsterKill() << endl;

		cout << "현재 HP : " << p.GetHP() << endl;

		if (p.GetHP() == 0)
		{
			cout << "채력이 다 떨어졌습니다.\n";

			p.clear(); 
			break;
		}

		
		char input = _getch();
		MovePlayer_Normal(Map_Normal, p, input);
	}
}

//난이도 Hard

void MoveUp_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() - 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(-1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//벽일때
		{
			if (p.GetKey()>0)
			{
				Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

				p.SetKey(-1);
			}
			 if (p.GetKey() == 0)
			{
				p.SetNow_Y(-1);
			}
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//키를 흭득했을때
		{
			p.SetKey(1);

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

		}
	}
}
void MoveDown_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p)
{
	if (p.GetNow_Y() + 1 < 36)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y() + 1][p.GetNow_X()] != '0')
		{
			p.SetNow_Y(1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//벽일때
		{
			if (p.GetKey() > 0)
			{
				Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

				p.SetKey(-1);
			}
			if (p.GetKey() == 0)
			{
				p.SetNow_Y(-1);
			}
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//키를 흭득했을때
		{
			p.SetKey(1);

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

		}
	}
}
void MoveLeft_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p)
{
	if (p.GetNow_X() - 1 < 36)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() - 1] != '0')
		{
			p.SetNow_X(-1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//벽일때
		{
			if (p.GetKey() > 0)
			{
				Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

				p.SetKey(-1);
			}
			 if (p.GetKey() == 0)
			{
				p.SetNow_X(-1);
			}
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//키를 흭득했을때
		{
			p.SetKey(1);

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

		}
	}
}
void MoveRight_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p)
{
	if (p.GetNow_X() + 1 < 36)
	{
		//벽인지 체크
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() + 1] != '0')
		{
			p.SetNow_X(1);
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '4')
		{
			p.Attack();

			p.MonsterKill();

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//벽일때
		{
			if (p.GetKey() > 0)
			{
				Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

				p.SetKey(-1);
			}
			 if (p.GetKey() == 0)
			{
				p.SetNow_X(1);
			}
		}
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//키를 흭득했을때
		{
			p.SetKey(1);

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

		}
	}
}




void MovePlayer_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p, char input) //플레이어를 움직이는 함수
{
	switch (input)
	{
	case 'w':
	case 'W':
		MoveUp_Hard(Map_difficulty, p);
		break;
	case 's':
	case 'S':
		MoveDown_Hard(Map_difficulty, p);
		break;
	case 'a':
	case 'A':
		MoveLeft_Hard(Map_difficulty, p);
		break;
	case 'd':
	case 'D':
		MoveRight_Hard(Map_difficulty, p);
		break;
	}
}


//난이도 Hard 맵
void Map_Print_Hard(char Map_Hard[HARD_X][HARD_Y])
{
	Player p;
	p.SetHP(50);
	p.SetEnd(35, 35);

	clock_t start = 0, end = 0;
	start = clock(); //타이머 시작


	strcpy_s(Map_Hard[0],  "0000000000000000000000000000000000000");
	strcpy_s(Map_Hard[1],  "0111010114111101141111011411110111110");
	strcpy_s(Map_Hard[2],  "0001010101000001010000010001000104000");
	strcpy_s(Map_Hard[3],  "0111014101114111010111011101011101110");
	strcpy_s(Map_Hard[4],  "0100000000010000010101000101010000010");
	strcpy_s(Map_Hard[5],  "0111111111011101110101111101110141010");
	strcpy_s(Map_Hard[6],  "0000000001000001000100000000000101010");
	strcpy_s(Map_Hard[7],  "0111111111011101110401011111011101110");
	strcpy_s(Map_Hard[8],  "0100000000010100010101010001010000010");
	strcpy_s(Map_Hard[9],  "0111014101110111011101011101011101110");
	strcpy_s(Map_Hard[10], "0001010101000001010001000101000101000");
	strcpy_s(Map_Hard[11], "0101010111041101011111010101411101050");
	strcpy_s(Map_Hard[12], "0101010000010001000001010100000001010");
	strcpy_s(Map_Hard[13], "0401011101111111011111110111011101010");
	strcpy_s(Map_Hard[14], "0101040101000000000001000001000101010");
	strcpy_s(Map_Hard[15], "0111010101110111111101011101014101010");
	strcpy_s(Map_Hard[16], "0100000100010100010100010101010001010");
	strcpy_s(Map_Hard[17], "0411111101010101110411010111011101010");
	strcpy_s(Map_Hard[18], "0000000001010401000001010000010104010");
	strcpy_s(Map_Hard[19], "0111110141110101011111110111010111010");
	strcpy_s(Map_Hard[20], "0100010100000101000000000101010000010");
	strcpy_s(Map_Hard[21], "0101110101110101011101011101010111110");
	strcpy_s(Map_Hard[22], "0001000101000101010101010001010100010");
	strcpy_s(Map_Hard[23], "0141011101111101110101011101010111010");
	strcpy_s(Map_Hard[24], "0100010000000400000101000101010001010");
	strcpy_s(Map_Hard[25], "0101110111110101111101011101010111010");
	strcpy_s(Map_Hard[26], "0101000100010101000001040001010100010");
	strcpy_s(Map_Hard[27], "0111011101110101110111111101010101110");
	strcpy_s(Map_Hard[28], "0100010001000100010000000101010100010");
	strcpy_s(Map_Hard[29], "0101410111110141011111011101010111010");
	strcpy_s(Map_Hard[30], "0101010000010001000001010004010101000");
	strcpy_s(Map_Hard[31], "0101011101011101010111010101040101110");
	strcpy_s(Map_Hard[32], "0100010101000101010100010101010000010");
	strcpy_s(Map_Hard[33], "0111010101110101110101040101011101110");
	strcpy_s(Map_Hard[34], "0001000101040100000101010101000101060");
	strcpy_s(Map_Hard[35], "0111114101011111114101111101111141030");
	strcpy_s(Map_Hard[36], "0000000000000000000000000000000000000");


	while (1)
	{
		system("cls");

		for (int i = 0; i < HARD_X; i++)
		{
			for (int j = 0; j < HARD_Y; j++)
			{
				if (p.GetNow_X() == j && p.GetNow_Y() == i)
				{
					setcolor(10, 0);
					cout << "▼";
				}
				else if (Map_Hard[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "■";
				}
				else if (Map_Hard[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Hard[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "▽";
				}
				else if (Map_Hard[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "◎";
				}
				else if (Map_Hard[i][j] == '4')
				{
					setcolor(13, 0);
					cout << "●";
				}
				else if (Map_Hard[i][j] == '5')
				{
					setcolor(14, 0);
					cout << "∮";
				}
				else if (Map_Hard[i][j] == '6')
				{
					setcolor(6, 0);
					cout << "▥";
				}
			}
			cout << endl;
		}

		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y()) //종료지점 도착
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10)+(p.GetMonsterKill()*1000); //점수 계산은 (걸린 시간 *100)+(체력 *10)+(몬스터 처리수 *1000) 입니다.

			string name; //플레이어 이름

			p.SetScore(scoreResult);

			cout << "도착했습니다.  완료시간은 : " << endTime << " 초 입니다." << endl;
			cout << "점수는 " << p.GetScore() << " 점 입니다." << endl;
			cout << "점수 입력을 위해 이름을 입력해 주세요 : ";
			cin >> name;


			scoreFile.open("score.txt"); //파일을 읽어온다.

			if (!scoreFile) //만약 파일이 없을경우
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " HARD" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}
			else //있는경우 뒤에 붙여서 작성
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " HARD" << endl;
				scoreOut.close();
				cout << "저장 되었습니다." << endl;
			}

			p.clear(); //Player 클래스 초기화
			break;
		}
		cout << "W : 위  S : 아래  A : 왼쪽  D : 오른쪽" << endl;

		cout << "하드난이도는 많은 몬스터(●)가 등장합니다.\n";

		cout << "벽(▥)을 통과하기 위해서는 키(∮)가 필요합니다." << endl;

		cout << "키 갯수 : " << p.GetKey() << endl;

		cout << "몬스터 처지 : " << p.GetMonsterKill() << endl;

		cout << "현재 HP : " << p.GetHP() << endl;

		if (p.GetHP() == 0)
		{
			cout << "채력이 다 떨어졌습니다.\n";

			p.clear();
			break;
		}


		char input = _getch();
		MovePlayer_Hard(Map_Hard, p, input);
	}
}