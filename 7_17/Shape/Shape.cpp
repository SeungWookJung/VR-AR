#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape(char* name)
	:m_name(name)
{
}
Shape::~Shape()
{
	cout << "Shape 소멸자 입니다." << endl;
}
