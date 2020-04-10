#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int _hash[66666] = {0, 0, 1};

int Judge(int x)
{
    for (int i = 2; i <= sqrt(1.0 * x); i++)
    {
        if (x % i == 0)
            return i;
    }
    return 0;
}

int main()
{

    int k;
    cin >> k;
    while (k--)
    {
        vector<int> nums;
        vector<int> temp;
        int x;
        cin >> x;
        temp.push_back(x);
        while (temp.size())
        {
            x = temp.back();
            temp.pop_back();
            if (_hash[x])
            {
                nums.push_back(x);
            }
            else
            {
                int t = Judge(x);
                if (!t)
                {
                    _hash[t] = 1;
                    nums.push_back(x);
                }
                else
                {
                    temp.push_back(t);
                    temp.push_back(x / t);
                }
            }
        }
        sort(nums.begin(), nums.end());
        printf("%d", nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            printf("*%d", nums[i]);
        }
        printf("\n");
    }
}