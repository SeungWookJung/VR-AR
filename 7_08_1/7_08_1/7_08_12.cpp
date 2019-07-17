#include <iostream>
#include <string>

using namespace std;


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
	Point& operator = (const Point& pt);
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
class PointArray
{
private:
	int size;
	Point* ptArr;

public:
	PointArray(int _size);
	PointArray(const PointArray& apa);
	~PointArray();

public:
	int GetSize() const;
	Point GetAt(int index) const;
	bool SetAt(int index, const Point& apt);
	PointArray& operator =(const PointArray& apa);
};

PointArray::PointArray(int _size)
{
	size = _size;
	ptArr = new Point[size]();
	memset(ptArr, 0, sizeof(Point) * size);
}
PointArray::PointArray(const PointArray& apa)
{
	size = apa.GetSize();
	ptArr = new Point[size]();
	memset(ptArr, 0, sizeof(Point) * size);
	memcpy(ptArr, apa.ptArr, sizeof(Point) * size);

}
PointArray& PointArray::operator=(const PointArray& apa)
{
	size = apa.GetSize();
	ptArr = new Point[size]();
	memset(ptArr, 0, sizeof(Point) * size);
	memcpy(ptArr, apa.ptArr, sizeof(Point) * size);
	return *this;
}
PointArray::~PointArray()
{
	delete[] ptArr;
}
int PointArray::GetSize() const
{
	return size;
}
Point PointArray::GetAt(int index) const
{
	return ptArr[index];
}
bool PointArray::SetAt(int index, const Point& apt)
{
	if (index >= 0 && index <= size)
	{
		ptArr[index] = apt;
		return true;
	}
	return false;
}

class Polygon
{
private:
	char* name;
	PointArray ptArray;
	Point centralPt;

public:
	const int PT_NUM;

public:
	Polygon(char* _name, const Point& centPt, const PointArray& apt);
	Polygon(const Polygon& apoly);
	~Polygon();
	PointArray GetPtArray() const;
	Point GetCenterPt();
	void ShowPolygon();
};
Polygon::Polygon(char* _name, const Point& centPt, const PointArray& apt)
	:PT_NUM(apt.GetSize()), ptArray(apt.GetSize())
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	centralPt = centPt;
	ptArray = apt;
}
Polygon::Polygon(const Polygon& apoly)
	:PT_NUM(apoly.ptArray.GetSize()), ptArray(apoly.ptArray.GetSize())
{
	name = new char[strlen(apoly.name) + 1];
	strcpy(name, apoly.name);
	centralPt = apoly.centralPt;
	ptArray = apoly.ptArray;
}
Polygon::~Polygon()
{
	delete[] name;
}
PointArray Polygon::GetPtArray()const
{
	return ptArray;
}
Point Polygon::GetCenterPt()
{
	return centralPt;
}
void Polygon::ShowPolygon()
{
	cout << name << endl;
	cout << "중심점 : ";
	centralPt.ShowPoint();
	for (int i = 0; i < PT_NUM; i++)
	{
		cout << "각지점 : ";
		ptArray.GetAt(i).ShowPoint();
	}
}
void main()
{
	PointArray ptArray(5);
	for (int i = 0; i < 5; i++)
		ptArray.SetAt(i, Point((i + 1) * 10, (i + 1) * 10));
	Point cpt(100, 100);
	char msg[7] = "오각형";
	Polygon poly5(msg, cpt, ptArray);
	poly5.ShowPolygon();

	cout << endl;
	Polygon poly = poly5;
	poly.ShowPolygon();
}