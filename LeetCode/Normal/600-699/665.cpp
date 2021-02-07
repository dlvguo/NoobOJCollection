#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //根据贪心只能只能换一次 a[i]>a[i+1] 可以换a[i]或者a[i+1]为了防止影响优先换当前的
    // 1 2 -1 将-1换成2 - 1 2 1 将2换成1  因为a[i]之前已经满足上升序列  
    bool checkPossibility(vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                if (i > 0 && nums[i+1] < nums[i - 1]) {
                    nums[i+1]= nums[i];
                }
            }
        }
        return true;
    }
};
