#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> targetmap;
        //将数组映射0-n-1
        for (int i = 0; i < target.size(); i++)
        {
            targetmap[target[i]] = i;
        }
        //构建
        vector<int> narr, p;

        for (int i = 0; i < arr.size(); i++)
        {
            auto f = targetmap.find(arr[i]);
            if (f != targetmap.end())
            {
                narr.push_back(targetmap[arr[i]]);
            }
        }
        //寻找narr最长路径
        if (narr.size() == 0)
            return target.size();
        p.push_back(narr[0]);
        for (int i = 1; i < narr.size(); i++)
        {
            if (p.back() < narr[i])
                p.push_back(narr[i]);
            //二分查找比back小的最大那个数字
            int left = 0, right = p.size() - 1, t = left;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (p[mid] < narr[i])
                    left = mid + 1;
                else
                {
                    t = mid;
                    right = mid - 1;
                }
            }
            p[t] = narr[i];
        }
        return target.size() - p.size();
    }
};
