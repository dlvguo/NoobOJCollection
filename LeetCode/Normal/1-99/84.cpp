#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        if (n == 0)
        {
            return 0;
        }

        int ans = 0;

        int p = 0, q = 0, h = 0, last_p = 0, last_q = n - 1;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 0; i < n; ++i)
        {
            h = heights[i];

            if (i > 0 && h > heights[i - 1])
            {
                p = i;
            }
            else
            {
                p = last_p;
                q = last_q;

                while (p > 0 && heights[p - 1] >= h)
                {
                    --p;
                }
            }

            // cout << i << endl;

            left[i] = p;
            last_p = p;
        }

        for (int i = n - 1; i > -1; --i)
        {
            h = heights[i];

            if (i < n - 1 && h > heights[i + 1])
            {
                q = i;
            }
            else
            {
                q = last_q;

                while (q < n - 1 && heights[q + 1] >= h)
                {
                    ++q;
                }
            }

            // cout << i << endl;

            right[i] = q;
            last_q = q;
        }

        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
        }

        return ans;
    }
};