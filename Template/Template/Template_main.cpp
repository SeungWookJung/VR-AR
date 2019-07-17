#include "PosList.h"
#include <iostream>

#define DEFAULT_POSLEN 24

using namespace std;

void main()
{
	double pos = 0;
	PosList <double>p1(DEFAULT_POSLEN);
	for (int i = 0;i < DEFAULT_POSLEN; i++)
	{
		if (!p1.SetPos(i, (pos = pos + i) * 2.25))
		{
			cout << "SetPos Error : [" << i << ", " << pos * 2.5 << "]" << endl;
		}
	}
	for (int i = 0; i < DEFAULT_POSLEN; i++)
	{
		if (p1.GetPos(i, pos))
		{
			cout << "pos : [" << i << ", " << pos << "]" << endl;
		}
		else
		{
			cout << "GetPos Error : [" << i << "]" << endl;
		}
	}
	return;
}
