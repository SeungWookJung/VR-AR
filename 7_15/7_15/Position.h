#include <iostream>
#include <string>

#pragma once

class Position
{
public:
	Position();
	Position(int x, int y);
	~Position();

public:
	void ShowPosition();

	//1. 단항연산자
public:
	Position& operator++();
	Position operator++(int);

	//2.이항연산자
	Position operator+(Position pos);
	Position operator*(int num);
	ostream& operator<<(ostream& os, const Position& p);

private:
	int m_nx;
	int m_ny;
};