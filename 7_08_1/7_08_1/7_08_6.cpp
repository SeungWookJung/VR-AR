#include "7_08_6.h"

#include <iostream>

using namespace std;

//Add sub mul Div
int main()
{
		int num1 = 10;
		int num2 = 20;

		float num3 = 48.33;
		float num4 = 40.33;

		Add(num1,num2);
		Sub(num1, num2);
		Mul(num1, num2);
		Div(num1, num2);

		Add(num3,num4);
		Sub(num3, num4);
		Mul(num3, num4);
		Div(num3, num4);


	return 0;
}

float Add(float num1, float num2)
{
	float result = (num1 + num2);
	cout << result << "\n" << endl;
	return result;
}
float Sub(float num1, float num2)
{
	float result = (num1 - num2);
	cout << result << "\n" << endl;
	return result;
}
float Mul(float num1, float num2)
{
	float result = (num1 * num2);
	cout << result << "\n" << endl;
	return result;
}
float Div(float num1, float num2)
{
	float result = (num1 / num2);
	cout << result << "\n" << endl;
	return result;
}
int Add(int num1, int num2)
{
	int result = (num1 + num2);
	cout << result << "\n" << endl;
	return result;
}
int Sub(int num1, int num2)
{
	int result = (num1 - num2);
	cout << result << "\n" << endl;
	return result;
}
int Mul(int num1, int num2)
{
	int result = (num1 * num2);
	cout << result << "\n" << endl;
	return result;
}
int Div(int num1, int num2)
{
	int result = (num1 / num2);
	cout << result << "\n" << endl;
	return result;
}