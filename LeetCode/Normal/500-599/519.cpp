#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand(time(nullptr));
    }

    vector<int> flip()
    {
        int x = rand() % total;
        vector<int> ans;
        total--;
        // 查找位置 x 对应的映射
        if (map.count(x))
        {
            ans = {map[x] / n, map[x] % n};
        }
        else
        {
            ans = {x / n, x % n};
        }
        // 将位置 x 对应的映射设置为位置 total 对应的映射
        if (map.count(total))
        {
            map[x] = map[total];
        }
        else
        {
            map[x] = total;
        }
        return ans;
    }

    void reset()
    {
        total = m * n;
        map.clear();
    }

private:
    int m;
    int n;
    int total;
    unordered_map<int, int> map;
};