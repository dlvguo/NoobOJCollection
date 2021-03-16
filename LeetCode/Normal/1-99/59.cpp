#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> nums(n, vector<int>(n, 0));
        int l = 0, r = n - 1, up = 0, down = n - 1, num = 1;
        int total = n * n;
        while (num <= total)
        {
            for (int i = l; i <= r; i++)
            {
                nums[up][i] = num++;
            }
            if (num > total)
                break;
            up++;
            for (int i = up; i <= down; i++)
            {
                nums[i][r] = num++;
            }
            if (num > total)
                break;
            r--;
            for (int i = r; i >= l; i--)
            {
                nums[down][i] = num++;
            }
            if (num > total)
                break;
            down--;
            for (int i = down; i >= up; i--)
            {
                nums[i][l] = num++;
            }
            l++;
        }
        return nums;
    }
};

int main()
{
    Solution s;
    s.generateMatrix(3);
}