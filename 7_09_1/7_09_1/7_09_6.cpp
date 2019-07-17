#include <iostream>

using namespace std;


typedef struct Person
{
	int id;
	string name;
	int phone;
};



int main()
{
	int id = 0;
	int count = 0;
	int Default = 5;

	Person p;
	Person* person = new Person[Default];

	int* dynamic_memory1 = new int[5];
	int array_size = sizeof(*dynamic_memory1) / sizeof(int);
	

	while (1)
	{
		if (array_size > Default)
		{
			Default=Default + 5;
			int* dynamic_memory2 = new int[Default];
			copy(dynamic_memory1[0], dynamic_memory1[5],*dynamic_memory2);

			delete[] dynamic_memory1;
			dynamic_memory1 = nullptr;

			dynamic_memory1 = dynamic_memory2;

		}

		cout << "id를 입력해 주세요" << endl;
		cin >> id;

		if (id == -1)
		{
			for (int i = 0; i= Default; i++)
			{
				cout << dynamic_memory1[i] << endl;
			}
			exit(1);
		}
		
			person[count].id = id;


			cout << "이름을 입력해 주세요" << endl;
			cin >> person[count].name;

			cout << "전화번호를  입력해 주세요" << endl;
			cin >> person[count].phone;

			count++;

			copy(person[0], person[Default], *dynamic_memory1);
		
	}

	return 0;
}
