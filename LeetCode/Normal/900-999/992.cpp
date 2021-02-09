#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0;
        while (right < A.size()) {
            ++mp[A[right++]];
            while (mp.size() > K) {
                --mp[A[left]];
                if (mp[A[left]] == 0) mp.erase(A[left]);
                ++left;
            }
            // 如果这里改成 ret = max(ret, right - left)，那么此函数就是 LeetCode 904 题的解。
            // 这里可以用动态规划的思想来理解 ret += right - left
            // right 增加一次，增加的数组个数可以用 right - left 来表示
            ret += right - left;
        }
        return ret;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A, K) - GetMostDistinct(A, K - 1);
    }
};



int main()
{

    vector<int> A = {1, 2, 1, 2, 3};
    Solution s;
    s.subarraysWithKDistinct(A,2);
    return 0;
}