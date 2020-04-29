#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length() - 1;
        int low = 0, high = n;

        //查找顶峰
        while (low < high)
        {
            int mid = (low + high) / 2;
            //说明是在上升序列g
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                low = mid + 1;
            }
            //说明是在下降序列
            else
            {
                high = mid;
            }
        }
        int peek = low;
        //代表最高点
        high = peek;
        low = 0;
        //先找左序列
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int num = mountainArr.get(mid);
            //说明是在上升序列
            if (num == target)
            {
                return mid;
            }
            else if (num < target)
            {
                low = mid + 1;
            }
            //说明是在下降序列
            else
            {
                high = mid - 1;
            }
        }
        low = peek + 1;
        high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int num = mountainArr.get(mid);
            //说明是在上升序列
            if (num == target)
            {
                return mid;
            }
            else if (num > target)
            {
                low = mid + 1;
            }
            //说明是在下降序列
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
}