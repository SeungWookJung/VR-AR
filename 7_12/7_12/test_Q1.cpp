#define MaxNum 10
#include <iostream>

using namespace std;

int main()
{
	int num = 0;

	for (int i = 1; i  < MaxNum+1; i++)
	{
		if ((i % 2) == 0)
		{
			num += i;
		}
		else
			continue;
	}
	cout <<"합계는 : " << num << " 입니다."<<endl;

	return 0;
}
