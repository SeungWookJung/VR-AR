#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
	Point p("Á¤½Â¿í",3, 2);

	p.SetPosition(3, 3);

	p.Print();

	p.MovePosition(2, 2);
	p.Print();
	return 0;
}