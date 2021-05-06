#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> d;
        d.push_back(first);
        for (int i = 0; i < encoded.size(); i++)
        {
            d.push_back(encoded[i] ^ d.back());
        }
        return d;
    }
};