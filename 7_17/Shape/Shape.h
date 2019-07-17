#pragma once

class Shape
{
public:
	Shape(char* name);
	virtual ~Shape();

public:
	virtual float GetPerimeter() = 0; //둘레(길이)
	virtual float GetArea() = 0; //넓이(면적)
	virtual void Print() = 0;

protected:
	char* m_name;
};