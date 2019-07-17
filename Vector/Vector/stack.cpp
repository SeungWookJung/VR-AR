#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;

	for (int i = 0; i < 5; i++)
	{
		s.push(i);
		cout << s.top() << endl;
	}

	s.pop();
	cout << s.top() << endl;

	return 0;
}
