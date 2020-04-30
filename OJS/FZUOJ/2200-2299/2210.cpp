#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    int nums[1005];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(nums, 0, sizeof(int) * (n + 1));
        int a, b;
        while (m--)
        {
            scanf("%d%d", &a, &b);
            nums[a]++;
        }
        int index = 1, max = nums[1];

        for (int i = 2; i <= n; i++)
        {
            if (max < nums[i])
            {
                index = i;
                max = nums[i];
            }
        }
        cout << index << endl;
    }
}