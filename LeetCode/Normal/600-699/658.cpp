#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool
             { return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b; });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
