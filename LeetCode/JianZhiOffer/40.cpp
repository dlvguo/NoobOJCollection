#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         if(k==0)
//             return {};
//         sort(arr.begin(),arr.end());
//         vector<int> a(arr.begin(),arr.begin()+(k-1));
//         return a;
//     }
// };

class Solution
{
public:
    //堆排序吧
    void AddJust(vector<int> &arr, int k, int len)
    {
        int i = k * 2;
        int p = arr[k];
        while (i < len)
        {
            int max = arr[i];
            if ((i + 1) < len && max < arr[i + 1])
            {
                max = arr[i + 1];
                i++;
            }
            if (p > max)
            {
                arr[k] = max;
                k = i;
                i *= 2;
            }
            else
            {
                break;
            }
        }
        arr[k] = p;
    }

    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
            return {};

        for (int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            AddJust(arr, i, arr.size());
        }
        vector<int> a;

        for (int i = 0; i < k; i++)
        {
            swap(arr[arr.size() - 1 - i], arr[i]);
            a.push_back(arr[arr.size() - 1 - i]);
            AddJust(arr, i, arr.size() - i - 1);
        }
        return a;
    }
};