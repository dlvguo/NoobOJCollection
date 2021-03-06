#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string reverseWords(string s)
	{
		if (s.length() == 0)
			return s;
		string str;
		int index = s.length() - 1;
		while (index >= 0 && s[index] == ' ')
		{
			index--;
		}
		string tempStr;
		while (index >= 0)
		{
			if (s[index] == ' ')
			{
				reverse(tempStr.begin(), tempStr.end());
				str += tempStr;
				str.push_back(' ');
				tempStr.clear();
				while (index >= 0 && s[index] == ' ')
				{
					index--;
				}
				continue;
			}
			else
			{
				tempStr.push_back(s[index--]);
			}
		}
		if (tempStr.size() != 0) {
			reverse(tempStr.begin(), tempStr.end());
			str += tempStr;
		}
		else
		{
			if (str.back() == ' ')
				str.pop_back();
		}
		return str;
	}
};

int main() {
	Solution s1;
	string str = "";
	s1.reverseWords(str);
}