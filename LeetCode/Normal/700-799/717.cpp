#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;

    bool dfs(vector<int> &bits, int nIndex = 0)
    {
        if (nIndex == n)
            return true;
        // 只能'0'
        if (bits[nIndex] == 0)
        {
            return dfs(bits, nIndex + 1);
        }
        else
        {
            if (nIndex < n - 1)
            {
                return dfs(bits, nIndex + 2);
            }
            return false;
        }
    }

    bool isOneBitCharacter(vector<int> &bits)
    {
        cout << bits.back();
        if (bits.back() != 0)
            return false;
        n = bits.size() - 1;
        return dfs(bits);
    }
};

int main()
{
    Solution s;
    vector<int> bits = {1, 0, 0};
    s.isOneBitCharacter(bits);
}