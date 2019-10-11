
#pragma once
#include <iostream>

using namespace std;

class Player
{
public:

	Player();
	~Player();

public:
	void SetHP(int add_HP); //체력 셋팅
	int GetHP(); //체력 받아오기

	void SetScore(int add_score); //점수 셋팅하기
	int GetScore(); //점수얻어오기

	int GetStart_X(); //시작점 X좌표
	int GetStart_Y(); //시작점 Y좌표

	void SetEnd(int add_pos_x, int add_pos_y); //종료점 셋팅하기
	int GetEnd_X();  //종료점 X좌표
	int GetEnd_Y();	 //종료점 Y좌표

	void SetNow_X(int add_pos_x); //현재위치 x셋팅
	void SetNow_Y(int add_pos_y);  //현재위치 y셋팅
	int GetNow_X(); //현재위치 x
	int GetNow_Y(); // 현재위치 y

	int GetMonsterKill();//몬스터 처치수
	void MonsterKill();//몬스터 셋팅

	int GetKey();//키 갯수
	void SetKey(int add_key);//키 흭득


	void clear(); //Player 클래스 초기화

public:
	void Attack(); //공격시 Set함수에 -10을 넣어줌

private:
	int HP; //체력
	int nowPos_X, nowPos_Y; //플레이어 현재 위치
	int startPos_X, startPos_Y; //미로 이동시 플레이어의 시작위치
	int endPos_X, endPos_Y; //미로 이동시 플레이어의 끝 위치
	int score; //플레이어의 점수
	int Monster; //몬스터 클리어 수
	int Key; // 문을 열기위한 키 갯수
};