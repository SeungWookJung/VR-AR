#pragma once
#include <iostream>

using namespace std;

class Human
{
	int hp = 100;
	int mp = 0;
public:
	void Set(int hp, int mp)
	{
		this->hp = hp;
		this->mp = mp;
		cout << "HP : " << this->hp << "MP : " << this->mp << " 로 설정되었습니다." << endl;
	}
	void AddMp(int mp)
	{
		this->mp = mp;
		cout << "MP는 " << this->mp << " 입니다." << endl;
	}
	int GetHp()
	{
		return this->hp;
		cout << "HP는 " << this->hp << " 입니다." << endl;
	}
	int GetMp()
	{
		return this->mp;
		cout << "MP는 " << this->hp << " 입니다." << endl;
	}
	void Run()
	{
		cout << "뛰고 있습니다." << endl;
	}
	void Attack(int mp)
	{
		int addMp = 0;
		int resultMp = 0;

		if (mp > 0)
		{
			cout << "공격 했습니다. mp 10 감소" << endl;
			AddMp((mp - 10));
		}
		else
		{
			cout << "mp 가 없어서 공격이 불가능 합니다." << endl;
			cout << "MP를 충전 해주세요 : ";

			int nowMp = GetMp();

			cin >> addMp;

			resultMp = nowMp + addMp;
			AddMp(resultMp);
		}

	}

};