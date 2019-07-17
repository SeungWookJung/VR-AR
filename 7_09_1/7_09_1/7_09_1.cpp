#include <iostream>

using namespace std;

struct Node
{
	int num;
	Node* next_p;
};

int main()
{
	Node a, b, c;

	a.num = 1;
	b.num = 2;
	c.num = 3;
	a.next_p = &b;
	b.next_p = &c;

	cout << "a " << a.num <<endl;
	cout << "b " << a.next_p->num << endl;
	cout << "c " << b.next_p->num << endl;



	return 0;
}