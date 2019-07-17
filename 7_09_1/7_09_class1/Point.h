#pragma once

//좌표쌍(x,y)
class Point
{
public:  //공공의

	//디폴트 생성자
	Point();
	//디폴트 소멸자
	~Point();

	Point(int x, int y);

	void ShowPoint();

	int GetX()
	{
		return mx;
	}
	int GetY()
	{
		return my;
	}
	void SetX(int x)
	{
		this->mx = x;
	}
	void SetY(int y)
	{
		this->my = y;
	}


protected: //보호된

private: //비밀 (멤버 변수는 보안으로)

	int mx, my; 
};