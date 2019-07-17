#pragma once
#include <iostream>

using namespace std;

class Parent
{
public:
	void Print1()
	{
		cout << "부모 클래스 입니다." << endl;
	}

protected: //프로텍티드는 상속과 관련이 되어져 있다.
	void Print2()
	{
		cout << "상속된 클래스 입니다." << endl;
	}

private:

};