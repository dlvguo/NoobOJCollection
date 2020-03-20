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
        int p = arr[k - 1];
        while (i <= len)
        {
            int max = arr[i - 1];
            if ((i + 1) <= len && max < arr[i])
            {
                max = arr[i];
                i++;
            }
            if (p > max)
            {
                arr[k - 1] = max;
                k = i;
                i *= 2;
            }
            else
            {
                break;
            }
        }
        arr[k - 1] = p;
    }

    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
            return {};

        for (int i = arr.size() / 2; i >= 1; i--)
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

int main()
{
    Solution s1;
    vector<int> arr{3, 2, 1};
    s1.getLeastNumbers(arr, 2);
    system("pause");
}