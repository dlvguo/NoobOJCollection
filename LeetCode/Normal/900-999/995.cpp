#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int len = A.size();
        queue<int> q;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            // 当前滑动窗口滑动过程中要保持新位置j<i+K 保持K长度  超出需要删除队首元素
            if (!q.empty() && i >= q.front() + K)
            {
                q.pop();
            }
            if (q.size() % 2 == A[i])
            {
                if (i + K > len)
                {
                    return -1;
                }
                q.push(i);
                res++;
            }
        }
        return res;
    }
};