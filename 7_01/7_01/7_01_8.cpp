#include <iostream>
#include <time.h>  //랜덤함수 중복 제거에 필요한 라이브러리

using namespace std;

int main()
{
	int max = 10;
	int list[5] = {0,0,0,0,0};

	srand(time(NULL)); //랜덤함수 중복값 제거

	for(int i=0;i<5;i++){

	 list[i] = rand() % (max + 1);

		cout << "랜덤숫자 5 개: " << list[i] << endl;
		
	}

	return 0;
}