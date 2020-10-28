#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_set<int> hashset;
        int ans = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                ans++;
            }
            else
            {
                if (hashset.count(ans) > 0)
                    return false;
                hashset.insert(ans);
                ans = 1;
            }
        }
        if (hashset.count(ans) > 0)
            return false;
        return true;
    }
};