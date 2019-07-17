#include <iostream>

using namespace std;

//값 전달 방식
//1. 값 전달
//2. 주소전달 call-by-references
void swap(int& pnum1, int& pnum2)
{
	int temp = 0;

	temp = pnum1;
	pnum1 = pnum2;
	pnum2 = temp;

	cout << pnum1 << "," << pnum2 << endl;

	return;
}

int main()
{
	//SWAP
	int num1 = 12;
	int num2 = 99;

	cout << num1 << "," << num2 << endl;

	//두수를 체인지
	swap(num1, num2);
	

	//두수를 체인지
	swap<int>(num1, num2);
	cout << num1 << "," << num2 << endl;

	return 0;
}
