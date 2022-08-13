#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        if (arr[0] == target)
            return 0;

        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (arr[mid] == target)
            {
                while (mid && arr[mid - 1] == arr[mid])
                {
                    mid--;
                }
                return mid;
            }
            // 说明左边有序
            else if (arr[mid] > arr[l])
            {
                if (arr[l] <= target && target < arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (arr[mid] < arr[l])
            {
                if (arr[mid] < target && arr[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
                l++;
        }
        return -1;
    }
};