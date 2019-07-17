#include <iostream>

using namespace std;

const int Size = 5;
int arr[Size] = {};

void Input(int *arr,int Size)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = i;
	}
}
void Print(int *arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{

	Input(arr,Size);
	Print(arr,Size);

	cout << "\n\n";

	return 0;
}