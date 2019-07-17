#include "MyString.h"
#include <iostream>

using ::MyString;
using namespace std;

MyString::MyString()
{
	msg = new char[ARR_LEN];
	for (int i = 0; i < 64; i++)
	{
		msg[i] = '\0';
	}
	cout << "ar_length : "<< ar_lenght <<" 문자열 동적할당(64칸) 완료" << endl;
	ar_lenght = 64;

}
MyString::MyString(char *a)
{
	delete[] msg;
	msg = new char[ARR_LEN];
	for (int i = 0; i < ARR_LEN; i++)
	{
		msg[i] = a[i];
	}
	cout << "문자열 입력완료" << endl;
	return;
}
MyString::~MyString()
{
	cout << "소멸자 호출" << endl;
}
void MyString::Clear()
{
	for (int i = 0; i < ARR_LEN + 1; i++)
	{
		msg[i] = '\0';
	}
	cout << "초기화 완료('\0')" << endl;
}
bool MyString::IsEmpty()
{
	char c;
	c = *msg;
	if (c == '\0')
	{
		cout << "비어있다" << endl;
		return true;
	}
	else
		cout << "비어있지 않다." << endl;
		return false;

}
void MyString::Print()
{
	for (int i = 0; i < ARR_LEN + 1; i++)
	{
		cout << "항목" << i << " : " << msg[i] << endl;
	}
}
char MyString::At(int num)
{
	return msg[num];
}
int MyString::Length()
{
	int count = 0;
	for (int i = 0; i < ARR_LEN + 1; i++)
	{
		count += 1;
	}
	return count;
}
int MyString::Capacity()
{
	int count = 0;
	for (int i = 0; i < ARR_LEN; i++)
	{
		count += 1;
	}
	return count;
}
void MyString::Append(char* input)
{
	for (int i = 0; i < ARR_LEN; i++)
	{
		int j = 0;
		if (msg[i] == '\0')
		{
			msg[i] = input[j];
			j++;
		}
		else
			continue;
	}
	cout << "삽입 완료" << endl;

		return;
}
void MyString::ReWrite()
{
	char input[64];
	
	for (int i = 0; i < ARR_LEN; i++)
	{
		cout << "입력할 문자를 계속 입력해 주세요: ";
		cin >> input[i];

		if (input[i] == '\0')
		{
			cout << "취소되었습니다." << endl;
			break;
		}
		msg[i] = input[i];
	}
	

	return;
}