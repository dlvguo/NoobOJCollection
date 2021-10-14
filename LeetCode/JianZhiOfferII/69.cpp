#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int index = 0, left = 1, right = arr.size() - 2;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid - 1])
            {
                index = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return index;
    }
};