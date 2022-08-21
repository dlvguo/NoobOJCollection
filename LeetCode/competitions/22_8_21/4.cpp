#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long LL;

    long long kSum(vector<int> &nums, int k)
    {
        priority_queue<LL, vector<LL>, greater<LL>> pq;

        vector<LL> sums(nums.size());

        vector<vector<LL>> temps(2);
        temps[1].push_back(nums[0]);

        sums[0] = nums[0];

        if (k == 1)
        {
            if (nums[0] < 0)
                pq.push(0);
            else
                pq.push(nums[0]);
        }
        else
        {
            pq.push(0);
            pq.push(nums[0]);
        }

        for (int i = 1; i < nums.size(); i++)
        {
            // 获取当前前缀和
            sums[i] = sums[i - 1] + nums[i];
            vector<LL> mvtc;
            mvtc.push_back(sums[i]);

            if (pq.size() < k)
            {
                pq.push(sums[i]);
            }
            else
            {
                if (pq.top() < sums[i])
                {
                    pq.pop();
                    pq.push(sums[i]);
                }
            }

            for (int j = i - 1; j >= 0; j--)
            {
                LL temp = sums[i] - sums[j];
                mvtc.push_back(temp);

                if (pq.size() < k)
                    pq.push(temp);
                else
                {
                    if (pq.top() < temp)
                    {
                        pq.pop();
                        pq.push(temp);
                    }
                }
            }

            if (temps[0].size())
            {
                for (int md = 0; md < temps[0].size(); md++)
                {
                    LL temp = nums[i] + temps[0][md];
                    mvtc.push_back(temp);

                    if (pq.size() < k)
                        pq.push(temp);
                    else
                    {
                        if (pq.top() < temp)
                        {
                            pq.pop();
                            pq.push(temp);
                        }
                    }
                }
            }
            temps[0] = temps[1];
            temps[1] = mvtc;
        }

        return pq.top();
    }
};

int main()
{

    Solution s;
    vector<int> nums = {2, 4, -2};
    cout << s.kSum(nums, 5);
}