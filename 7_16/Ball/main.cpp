#include "Ball.h"
#include <iostream>

using namespace std;

int main()
{
	Ball* b;
	b = Ball::GetInstance();

	Ball* b2 = Ball::GetInstance();
	Ball* b3 = Ball::GetInstance();

	return 0;
}
