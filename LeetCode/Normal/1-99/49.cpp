#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string &str : strs)
        {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i)
            {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};