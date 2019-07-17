#pragma once

class MyString
{
public:
	MyString();
	MyString(char *a);
	~MyString();

	void Clear();
	bool IsEmpty();
	void Print();
	char At(int num);
	int Length();
	void Clear();
	int Capacity();
	void Append(char* input);
	void ReWrite();

private:
	char* msg;
	const int ARR_LEN = 64;
	int ar_lenght;
};
