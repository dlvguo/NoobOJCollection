#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

bool Judge(const string& s, int i)
{
	if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
		return true;
	return false;
}

int main()
{
	string str;
	set<string>::iterator iter;
	while (cin >> str)
	{
		set<string> _set;
		string temps;
		int index = 0;
		vector<string> vts;

		for (int i = 0; i < str.size(); i++)
		{
			if (Judge(str, i))
			{
				temps.push_back(str[i]);
			}
			else
			{
				if (temps.size())
				{
					iter = _set.find(temps);
					if (iter == _set.end())
					{
						_set.insert(temps);
						vts.push_back(temps);
					}
					temps.clear();
				}
			}
		}

		if (temps.size())
		{
			iter = _set.find(temps);
			if (iter == _set.end())
			{
				_set.insert(temps);
				vts.push_back(temps);
			}
		}
		for (int i = 0; i < vts.size(); i++)
		{
			cout << vts[i] << endl;
		}

	}
}