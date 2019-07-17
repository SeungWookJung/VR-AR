#include <iostream>

using namespace std;

#define NAME_LEN 30

class Theater
{
public:
	Theater(char* _name)
	{
		this->m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		strcpy(m_strName, _name);
	}
	Theater(const Theater& theater)
	{
		m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		memcpy(m_strName, theater.m_strName, NAME_LEN);
	}
	~Theater()
	{
		delete[] m_strName;
	}
	static void AddViewerCount()
	{
		m_nViewCount++;
	}
	static int GetViewerCount()
	{
		return m_nViewCount;
	}

private:
	char* m_strName;
	static int m_nViewCount;
};

int Theater::m_nViewCount = 0;

int main()
{
	cout << "관객수 : " << Theater::GetViewerCount() << " 명" << endl;

	Theater theater1((char*)"단성사");
	Theater theater2((char*)"서울극장");
	Theater theater3((char*)"명동 CGV");

	for (int i = 0; i < 1000000; i++)
		theater1.AddViewerCount();
	for (int i = 0; i < 1000000; i++)
		theater2.AddViewerCount();
	for (int i = 0; i < 1000000; i++)
		theater3.AddViewerCount();

	cout << "관객수 : " << Theater::GetViewerCount() << " 명" << endl;
	return 0;
}
