#include <bits/stdc++.h>
using namespace std;

/**
 * 思路：计算每个数字的出现次数
 *      把出现次数大于2且为奇数的数-1 变为偶数
 *      然后如果出现次数大于2的只有0或者没有 则从9到0找出现一次的数返回
 *      否则 出现次数偶数的数字从大到小排列，并且在中间添加一个从9到0找出现一次的数字
 **/
struct node
{
    int num = 0, val = 0;
};

string solution(string &S)
{
    vector<node> nodes;
    for (int i = 0; i < 10; i++)
    {
        node n;
        n.val = i;
        nodes.push_back(n);
    }

    //统计次数
    for (auto ch : S)
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
