#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
       int n = nums.size(), L = 0, R = n;
        vector<int> res;
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) {
                int start = mid - 1, end = mid + 1;  //分别向前和向后查找起始和终止索引
                while(start >= 0 && nums[start] == target) start--;
                res.push_back(start+1);
                while(end < n && nums[end] == target) end++;
                res.push_back(end-1);
                return res;
            }
            else if(nums[mid] < target) L = mid + 1;
            else R = mid;
        }
        return {-1, -1};
    }
};