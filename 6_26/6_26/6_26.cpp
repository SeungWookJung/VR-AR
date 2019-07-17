#include <iostream>

#include "Add.h"
#include "Min.h"
#include "Mul.h"
#include "Div.h"

using namespace std;


//변수명은 소문자, 함수명,헤더명 대문자


//Func(x,y) x,y -> 매개변수,파라미터
int main()
{
	int sum_Add = Add(10, 20);
	int sum_Min = Min(10, 20);
	int sum_Mul = Mul(10, 20);
	int sum_Div = Div(20, 10);



	cout << "결과 = " << sum_Add << endl;
	cout << "결과 = "<< sum_Min << endl;
	cout << "결과 = " << sum_Mul << endl;
	cout << "결과 = " << sum_Div << endl;
	

	return 0;
}