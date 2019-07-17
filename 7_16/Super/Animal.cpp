#include "Animal.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"

Animal::Animal()
{
	cout << "Animal 호출" << endl;
}
Animal::~Animal()
{
	cout << "소멸자 호출" << endl;
}

void Animal::Print_Bird()
{
	cout << "Bird 호출 입니다(상속)" << endl;
}
void Animal::Print_Cat()
{
	cout << "Cat 호출 입니다(상속)" << endl;
}
void Animal::Print_Dog()
{
	cout << "Dog 호출 입니다(상속)" << endl;
}

Bird::Bird()
{
	cout << "Bird 호출" << endl;
}
Bird::~Bird()
{
	cout << "소멸자 호출" << endl;
}

Cat::Cat()
{
	cout << "Cat 호출" << endl;
}
Cat::~Cat()
{
	cout << "소멸자 호출" << endl;
}


Dog::Dog()
{
	cout << "Dog 호출" << endl;
}
Dog::~Dog()
{
	cout << "소멸자 호출" << endl;
}