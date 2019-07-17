#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num[10];			//정적할당
	int* pnum = new int[10]; //동적할당   프로그램 실행 중에도 공간 할당 가능


	/* //벡터는 이렇게 사용  //이런것들을 STL(standard template library) =>vector,list,stack,queue
	vector<int> v;
	vector<float> vf;
	vector<double> vd;
	*/

	vector <float> v;
	v.push_back(3.14f);
	v.push_back(3.25f);
	cout << v.at(0) << endl;  //v[0]
	cout << v.at(1) << endl;  // v[1]

	cout << v[0] << endl;
	cout << v[1] << endl;

	cout << "v.capacity : " << v.capacity() << endl;
	cout << "v.size : " << v.size() << endl;

	return 0;
}
