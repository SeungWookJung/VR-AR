#include "Position.h"

#include <iostream>

using namespace std;

Position::Position()
	: m_nx(0)
	, m_ny(0)
{
}

Position::Position(int x, int y)
	: m_nx(x)
	, m_ny(y)
{
}

Position::~Position()
{
	cout << "¼Ò¸êÀÚ" << endl;
}
void Position::ShowPosition()
{
	cout << "[" << m_nx << ", " << m_ny << "]" << endl;
}
Position& Position::operator++()
{
	++m_nx;
	++m_ny;

	return *this;
}
Position Position::operator++(int)
{
	Position temp = *this;
	++m_nx;
	++m_ny;
	return temp;
}
Position Position::operator+(Position pos)
{
	Position temp;
	temp.m_nx = m_nx + pos.m_nx;
	temp.m_ny = m_ny + pos.m_ny;
}
Position Position::operator*(int num)
{
	Position temp;
	temp.m_nx = m_nx;
	temp.m_ny = m_ny;
}
ostream& operator<<(ostream& os, const Position& p)
{
	os << "[" << p.m_nx << ", " << p.m_ny << "]" << endl;
	return os;
}