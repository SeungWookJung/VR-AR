#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
	:mx(0),my(0) //초기화 리스트
{
	cout << "생성자 호출" << endl;
}
Point::~Point()
{
	cout << "소멸자 호출" << endl;
	
}
Point::Point(int x, int y)
{
	mx = x;
	my = y;
}
void Point::ShowPoint()
{
	cout << "(mx,my) = (" << mx << "," << my << ")\n";
}