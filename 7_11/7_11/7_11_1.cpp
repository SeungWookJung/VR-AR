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
	int num1 = 23;
	int num2 = 90;

	cout << num1 << "," << num2 << endl;

	//두수를 체인지
	swap(num1, num2);
	 
	return 0;
}
