#include <iostream>
#include <string>
#include <set>

using namespace std;

void Test3()
{
	string str("Hi! how are you?");
	string punctuation("!?.");
	size_t found = str.find_first_of(punctuation);

	cout << "found : " << found << endl;

	while (found != string::npos)
	{
		str.insert(found, 2, str[found]);
		found = str.find_first_of(punctuation, found + 3);
		cout << "found : " << found << endl;
	}
	cout << str << endl;
}

void Test4()
{
	string filename[] = { "readme.txt","presentation.ppt","word.doc","manual.pdf","plain.txt" };
	int arrLen = sizeof(filename) / sizeof(filename[0]);
	for (int i = 0; i < arrLen; i++)
	{
		size_t period = filename[i].rfind('.');
		if (period != string::npos)
		{
			string extension = filename[i].substr(period);
			if (extension.compare(".txt") == 0)
				cout << filename[i] << endl;
		}
	}
}
void Test5()
{
	string str("Hi ! How are you?");
	cout << "String length : " << str.length() << endl;
	printf("%s\n", str.c_str());

	str.clear();
	if (str.empty())
	{
		cout << "Now string is empty" << endl;
		cout << "String length : " << str.length();
	}
}

void Test6()
{
	string fruitArr[] = { "kiwi","apple","pineapple","orange","lemon","banana" };
	set<string> fruitSet;
	int arrLen = sizeof(fruitArr) / sizeof(fruitArr[0]);
	for (int i = 0; i < arrLen; i++)
	{
		fruitSet.insert(fruitArr[i]);
	}
	for (set<string>::iterator it = fruitSet.begin(); it != fruitSet.end(); it++)
	{
		cout << *it << ",";
	}cout << endl;

	string testArr[] = {"strawberry",}

}

int main()
{
	//Test3();
	//Test4();
	Test5();

	return 0;
}
