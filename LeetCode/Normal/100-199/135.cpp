#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int res = 0;
        vector<int> left(ratings.size(), 1);
        // 左规则 当r[i]>r[i-1]则至少要满足left[i]=left[i-1]+1
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }
        // 省内存right不做数组 因为迭代需要i-1 故最右边的数要先处理
        int right = 1, ans = max(right, left.back());
        // 右规则 当r[i-1]>r[i]则至少要满足right[i-1]=right[i]+1
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                right += 1;
            else
            {
                right = 1;
            }
            //取左右规则满足的大的那个数
            ans += max(left[i], right);
        }
        return ans;
    }
};