#include <iostream>

using namespace std;
/*
	일반적인 경우 (.h) - 헤더파일에만 적용
  - 지금 보고 있는 소스파일의 의미
  - 지금 소스파일에서 의도 하는 것
  - 지금 소스파일을 사용하는 방식,기능

	main 함수가 있는 cpp 파일
  - 배경지식
  - 만든사람, 날짜
  - 라이센스

*/

/*1.라인 단위로 의미 적어주기
2.함수 위쪽에 사용해서 함수의 의미 적어주기*/
int main()
{
	//int numi = 3;
	//float numf = 4.8f;

	////numi = (int)numf;	 //C 스타일 type cast(형변환)

	//numi = static_cast<int>(numf); // c++ 스타일 type cast(형변환) 총 4가지 스타일이 있다
	//cout << numf << endl;
	//cout << numi << endl;

	//\t 자동정렬 \n 줄바꿈
	int num1 = 1;
	float num2 = 1.23f;
	double num3 = 1.23;


	cout << "num1=" << num1 << "\t\t" << sizeof(int) << "bytes" << endl;
	cout << "num2=" << num1 << "\t\t" << sizeof(float) << "bytes" << endl;
	cout << "num3=" << num1 << "\t\t" << sizeof(double) << "bytes" << endl;


	char ch = 'a';
	bool b = true;

	cout << "ch=" << ch << "\t\t" << sizeof(char) << "bytes" << endl;
	cout << "b=" << b << "\t\t" << sizeof(bool) << "bytes" << endl;

	return 0;
}