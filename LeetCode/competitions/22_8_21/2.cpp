#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct node
    {
        int num = 0, val = 0;
    };

    string largestPalindromic(string num)
    {
        vector<node> nodes;
        for (int i = 0; i < 10; i++)
        {
            node n;
            n.val = i;
            nodes.push_back(n);
        }

        //统计次数
        for (auto ch : num)
        {
            int num = ch - '0';
            nodes[num].num++;
        }

        vector<node> nnodes;
        // 从大往后放 存放次数超过>=2的数
        for (int i = 9; i >= 0; i--)
        {
            if (nodes[i].num > 1)
            {
                nnodes.push_back(nodes[i]);
            }
        }
        // 说明没有俩个偶数的 或者最大为0
        if (nnodes.size() == 0 || nnodes.front().val == 0)
        {
            // 找出现过的数字 返回
            for (int i = 9; i >= 0; i--)
            {
                if (nodes[i].num)
                {
                    return to_string(i);
                }
            }
        }

        string res = "";
        for (int i = 0; i < nnodes.size(); i++)
        {
            char ch = '0' + nnodes[i].val;
            int temp = nnodes[i].num / 2;
            while (temp--)
            {
                res.push_back(ch);
            }
        }

        int size = res.size() - 1;

        // 考虑一个中间再取一个最大值的
        for (int i = 9; i >= 0; i--)
        {
            // 这个就是构成全栈的
            if (nodes[i].num % 2)
            {
                res.push_back('0' + i);
                break;
            }
        }

        for (int i = size; i >= 0; i--)
        {
            res.push_back(res[i]);
        }

        return res;
    }
};