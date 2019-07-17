#include <iostream>

using namespace std;


struct Person
{
	char name[5];
	int id;
	int phone;
};



int main()
{
	int idx = 0;
	int count = 0;
	int Default = 5;

	Person* person1 = new Person[Default];
	int array_size = sizeof(*person1) / sizeof(int);


	while (1)
	{
		if (array_size > Default)
		{
			Default = Default + 5;
			Person* person2 = new Person[Default];
			copy(person1[0], person1[Default], *person2);

			delete[] person1;
			person1 = nullptr;

			person1 = person2;

			delete[] person2;
			person2 = nullptr;

		}

		cout << "id를 입력해 주세요" << endl;
		cin >> idx;

		if (idx == -1)
		{
			for (int i = 0; i = array_size; i++)
			{
				cout << person1[i].id << endl;
				cout << person1[i].name << endl;
				cout << person1[i].phone << endl;

			}
			delete[] person1;
			person1 = nullptr;
			
			exit(1);
		}

		person1[count].id = idx;


		cout << "이름을 입력해 주세요" << endl;
		cin >> person1[count].name;

		cout << "전화번호를  입력해 주세요" << endl;
		cin >> person1[count].phone;

		count++;
	}

	return 0;
}