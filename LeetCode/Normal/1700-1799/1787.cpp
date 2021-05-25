#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // x 的范围为 [0, 2^10)
    static constexpr int MAXX = 1 << 10;
    // 极大值，为了防止整数溢出选择 INT_MAX / 2
    static constexpr int INFTY = INT_MAX / 2;

public:
    int minChanges(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> f(MAXX, INFTY);
        // 边界条件 f(-1,0)=0
        f[0] = 0;

        for (int i = 0; i < k; ++i)
        {
            // 第 i 个组的哈希映射
            unordered_map<int, int> cnt;
            int size = 0;
            for (int j = i; j < n; j += k)
            {
                ++cnt[nums[j]];
                ++size;
            }

            // 求出 t2
            int t2min = *min_element(f.begin(), f.end());

            vector<int> g(MAXX, t2min);
            for (int mask = 0; mask < MAXX; ++mask)
            {
                // t1 则需要枚举 x 才能求出
                for (auto [x, countx] : cnt)
                {
                    g[mask] = min(g[mask], f[mask ^ x] - countx);
                }
            }

            // 别忘了加上 size
            for_each(g.begin(), g.end(), [&](int &val)
                     { val += size; });
            f = move(g);
        }

        return f[0];
    }
};
