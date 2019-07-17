#include <iostream>

using namespace std;

int main()
{
	const int N = 5;//배열의 길이
	int i, j, temp;
	int data[N] = { 5, 3, 7, 9, 1 };

	// Bubble Sort 
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - (i + 1); j++) {
			if (data[j] > data[j + 1]) {

				// 자리교환
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;

			}

		}
		cout << data[i]<<" , ";
	}
}
