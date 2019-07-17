#include "Add.h"
#include "Min.h"
#include "Mul.h"
#include "Div.h"

int Add(int num1, int num2) //µ¡¼À
{
	int result = num1 + num2;

	return result;
}

int Min(int num1, int num2) //»¬¼À
{
	int result = num1 - num2;

	return result;
}

int Mul(int num1, int num2)  //°ö¼À
{
	int result = num1 * num2;

	return result;
}

int Div(int num1, int num2) //³ª´°¼À
{
	int result = num1 / num2;

	return result;
}