#pragma once
#include "Parent.h"

class Child : public Parent
{
public:
	void Print3()
	{
		Print2();
		cout << "자식 클래스입니다" << endl;
	}
protected:

private:

};