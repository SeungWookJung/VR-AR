#include <iostream>

using namespace std;

int main()
{
	int num = 0;

	cout << "몇개의 숫자를 만드시나요? " << endl;
	cin >> num;

	int* ar = new int[num];

	for (int i = 0; i < num; i++)
	{
		ar[i] = i;
		cout << "ar[" << i << "] : " << ar[i] << endl;
	}

	delete[] ar;
	ar = nullptr;

	return 0;
}
