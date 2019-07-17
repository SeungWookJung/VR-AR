#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int radius);
	virtual ~Circle();
public:
	virtual float GetParimeter(int radius);
	virtual float GetArea(int radius);
	virtual void Print();

private:
	int radius;
};