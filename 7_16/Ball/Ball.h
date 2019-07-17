#pragma once
#include <iostream>

using namespace std;

class Ball
{
public:
	Ball();
	~Ball();
	Ball* GetInstance(static Ball& m_instance);

private:
	static Ball* m_instance;
};