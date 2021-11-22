#include <bits/stdc++.h>
using namespace std;
class MapSum
{
public:
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        cnt[key] = val;
    }

    int sum(string prefix)
    {
        int res = 0;
        for (auto &[key, val] : cnt)
        {
            if (key.substr(0, prefix.size()) == prefix)
            {
                res += val;
            }
        }
        return res;
    }

private:
    unordered_map<string, int> cnt;
};