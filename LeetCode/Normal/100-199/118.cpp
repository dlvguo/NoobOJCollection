#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (!numRows)
            return {};
        vector<vector<int>> vts;
        vts.push_back({1});
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> vt = {1};
            int h = i % 2 ? i / 2 + 1 : i / 2;
            for (int j = 2; j <= h; j++)
            {
                int t = vts[i - 2][j - 2] + vts[i - 2][j - 1];
                vt.push_back(t);
            }
            int num = i / 2;
            while (num)
            {
                vt.push_back(vt[--num]);
            }
            vts.push_back(vt);
        }
        return vts;
    }
};

int main(){
    Solution s;
    s.generate(5);
}