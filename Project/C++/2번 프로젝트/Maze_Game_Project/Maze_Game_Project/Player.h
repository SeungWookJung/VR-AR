
#pragma once
#include <iostream>

using namespace std;

class Player
{
public:

	Player();
	~Player();

public:
	void SetHP(int add_HP); //ü�� ����
	int GetHP(); //ü�� �޾ƿ���

	void SetScore(int add_score); //���� �����ϱ�
	int GetScore(); //����������

	int GetStart_X(); //������ X��ǥ
	int GetStart_Y(); //������ Y��ǥ

	void SetEnd(int add_pos_x, int add_pos_y); //������ �����ϱ�
	int GetEnd_X();  //������ X��ǥ
	int GetEnd_Y();	 //������ Y��ǥ

	void SetNow_X(int add_pos_x); //������ġ x����
	void SetNow_Y(int add_pos_y);  //������ġ y����
	int GetNow_X(); //������ġ x
	int GetNow_Y(); // ������ġ y

	int GetMonsterKill();//���� óġ��
	void MonsterKill();//���� ����

	int GetKey();//Ű ����
	void SetKey(int add_key);//Ű ŉ��


	void clear(); //Player Ŭ���� �ʱ�ȭ

public:
	void Attack(); //���ݽ� Set�Լ��� -10�� �־���

private:
	int HP; //ü��
	int nowPos_X, nowPos_Y; //�÷��̾� ���� ��ġ
	int startPos_X, startPos_Y; //�̷� �̵��� �÷��̾��� ������ġ
	int endPos_X, endPos_Y; //�̷� �̵��� �÷��̾��� �� ��ġ
	int score; //�÷��̾��� ����
	int Monster; //���� Ŭ���� ��
	int Key; // ���� �������� Ű ����
};