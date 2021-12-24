#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bitset<32>> bts;
    bitset<32> tempB;
    int maxLen = 0, tempLen = 0;

    void dfs(int nowIndex)
    {
        if (nowIndex >= bts.size())
        {
            return;
        }
        //说明没交集
        if (!(tempB & bts[nowIndex]).count())
        {
            tempB |= bts[nowIndex];
            tempLen += bts[nowIndex].count();
            maxLen = max(tempLen, maxLen);
            dfs(nowIndex + 1);
            tempB ^= bts[nowIndex];
            tempLen -= bts[nowIndex].count();
        }
        dfs(nowIndex + 1);
    }

    int searchBin(const string &s)
    {
        int set[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (set[s[i] - 'a'])
                return 0;
            set[s[i] - 'a']++;
        }
        int res = 0, count = 1;
        for (int i = 0; i < 26; i++)
        {
            if (set[i])
                res += count;
            count *= 2;
        }
        return res;
    }

    int maxLength(vector<string> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int num = searchBin(arr[i]);
            if (!num)
                continue;
            bitset<32> b(num);
            bts.push_back(b);
        }
        dfs(0);
        return maxLen;
    }
};

int main()
{
    bitset<32> b(5), a(4);
    int n = (b & a).count();
    cout << n << endl;
}