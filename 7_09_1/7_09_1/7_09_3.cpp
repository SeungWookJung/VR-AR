#include <iostream>

using namespace std;

int main()
{
	int* p = new int[3];

	//int n = 635;
	//p = &n;

	for (int i = 0; i < 3; i++)
	{
		*(p + i) = 633+i;

		cout << " p["<<i<<"] : "<< p[i] << endl;
	}
	cout << " *p " << *(p + 0) << endl;
	cout << " *p " << *(p + 1) << endl;
	cout << " *p " << *(p + 2) << endl;

	//cout << " n " << n << endl;
	//cout << " &n " << &n << endl;


	delete[] p; //
	p = nullptr;

	return 0;
}
