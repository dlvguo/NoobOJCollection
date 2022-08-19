#include <bits/stdc++.h>
using namespace std;

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

    for (auto ch : S)
    {
        int num = ch - '0';
        nodes[num].num++;
    }

    for (int i = 0; i < 10; i++)
    {
        // 变为偶数 其次 1 的话就不减了
        if (nodes[i].num > 2 && nodes[i].num % 2)
            nodes[i].num--;
    }

    vector<node> nnodes;
    // 从大往后放
    for (int i = 9; i >= 0; i--)
    {
        // 这个就是构成全栈的
        if (nodes[i].num > 1)
        {
            nnodes.push_back(nodes[i]);
        }
    }
    // 说明没有俩个偶数的 或者最大为0
    if (nnodes.size() == 0 || nnodes.front().val == 0)
    {
        for (int i = 9; i >= 0; i--)
        {
            // 这个就是构成全栈的
            if (nodes[i].num)
            {
                return to_string(i);
            }
        }
    }

    string res = "";
    // 添加一半就行 后面revers下
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
        if (nodes[i].num == 1)
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
    // 0分开考虑 0最多 那就看看后面的是否为偶数?

    // write your code in C++ (C++14 (g++ 6.2.0))
}

int main()
{
    string str = "8199";
    cout << solution(str) << endl;
}