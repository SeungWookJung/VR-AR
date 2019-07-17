#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(6);

	cout << "내부공간 : " << v.capacity() << endl;
	for (int i = 0; i < 6; i++)
		v[i] = i;

	v.push_back(7);
	v.push_back(8);

	cout << "저장 개수 : " << v.size() << endl;
	cout << "내부 공간 : " << v.capacity() << endl;

	for (int i = 0; i < 6; i++)
		cout << v[i] << ",";
	cout << endl;

	return 0;
}
