#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
	//0~9
	int arr[10] = {};
	
	for (int i = 0;i <size(arr); i++) //배열에 값을 집어넣음(숫자)
	{
		arr[i] = i;
		cout << arr[i]<<"\n";
	}


	for (int i = 0; i <= size(arr); i++) //배열을 초기화(숫자)
	{
		arr[i] = 0;
		cout << arr[i] << endl;
	}*/

	//배열은 \0 까지 가기 때문에 string 을 사용시에는 상관이 없으나
	char arr2[10];

	for (int i = 0; i < size(arr2); i++) //배열에 값을 집어넣음(문자)
	{
		
		arr2[i] = 'a' + i;
		cout << arr2[i] << "\n";
	}


	for (int i = 0; i <= size(arr2); i++) //배열을 초기화(문자)
	{
		arr2[i] = '0';
		cout << arr2[i] << endl;
	}

	return 0;
}