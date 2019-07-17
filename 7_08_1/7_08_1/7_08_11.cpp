#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int _x, int _y);
	Point(const Point& pt);
	~Point();

public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
	Point&operator = (const Point& pt);
};
Point::Point()
{
	x = y = 0;
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}
Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}
Point& Point::operator=(const Point& pt)
{
	x = pt.x;
	y = pt.y;
	return *this;
}
Point::~Point()
{
}
void Point::SetPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}
void Point::ShowPoint()
{
	cout << "x,y : [" << x << "," << y << "]" << endl;
}
void main()
{
	Point pt(100, 100);
	Point pt1 = pt;
	pt1.ShowPoint();
}