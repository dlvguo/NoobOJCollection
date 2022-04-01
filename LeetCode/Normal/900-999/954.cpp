#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> umap;

        for (int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (umap.find(arr[i]) != umap.end())
            {
                int num;
                if (arr[i] > 0)
                {
                    num = arr[i] * 2;
                }
                //除法注意带有余数的情况
                else
                {
                    if (arr[i] & 1)
                        return false;
                    num = arr[i] / 2;
                }

                if (umap.find(num) == umap.end() || umap[arr[i]] > umap[num])
                    return false;

                umap[num] -= umap[arr[i]];
                umap.erase(arr[i]);
                if (!umap[num])
                    umap.erase(num);
            }
        }
        return true;
    }
};
