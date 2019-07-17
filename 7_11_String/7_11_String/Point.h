#pragma once
#include <string>

using std::string;

class Point
{
private:
	int mx, my;
	string mname;
public:
	Point();
	Point(string name,int x, int y);
	~Point();
	void SetPosition(int x, int y);
	void Print();
	void MovePosition(int x, int y);
};