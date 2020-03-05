#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int low = 0, high = numbers.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (numbers[mid] > numbers[high])
            {
                low = mid + 1;
                continue;
            }
            else if (numbers[high] > numbers[mid])
            {
                high = mid;
            }
            else
                high--;
        }
        return numbers[low];
    }
};