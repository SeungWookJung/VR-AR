#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*char msg = ' ';

	for (int i = 0; i < 128;i++)
	{
		msg = i;
		//cout << msg << " ";
		cout << (int)msg << " : " << msg << endl;
	}
	cout << endl;*/

	//0 ~255 2^8
	unsigned char uc = NULL;
	for (int i = 0; i < 256; i++)
	{
		uc = i;
		cout << i << " : " << uc << endl;
	}
	cout << endl;

	return 0;
}
