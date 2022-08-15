#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // a1size大于 a2size
    vector<int> findSwapValue2(vector<int> &array1, vector<int> &array2)
    {
        unordered_set<int> aset;
        long long diff = 0;
        for (int i = 0; i < array1.size(); i++)
        {
            diff += array1[i];
            if (i < array2.size())
            {
                diff -= array2[i];
                aset.emplace(array2[i]);
            }
        }
        if (diff % 2 == 0)
        {
            diff /= 2;
            for (int i = 0; i < array1.size(); i++)
            {
                if (aset.find(array1[i] - diff) != aset.end())
                    return {array1[i], int(array1[i] - diff)};
            }
        }

        return {};
    }

    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2)
    {
        if (array1.size() < array2.size())
            return findSwapValue2(array2, array1);
        return findSwapValue2(array1, array2);
    }
};