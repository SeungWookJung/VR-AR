#include <iostream>

using namespace std;

int main()
{
	cout << "-------------------------------------------" << endl;
	cout << "성적 메시지" << endl;
	for (int i = 1; i < 6; i++)
	{
		if (i == 1)
		{
			cout << i << "\t" << "성적은 " << i << "입니다. 노력합시다." << endl;
		}
		else if (i == 2)
		{
			cout << i << "\t" << "성적은 " << i << "입니다. 조금 더 노력합시다." << endl;
		}
		else if (i == 3)
		{
			cout << i << "\t" << "성적은 " << i << "입니다. 더 높은 점수를 목표로 합시다." << endl;
		}
		else if (i == 4)
		{
			cout << i << "\t" << "성적은 " << i << "입니다. 매우 잘했습니다." << endl;
		}
		else if (i == 5)
		{
			cout << i << "\t" << "성적은 " << i << "입니다. 매우 우수합니다." << endl;
		}
		
	}
	cout << "-------------------------------------------" << endl;
	return 0;
}
