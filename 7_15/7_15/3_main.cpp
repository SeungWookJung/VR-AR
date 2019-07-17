#include "Exception.h"
#include <iostream>

using namespace std;


void Divide(double dividend, double divider, double& result)
{
	if (divider == 0)
		throw Exception("Divide()",0);

	result = dividend / divider;
}
int main()
{
	double num1, num2, result;
	char Name[100];

	cout << "A/B 를 연산할 2개의 수 입력: ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2, result);
		cout << num1 << "/" << num2 << "=" << result << endl;
	}
	catch (Exception& e)
	{
		cout << "Exception : " << e.GetName() << ", Line : " << e.GetLine() << endl;
	}

	return 0;
}