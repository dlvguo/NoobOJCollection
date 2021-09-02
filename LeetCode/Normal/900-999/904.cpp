#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int a = fruits[0], b, c, anum = 1, bnum = 0, ans = 1, i, left = 0;
        for (i = 1; i < fruits.size(); i++)
        {
            if (fruits[i] != a)
            {
                b = fruits[i];
                bnum = 1;
                break;
            }
            anum++;
        }
        ans = bnum + anum;
        for (i = i + 1; i < fruits.size(); i++)
        {
            if (fruits[i] == a)
            {
                anum++;
            }
            else if (fruits[i] == b)
            {
                bnum++;
            }
            else
            {
                //说明有第三个了
                ans = max(ans, anum + bnum);
                //删除其中一个有0的就行 不能删最左边否则会导致输入减少的问题
                while (anum && bnum)
                {
                    if (fruits[left++] == a)
                        anum--;
                    else
                    {
                        bnum--;
                    }
                }
                if (!anum)
                {
                    a = fruits[i];
                    anum = 1;
                }
                else
                {
                    b = fruits[i];
                    bnum = 1;
                }
            }
        }
        ans = max(ans, anum + bnum);
        return ans;
    }
};

int main()
{
    vector<int> v = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    Solution s;
    cout << s.totalFruit(v);
}