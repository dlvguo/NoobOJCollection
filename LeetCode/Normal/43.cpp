#include<string>
#include<iostream>
using namespace std;

class Solution
{
public:
    //注意数字下标对称 以及判断数位
	string multiply(string num1, string num2)
	{
		if (num1[0] == '0' || num2[0] == '0')
			return "0";
		string str;
		int count = 1;
		int i, j;
		for (i = num1.size() - 1; i >= 0; i--)
		{
			int index = 1, dig = 0;
			for (j = num2.size() - 1; j >= 0; j--)
			{
				int temp = (num2[j] - '0') * (num1[i] - '0') + dig;
				if (index + count - 1 <= str.size())
				{
					temp += (str[index + count - 2] - '0');
					dig = temp / 10;
					temp %= 10;
					str[index + count - 2] = temp + '0';
				}
				else
				{
					dig = temp / 10;
					temp %= 10;
					str.push_back(temp + '0');
				}
				index++;
			}
			if (dig)
				str.push_back(dig + '0');
			count++;
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	string str1 = "456", str2 = "123";
	Solution s1;
	s1.multiply(str2, str1);
}