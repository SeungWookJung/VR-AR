#include <iostream>
#include <string>

using namespace std;

class KingInfo
{
public:
	void SetName(string name)
	{
		m_name = name;
	}

	string GetName() const
	{
		return m_name;
	}

private:
	string m_name;
};