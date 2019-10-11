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

//////�� ���̵��� ũ��/////

#define EASY_X 22
#define EASY_Y 22

#define NORMAL_X 28
#define NORMAL_Y 28

#define HARD_X 38
#define HARD_Y 38

ifstream scoreFile;
////////�Լ���///////////

void MainUi(); //���� ȭ��
void DifficultyMenu(); //���̵� ���� ȭ��
void MenuScore();//����� ���ھ� ǥ��
void Difficulty(); //���̵� �����Լ�
int Hp = 100;//cpp���� ü���� �Ⱥҷ����� �ӽ�
void setcolor(int color, int bgcolor); //���� ���� �Լ�


//���̵� �� �̷� ���
void Map_Print_Easy(char Map_Easy[EASY_X][EASY_Y]);
void Map_Print_Normal(char Map_Normal[NORMAL_X][NORMAL_Y]);
void Map_Print_Hard(char Map_Hard[HARD_X][HARD_Y]);

//���̵��� �÷��̾� �̵��Լ�
void MovePlayer_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p, char input);
void MovePlayer_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p, char input);
void MovePlayer_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p, char input);

//���̵��� �÷��̾� �̵� �Լ�(��,��,��,��)
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
������ : ���¿�
���� ��¥ : 2019-07-21
�������� : �� ũ�� ����, ���� ���� �ؽ��Ŀ� ���� ������
*/

int main()
{
	int Choice = 0;

	while (1)
	{
		MainUi(); //���� UI
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
			cout << "\t\t ������ּż� �����մϴ�." << endl;
			cout << "\t\t ���� �Ǿ����ϴ�." << endl;
			exit(1);
		}
		else
		{
			cout << "\t" << " �߸� �Է��ϼ̽��ϴ�. �ٽ��Է��� �ּ���. " << endl;
			Choice = 0;
		}
	}

	return 0;
}



//���� ����ȭ��
void MainUi()
{
	cout << "\t\t------------------------------------------" << endl;

	cout << "\t\t*             1. ���� ����               *" << endl;

	cout << "\t\t*             2. ���� ȭ��               *" << endl;

	cout << "\t\t*              0. ��  ��                 *" << endl;

	cout << "\t\t*                                        *" << endl;

	cout << "\t\t------------------------------------------" << endl;
}

// ���̵� ���� �޴���
void DifficultyMenu()
{
	cout << "\t\t------------------------------------------" << endl;

	cout << "\t\t*\t\t" << "1.  Easy  " << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "2.  Normal" << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "3.  Hard  " << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "0.  ����ȭ��" << "\t\t *" << endl;

	cout << "\t\t*\t\t" << "\t\t\t *" << endl;

	cout << "\t\t------------------------------------------" << endl;
}

//���� ��� �Լ�
void MenuScore()
{
	system("cls");

	cout << "\t\t*\t   ���ھ ǥ���մϴ�.\n\n";

	cout<< "\t\t�̸�\t\t����\t���̵�\n" << endl;

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
		cout << "\t\t\t����� ����� �����ϴ�.\n";
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



//���� ���� �Լ�
void setcolor(int color, int bgcolor)

{
	color &= 0xf;

	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//���̵� ���� �Լ�
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

		if (difficulty == 0) //�������� ���ư�
		{
			break;
		}

		if (difficulty == 1)// ���̵� ����
		{
			Map_Print_Easy(Map_Easy);
			break;
		}

		else if (difficulty == 2)// ���̵� �߰�
		{
			Map_Print_Normal(Map_Normal);
			break;
		}
		else if (difficulty == 3)// ���̵� �����
		{
			Map_Print_Hard(Map_Hard);
			break;
		}
		else
			cout << "\t" << " �߸� �Է��ϼ̽��ϴ�. �ٽ��Է��� �ּ���. " << endl;
	}

}

//���̵� Easy

void MoveUp_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//������ üũ
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
		//������ üũ
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
		//������ üũ
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
		//������ üũ
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X() + 1] != '0')
		{
			p.SetNow_X(1);
		}
	}
}

void MovePlayer_Easy(char Map_difficulty[EASY_X][EASY_Y], Player& p, char input) //�÷��̾ �����̴� �Լ�
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

