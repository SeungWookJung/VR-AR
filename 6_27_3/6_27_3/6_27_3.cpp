#include <iostream>
#include <array>

using namespace std;


int main()
{
	int list[7] = {2,4,5,8,3,0,7};
	
	for (int i = 0; i < size(list); i++)
	{	
		if (list[i] == 5)
		{
			cout << list[i] << endl;
			break;
		}
		else
		{
			cout << list[i] << endl;
		}
	}

	
	return 0;
}