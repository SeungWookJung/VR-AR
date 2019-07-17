#include "MyInt.h"
#include <iostream>

using namespace std;

int main()
{
	//복사 생성자(클래스에서는 받는 인자를 &를 사용한다), 넘기는 인자는 그대로 사용하면 된다.
	//MyInt n3(n2);

	MyInt n1;
	MyInt n2(3);

	n1 = n2;
	n1.Set(66);

	n1.print();
	return 0;
}
