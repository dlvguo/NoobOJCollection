#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool static cmp(const string a, const string b)
	{
		return a + b < b + a;
	}


	string minNumber(vector<int>& nums)
	{
		vector<string> vts;
		for (int i = 0; i < nums.size(); i++)
		{
			vts.push_back(to_string(nums[i]));
		}
		sort(vts.begin(), vts.end(), cmp);
		string str;
		for (int i = 0; i < nums.size(); i++)
		{
			str += (vts[i]);
		}
		return str;
	}
};