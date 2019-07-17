#pragma once
#include <ostream>

class MyInt
{
public:
	MyInt();
	~MyInt();
	MyInt(int num);

	//복사 생성자 &를 사용
	MyInt(const MyInt &inData);
	MyInt& operator=(const MyInt& inData);

public:
	void print();
	void Set(int num);
	int Get();

	//friend 는 다른 영역을 참가 하는 것
	friend ostream& operator<<(ostream& os, const MyInt& inData);

private:
	int m_num;
};