#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> res;
        backTrack(res, S, 0, 0, 0);
        return res;
    }

    bool backTrack(vector<int> &res, string S, long long sum, int idx, int prev)
    {
        //当遍历完成
        if (idx == S.size())
        {
            //结果数组长度大于3，则返回True
            return res.size() >= 3;
        }
        long long cur = 0;
        //切分数字
        for (int i = idx; i < S.size(); i++)
        {
            //当前切分数大于最大整型INT_MAX，进行剪枝
            if (i > idx && S[idx] == '0')
            {
                break;
            }
            //计算所切分数的数值大小
            cur = cur * 10 + S[i] - '0';
            //当前数大于前两数之和，剪枝
            if (cur > INT_MAX)
                break;
            //当结果数组长度大于等于2时，
            if (res.size() >= 2)
            {
                //若当前的切分数小于前两数之和，则继续添加下一位
                if (cur < sum)
                    continue;
                //若切分数大于前两数之和，剪枝
                else if (cur > sum)
                    break;
            }
            //当结果数组长度小于2 或 当前数等于前两数之和时将该数加入数组
            res.emplace_back(cur);
            //继续递归，如果后续递归成功则返回true
            if (backTrack(res, S, prev + cur, i + 1, cur))
                return true;
            //如果后续递归结果失败，则回溯
            res.pop_back();
        }
        return false;
    }
};
