#include <bits/stdc++.h>
using namespace std;

class SummaryRanges
{
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int val)
    {
        // 找到 l1 最小的且满足 l1 > val 的区间 interval1 = [l1, r1]
        // 如果不存在这样的区间，interval1 为尾迭代器
        auto interval1 = intervals.upper_bound(val);
        // 找到 l0 最大的且满足 l0 <= val 的区间 interval0 = [l0, r0]
        // 在有序集合中，interval0 就是 interval1 的前一个区间
        // 如果不存在这样的区间，interval0 为尾迭代器
        auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

        if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second)
        {
            // 情况一
            return;
        }
        else
        {
            bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
            bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
            if (left_aside && right_aside)
            {
                // 情况四
                int left = interval0->first, right = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left, right);
            }
            else if (left_aside)
            {
                // 情况二
                ++interval0->second;
            }
            else if (right_aside)
            {
                // 情况三
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            }
            else
            {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (const auto &[left, right] : intervals)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
