#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ABS(int a, int b)
    {
        long long s = a - b;
        return s > 0 ? s : -s;
    }

    int smallestDifference(vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int _min = 2147483647;
        int l = 0, r = 0;

        while (l < a.size() && r < b.size())
        {
            int temp = ABS(a[l], b[r]);
            _min = min(temp, _min);
            if (!_min)
                return _min;
            // 防止溢出
            if (_min < 0)
                _min = 2147483647;
            if (a[l] > b[r])
                r++;
            else
                l++;
        }
        return _min;
    }
};
