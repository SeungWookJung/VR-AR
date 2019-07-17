#include <iostream>

using namespace std;

int main()
{
	int* p1 = new int[3];
	
	for (int i = 0; i < 3; i++)
		p1[i] = i;

	
	int* p2;
	p2 = new int[3];

	for (int i = 0; i < 3; i++)
		p2[i] = i;



	cout << p2[0] << "," << p2[1] << "," << p2[2] << endl;

	return 0;
}
