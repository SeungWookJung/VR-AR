#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	cout << "내부공간 : " << v.capacity() << endl;

	v.resize(6);
	for (int i = 0; i < 6; i++)
		v[i] = i;

	v.push_back(6);
	v.push_back(7);

	cout << "저장 개수 : " << v.size() << endl;
	cout << "내부 공간 : " << v.capacity() << endl;

	for (int i = 0; i < 8; i++)
		cout << v[i] << ",";
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
		cout << *it++ << ",";
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
		cout << *rit++ << ",";
	cout << endl;

	return 0;
}
