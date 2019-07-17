#include "Animal.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"

using namespace std;

/*상속 제작
Parent -> Animal
Child -> Dog,Cat
*/
int main()
{

	

	Bird b;
	b.Print_Bird();

	Cat c;
	c.Print_Cat();

	Dog d;
	d.Print_Dog();

	Animal* A = &c;
	A->Print_Cat();



	return 0;
}
