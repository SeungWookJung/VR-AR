#include <iostream>

using namespace std;


int main()
{
	int num = 0;

	for (int i = 1; i < 11; i++) {
		cout << i << endl;
		if (i == 10) {
			for (int i = 10; i >=1; i--)
				cout << i << endl;
		}
	}

	return 0;
}