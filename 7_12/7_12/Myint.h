#pragma once
#include <iostream>

using namespace std;

class Myint
{
private:
	int* mnum;
public:
	Myint();
	~Myint();
	Myint(int x);
	Myint(const Myint& c);

	Myint operator+(const Myint& c);
	void copy(const Myint& c);
	int GetNum();
	void SetNum(int x);

	void Print();
};