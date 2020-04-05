#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (!k)
        return {};
    vector<int> n;
    deque<int> maxQ;
    int max = nums[0], right;
    for (right = 0; right < k; right++)
    {
        while (!maxQ.empty() && maxQ.back() < nums[right])
        {
            maxQ.pop_back();
        }
        maxQ.push_back(nums[right]);
    }
    n.push_back(maxQ.front());
    for (; right < nums.size(); right++)
    {
        if (maxQ.front() == nums[right - k])
            maxQ.pop_front();
        while (!maxQ.empty() && maxQ.back() < nums[right])
        {
            maxQ.pop_back();
        }
        maxQ.push_back(nums[right]);
        n.push_back(maxQ.front());
    }
    return n;
}