#include "Ball.h"
#include <iostream>

using namespace std;

Ball* Ball::m_instance = nullptr;

Ball::Ball()
{
}
Ball::~Ball()
{
	if (!nullptr)
		delete[] m_instance;
}
Ball::GetInstance()
{

}