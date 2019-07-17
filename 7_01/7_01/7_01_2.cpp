#include <iostream>

using namespace std;

int C_For(int result);
int C_While(int result);
int C_DoWhile(int result);
int main()
{
	// 1~ 10(정수) 더하는 기능의 함수
	// 조건 for 사용 할 것
	int x, y, result = 0;

	result = C_For(result);
	cout << "result = " << result << endl;
	result = 0;

	result = C_While(result);
	cout << "result = " << result << endl;
	result = 0;
	
	result = C_DoWhile(result);
	cout << "result = " << result <<  endl;

	return 0;
}

int C_For(int result)
{
	for (int i = 0; i <= 10; i++) 
	{
		result += i;
	}
	return result;
}

int C_While(int result)
{
	int i = 0;
	while (i<=10)
	{
		result = result + i;
		i++;
	}
	return result;
}

int C_DoWhile(int result)
{
	int i = 0;
	do
	{
		result = result + i;
		i++;
	} while(i<=10);
	return result;
}