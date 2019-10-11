#include "Player.h"

Player::Player()
	:HP(100)
	, startPos_X(1)
	, startPos_Y(1)
	, endPos_X(0)
	, endPos_Y(0)
	, score(0)
	, nowPos_X(1)
	, nowPos_Y(1)
	,Monster(0)
	, Key(0)
{
}
Player::~Player()
{
}

void Player::SetHP(int add_HP)
{
	this->HP += add_HP;
}
int Player::GetHP()
{
	return this->HP;
}

void Player::SetScore(int add_score)
{
	this->score += add_score;
}
int Player::GetScore()
{
	return this->score;
}

int Player::GetStart_X()
{
	return this->startPos_X;
}
int Player::GetStart_Y()
{
	return this->startPos_Y;
}

void Player::SetEnd(int add_pos_x, int add_pos_y)
{
	this->endPos_X = add_pos_x;
	this->endPos_Y = add_pos_y;
}
int Player::GetEnd_X()
{
	return this->endPos_X;
}
int Player::GetEnd_Y()
{
	return this->endPos_Y;
}

void Player::SetNow_X(int add_pos_x)
{
	this->nowPos_X += add_pos_x;
}
void Player::SetNow_Y(int add_pos_y)
{
	this->nowPos_Y += add_pos_y;
}
int Player::GetNow_X()
{
	return this->nowPos_X;
}
int Player::GetNow_Y()
{
	return this->nowPos_Y;
}

void Player::clear()
{
	HP = 0;
	nowPos_X = 0;
	nowPos_Y = 0;
	startPos_X = 0;
	startPos_Y = 0;
	endPos_X = 0;
	endPos_Y = 0;
	score = 0;
	Monster = 0;
	Key = 0;
}

int Player::GetMonsterKill()
{
	return this->Monster;
}
void Player::MonsterKill()
{
	Monster +=1;
}

void Player::Attack()
{
	SetHP(-10);
}

int Player::GetKey()
{
	return this->Key;
}
void Player::SetKey(int add_key)
{
	this->Key += add_key;
}
