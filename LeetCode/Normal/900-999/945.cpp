#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //注意数组范围
    int minIncrementForUnique(vector<int> &A)
    {
        if (A.size() == 0 || A.size() == 1)
            return A.size();
        int a[50005] = {0};
        for (int i = 0; i < A.size(); i++)
        {
            a[A[i]]++;
        }
        //找最后一个move
        int sum = 0, count = 0, nextIndex = 0;
        while (a[nextIndex] == 0 && nextIndex)
        {
            nextIndex++;
        }

        for (int i = nextIndex; count < A.size() && i < 50000 && nextIndex < 50000; i++)
        {
            if (a[i] > 1)
            {
                if (nextIndex < i)
                    nextIndex = i;
                while (a[i] > 1)
                {
                    //找到下一个不等于1的
                    while (nextIndex < 50000 && a[nextIndex])
                    {
                        nextIndex++;
                    }
                    a[nextIndex] = 1;
                    sum += (nextIndex - i);
                    a[i]--;
                }
                count++;
            }
            else if (a[i] == 1)
            {
                if (nextIndex < i)
                    nextIndex = i;
                count++;
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> v{3, 2, 1, 2, 1, 7};
    Solution s1;
    s1.minIncrementForUnique(v);
}