#include <iostream>
#include <Windows.h>
#include <string>


#define DWORD COLORREF
#define RGB(r,g,b) ((COLORREF)(((BYTE)(r) | ((WORD)((BYTE)(g))<<8)) | (((DWORD)(BYTE)(b))<<16)))
#define unsigned int uint;

using namespace std;


//rgb를 입력받아사 출력하는 함수를 만들어 보세요
int main()
{

	string strTemp;


	int R=0, G=0, B = 0;

	cout << "R G B값을 입력하세요"<<endl;
	cout << "R 입력 : ";
	cin >> R;

	cout << "R 입력 : ";
	cin >> G;

	cout << "R 입력 : ";
	cin >> B;

	RGB(R, G, B);


	//typedef (변수타입) (원하는 변수 타입명)
	typedef unsigned int uint;

	return 0;
}
