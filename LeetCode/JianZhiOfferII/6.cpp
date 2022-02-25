#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int num = numbers[left] + numbers[right];
            if (num == target)
                return {left, right};
            else if (num < target)
            {
                left++;
            }
            else
                right--;

            /* code */
        }
        return {0, 0};
    }
};