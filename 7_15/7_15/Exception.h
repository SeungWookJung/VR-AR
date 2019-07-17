#pragma once
#include <iostream>
class Exception
{
public:
	Exception(char* name,int line);
	virtual ~Exception();

public:
	char* GetName();
	int GetLine();

private:
	char* m_pStrName;
	int m_nLine;
};