/*��
	0. ��
	1. ���
	2. ������
	3. ������s
*/

//���̵� Easy ��
void Map_Print_Easy(char Map_Easy[EASY_X][EASY_Y])
{
	Player p;
	p.SetEnd(19, 19);

	clock_t start = 0, end = 0;
	start = clock(); //Ÿ�̸� ����

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
					cout << "��";

				}
				else if (Map_Easy[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "��";
				}
				else if (Map_Easy[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Easy[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "��";
				}
				else if (Map_Easy[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "��";
				}
			}

			cout << endl;
		}
		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y()) //���� ������ ������ ��������
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10); //���� ����� (�ɸ� �ð� *100)+(ü�� *10) �Դϴ�.

			string name; //�÷��̾� �̸�

			p.SetScore(scoreResult);

			cout << "�����߽��ϴ�.  �Ϸ�ð��� : " << endTime << " �� �Դϴ�." << endl;
			cout << "������ " << p.GetScore() << " �� �Դϴ�." << endl;
			cout << "���� �Է��� ���� �̸��� �Է��� �ּ��� : ";
			cin >> name;


			scoreFile.open("score.txt"); //������ �о�´�.

			if (!scoreFile) //���� ������ �������
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " EASY" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}
			else //�ִ°�� �ڿ� �ٿ��� �ۼ�
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " EASY" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}

			p.clear(); //Player Ŭ���� �ʱ�ȭ
			break;
		}

		cout << "W : ��  S : �Ʒ�  A : ����  D : ������" << endl;


		char input = _getch();
		MovePlayer_Easy(Map_Easy, p, input);
	}

}

//���̵� Normal

void MoveUp_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//������ üũ
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
		//������ üũ
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
		//������ üũ
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
		//������ üũ
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







void MovePlayer_Normal(char Map_difficulty[NORMAL_X][NORMAL_Y], Player& p, char input) //�÷��̾ �����̴� �Լ�
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
//���̵� Normal ��
void Map_Print_Normal(char Map_Normal[NORMAL_X][NORMAL_Y])
{
	Player p;
	p.SetEnd(24, 24);

	clock_t start = 0, end = 0;
	start = clock(); //Ÿ�̸� ����

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
					cout << "��";
				}
				else if (Map_Normal[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "��";
				}
				else if (Map_Normal[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Normal[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "��";
				}
				else if (Map_Normal[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "��";
				}
				else if (Map_Normal[i][j] == '4')
				{			
					setcolor(13, 0);
					cout << "��";
				}

			}
			cout << endl;
		}

		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y())
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10)+(p.GetMonsterKill()*1000); //���� ����� (�ɸ� �ð� *100)+(ü�� *10) �Դϴ�.

			string name; //�÷��̾� �̸�

			p.SetScore(scoreResult);

			cout << "�����߽��ϴ�.  �Ϸ�ð��� : " << endTime << " �� �Դϴ�." << endl;
			cout << "������ " << p.GetScore() << " �� �Դϴ�." << endl;
			cout << "���� �Է��� ���� �̸��� �Է��� �ּ��� : ";
			cin >> name;


			scoreFile.open("score.txt"); //������ �о�´�.

			if (!scoreFile) //���� ������ �������
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " NORMAL" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}
			else //�ִ°�� �ڿ� �ٿ��� �ۼ�
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " NORMAL" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}

			p.clear(); //Player Ŭ���� �ʱ�ȭ
			break;
		}
		cout << "W : ��  S : �Ʒ�  A : ����  D : ������" << endl;

		cout << "�븻���̵����ʹ� ����(��)�� �����մϴ�.\n";
		
		cout << "���� ó�� : " << p.GetMonsterKill() << endl;

		cout << "���� HP : " << p.GetHP() << endl;

		if (p.GetHP() == 0)
		{
			cout << "ä���� �� ���������ϴ�.\n";

			p.clear(); 
			break;
		}

		
		char input = _getch();
		MovePlayer_Normal(Map_Normal, p, input);
	}
}

//���̵� Hard

