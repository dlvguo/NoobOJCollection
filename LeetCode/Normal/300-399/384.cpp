#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> origin;
    vector<int> current;
    int n;

    Solution(vector<int> &nums)
    {
        origin = nums;
        current = nums;
        n = nums.size();
    }

    vector<int> reset()
    {
        current = origin;
        return current;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < n; i++)
        {
            int tmp;
            int target = i + rand() % (n - i);
            tmp = current[i];
            current[i] = current[target];
            current[target] = tmp;
        }
        return current;
    }
};
