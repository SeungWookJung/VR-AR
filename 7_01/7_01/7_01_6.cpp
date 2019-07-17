#include <iostream>

using namespace std;

//함수의 선언부에서 기본 값을 넣어 놓으면 해당 값잉 기본값으로 동작 // 오른쪽부터 동작
int Add(int a ,int b,int c = 1,int d = 1,int e = 1);

// 아래의 방법은 안된다.
//int Add(int x=0, int y);  (X)
// 아래의 방법은 된다.
// int Add(int x =0,int y= 0);  (O)

void Resolution(int width = 800, int height = 600);


int main()
{
	Resolution();
	Resolution(1200, 900);

	//int result = 0;
	//result = Add(2,3); //함수를 사용

	//cout << "result= " << result << endl;

	return 0;
}

//파라미터를 적어줘야함
int Add(int a, int b, int c, int d, int e)
{
	int result = 0;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
	cout << "d : " << d << endl;
	cout << "e : " << e << endl;

	result = (a + b + c + d + e);

	return result;
}

void Resolution(int width, int height)
{
	cout << "(width, height) =  ( " << width << "," << height << ")" << endl;

}