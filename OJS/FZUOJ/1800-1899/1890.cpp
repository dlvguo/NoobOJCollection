#include <iostream>
using namespace std;

int main()
{
    int nums[105];
    int t, n, m, a, b, max;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }
        while (m--)
        {
            cin >> a >> b;
            if (a > 0)
            {
                nums[b] *= 2;
            }
            else if (a < 0)
            {
                nums[b] += 2;
            }
        }
        max = nums[1];
        for (int i = 2; i <= n; i++)
        {
            if (max < nums[i])
                max = nums[i];
        }
        cout << max << endl;
    }
}