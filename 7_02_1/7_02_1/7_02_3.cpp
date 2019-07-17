#include <iostream>
#include <string>

using namespace std;

/*struct Person
{
	int id;
	string name;
	string address;
}p;*/

//
int main()
{
	

	//¿­°ÅÇü 
	enum POLY{TRIANGLE =2, CIRCLE, RECTANGLE};
	

	//
	POLY ePOLY;

	ePOLY = POLY::RECTANGLE;

	cout << ePOLY << endl;

	ePOLY = POLY::CIRCLE;

	cout << ePOLY << endl;

	ePOLY = POLY::TRIANGLE;

	cout << ePOLY << endl;

	return 0;
}