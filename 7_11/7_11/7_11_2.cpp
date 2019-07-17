#include "Human.h"
#include <iostream>

using namespace std;

/*멤버 변수 : hp,mp
	멤버 함수 : Run,Walk -> 메세지 출력

	기본 생성자
	생성자(hp,mp)

	attack -> mp > 0 이상일때만 공격 가능, 공격했다,mp를 감소 시키세요

	*/
int main()
{
	Human h1;
	int HP = 100;
	int MP = 0;
	int enemy = 100;
	
		cout << "HP와 MP를 입력해 주세요 : ";
		cin >> HP;
		cin >> MP;

		h1.Set(HP, MP);

		HP = h1.GetHp();
		MP = h1.GetMp();
		h1.Run();

		cout << "적을 만났습니다. 공격해주세요" << endl;

		while (1)
		{
			h1.Attack(MP);
			MP = h1.GetMp();
			enemy -= 5;
			if (enemy == 0)
			{
				cout << "적을 물리쳤습니다. 축하합니다." << endl;
				break;
			}
		}


	return 0;
}