#include <bits/stdc++.h>
using namespace std;
/*
使用贪心思想:假设没有k个次数限制,只需要每次找到当前能资金能够启动的项目依次添加
当k个限制之后,每次寻找当前资金能够获得的最大利润，之后资金加上利润继续寻找直到k次
使用俩个优先队列存储 一个按启动资金从小到大排列 另外一个按利润从大到小排列
*/

class Solution
{
public:
    struct node
    {
        int pro;
        int cap;
        bool operator<(const node &b) const
        {
            return cap > b.cap;
        }
        node(int p, int c) : pro(p), cap(c)
        {
        }
    };

    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        //使用俩个优先队列
        //按启动资金从小到大排列
        priority_queue<node> nodeQ;
        for (int i = 0; i < profits.size(); i++)
        {
            node n(profits[i], capital[i]);
            nodeQ.push(n);
        }
        //按利润从大到小排列
        priority_queue<int, vector<int>, less<int>> pQ;
        while (k--)
        {
            //依次弹出小于等于当前资金的元素
            while (!nodeQ.empty() && w >= nodeQ.top().cap)
            {
                pQ.push(nodeQ.top().pro);
                nodeQ.pop();
            }
            //当前资金加上当前资金能获取的最大利润
            if (pQ.empty())
            {
                break;
            }
            else
            {
                w += pQ.top();
                pQ.pop();
            }
        }
        return w;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1, 2, 3}, v2 = {0, 1, 1};
    cout << s.findMaximizedCapital(2, 0, v1, v2);
}