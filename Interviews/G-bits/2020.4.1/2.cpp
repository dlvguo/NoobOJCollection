#include<iostream>
#include<vector>
using namespace std;

int visit[16] = { 0 };
int ans = 0;
int m;

void TrackBack(string& str, vector<int>& nums) {
	if (nums.size() == str.size()) {
		long long sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum = (sum * 10 + nums[i]) % m;
		}
		if (!sum)
			ans++;
	}
	else {
		for (int i = 0; i < str.size(); i++)
		{
			if (!visit[i]) {
				nums.push_back(str[i] - '0');
				visit[i] = 1;
				TrackBack(str, nums);
				visit[i] = 0;
				nums.pop_back();
			}
		}
	}
}

//给出一个长度小于15的数字字符串，一个数字M，求出用这个字符串排列出的数字能够被M整除的数量
//如：123 6 输出结果 2 因为有:132 312

int main() {

	string s;
	vector<int> nums;

	cin >> s >> m;
	TrackBack(s, nums);
	cout << ans << endl;
}
