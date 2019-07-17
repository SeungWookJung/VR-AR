#include <iostream>

using namespace std;


class Point
{
private:
	int mx, my;
	string mname;

public:
	Point()
		: mx(0)
		, my(0)
		, mname("")
	{
		cout << "생성자 호출" << endl;
	}
	Point(string name, int x, int y)
		: mx(x)
		, my(y)
		, mname(name)
	{
	}

	~Point()
	{
		cout << "소멸자 호출" << endl;
	}
	void SetPosition(int x, int y)
	{
		mx = x;
		my = y;
	}
	void Print()
	{
		cout << "(name,x,y) = (" << mname << " , " << mx << " , " << my << ")" << endl;
	}
	void MovePosition(int x, int y)
	{
		mx = mx + x;
		my = my + y;
	}
};
int main()
{

	int num;
	int* pnum = new int;

	int arr[10];
	int* parr = new int[10];

	
	Point* p = nullptr;
	p = new Point("name", 1, 2);

	p->Print();


	return 0;
}
