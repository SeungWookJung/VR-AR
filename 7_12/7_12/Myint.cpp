#include "Myint.h"
#include <iostream>

//기본 생성자
Myint::Myint()
	:mnum(0)
{
	cout << "생성자 호출" << endl;
}
//소멸자
Myint::~Myint()
{
	delete mnum;
	mnum = nullptr;
	cout << "소멸자 호출" << endl;
}
//생성자
Myint::Myint(int x)
{
	*mnum = x;
}
//복사 생성자 Myint n2(n1)
Myint::Myint(const Myint& c)
{
	*mnum = *c.mnum;
}

void Myint::copy(const Myint& c)
{
	if (mnum == nullptr)
	{
		cout << "공간이 없습니다. 추가로 할당이 됩니다." << endl;
		mnum = new int;
	}
	*mnum = *c.mnum;
}
Myint Myint::operator+(const Myint& c)
{
	return Myint(*mnum + *c.mnum);
}

int Myint::GetNum() 
{
	return *mnum;
}
void Myint::SetNum(int x)	
{
	*mnum = x;
}
//출력
void Myint::Print()
{
	cout << *mnum << endl;
}