void MoveUp_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p)
{
	if (p.GetNow_Y() - 1 >= 0)
	{
		//������ üũ
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//���϶�
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//Ű�� ŉ��������
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
		//������ üũ
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//���϶�
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//Ű�� ŉ��������
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
		//������ üũ
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//���϶�
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//Ű�� ŉ��������
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
		//������ üũ
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '6')//���϶�
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
		if (Map_difficulty[p.GetNow_Y()][p.GetNow_X()] == '5')//Ű�� ŉ��������
		{
			p.SetKey(1);

			Map_difficulty[p.GetNow_Y()][p.GetNow_X()] = '1';

		}
	}
}




void MovePlayer_Hard(char Map_difficulty[HARD_X][HARD_Y], Player& p, char input) //�÷��̾ �����̴� �Լ�
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


//���̵� Hard ��
void Map_Print_Hard(char Map_Hard[HARD_X][HARD_Y])
{
	Player p;
	p.SetHP(50);
	p.SetEnd(35, 35);

	clock_t start = 0, end = 0;
	start = clock(); //Ÿ�̸� ����


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
					cout << "��";
				}
				else if (Map_Hard[i][j] == '0')
				{
					setcolor(15, 0);
					cout << "��";
				}
				else if (Map_Hard[i][j] == '1')
				{
					cout << "  ";
				}
				else if (Map_Hard[i][j] == '2')
				{
					setcolor(10, 0);
					cout << "��";
				}
				else if (Map_Hard[i][j] == '3')
				{
					setcolor(12, 0);
					cout << "��";
				}
				else if (Map_Hard[i][j] == '4')
				{
					setcolor(13, 0);
					cout << "��";
				}
				else if (Map_Hard[i][j] == '5')
				{
					setcolor(14, 0);
					cout << "��";
				}
				else if (Map_Hard[i][j] == '6')
				{
					setcolor(6, 0);
					cout << "��";
				}
			}
			cout << endl;
		}

		if (p.GetNow_X() == p.GetEnd_X() && p.GetNow_Y() == p.GetEnd_Y()) //�������� ����
		{
			end = clock();
			int endTime = ((end - start) / CLOCKS_PER_SEC);
			int scoreResult = (endTime * 100) + (p.GetHP() * 10)+(p.GetMonsterKill()*1000); //���� ����� (�ɸ� �ð� *100)+(ü�� *10)+(���� ó���� *1000) �Դϴ�.

			string name; //�÷��̾� �̸�

			p.SetScore(scoreResult);

			cout << "�����߽��ϴ�.  �Ϸ�ð��� : " << endTime << " �� �Դϴ�." << endl;
			cout << "������ " << p.GetScore() << " �� �Դϴ�." << endl;
			cout << "���� �Է��� ���� �̸��� �Է��� �ּ��� : ";
			cin >> name;


			scoreFile.open("score.txt"); //������ �о�´�.

			if (!scoreFile) //���� ������ �������
			{
				ofstream scoreOut("score.txt");

				scoreOut << name << " " << p.GetScore() << " HARD" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}
			else //�ִ°�� �ڿ� �ٿ��� �ۼ�
			{
				ofstream scoreOut("score.txt", ios::app);
				scoreOut << name << " " << p.GetScore() << " HARD" << endl;
				scoreOut.close();
				cout << "���� �Ǿ����ϴ�." << endl;
			}

			p.clear(); //Player Ŭ���� �ʱ�ȭ
			break;
		}
		cout << "W : ��  S : �Ʒ�  A : ����  D : ������" << endl;

		cout << "�ϵ峭�̵��� ���� ����(��)�� �����մϴ�.\n";

		cout << "��(��)�� ����ϱ� ���ؼ��� Ű(��)�� �ʿ��մϴ�." << endl;

		cout << "Ű ���� : " << p.GetKey() << endl;

		cout << "���� ó�� : " << p.GetMonsterKill() << endl;

		cout << "���� HP : " << p.GetHP() << endl;

		if (p.GetHP() == 0)
		{
			cout << "ä���� �� ���������ϴ�.\n";

			p.clear();
			break;
		}


		char input = _getch();
		MovePlayer_Hard(Map_Hard, p, input);
	}
}