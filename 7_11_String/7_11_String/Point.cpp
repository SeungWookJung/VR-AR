#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
	: mx(0)
	, my(0)
	, mname("")
{
	cout << "생성자 호출" << endl;
}
Point::Point(string name,int x, int y)
	: mx(x)
	, my(y)
	, mname(name)
{
}

Point::~Point()
{
	cout << "소멸자 호출" << endl;
}
void Point::SetPosition(int x, int y)
{
	mx = x;
	my = y;
}
void Point::Print()
{
	cout << "(name,x,y) = (" << mname << " , "<<mx << " , " << my << ")" << endl;
}
void Point::MovePosition(int x, int y)
{
	mx = mx + x;
	my = my + y;
}