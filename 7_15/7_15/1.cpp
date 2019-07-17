#include <iostream>

using namespace std;


bool Divide(double dividend, double divider, double* result)
{
	if (divider == 0)
		return false;

	*result = dividend / divider;
	return true;
}
void main()
{
	double num1, num2, result;

	cout << "A/B 를 연산할 2개의 수 입력: ";
	cin >> num1 >> num2;

	if (Divide(num1, num2, &result))
		cout << num1 << "/" << num2 << "=" << result << endl;
	else
		cout << "Invalid Value!!!" <<  endl;

	return;
}
