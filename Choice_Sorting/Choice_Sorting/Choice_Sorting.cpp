#include <iostream>

using namespace std;



int main()
{
	int arr[10] = { 5,2,4,8,0,9,6,3,1,7 };

	int temp = 0;
	int first = 0;
	int second = 0;


	cout << "정렬 되기 전 : ";
	for(int i = 0; i < 10-1; i++)
	{
		cout <<arr[i] << ",";
	}
	cout << "\n" << endl;
	
	for (int i = 0; i <10-1; i++)
	{
		first = arr[i];

		// 최솟값을 탐색한다.
		for (int j = i + 1; j < 10; j++) 
		{
			if (arr[j] < arr[first])
				first = j;
		}

		// 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
		if (i != first) {
			temp = arr[i];
			arr[i] = arr[first];
			arr[first] = temp;
		}
	}

	cout << "정렬 되고난 후 : ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ",";
	}
	cout << "\n" << endl;
	
	return 0;
}
