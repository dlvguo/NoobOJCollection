#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 1; j < n; ++j)
                matrix[i][j] ^= matrix[i][j - 1];

        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i)
                matrix[i][j] ^= matrix[i - 1][j];

        priority_queue<int, vector<int>, greater<int>> q;
        for (auto &vec : matrix)
        {
            for (auto &x : vec)
            {
                //cout << x << " ";
                if (q.size() < k)
                    q.push(x);
                else if (x > q.top())
                {
                    q.pop();
                    q.push(x);
                }
            }
            //cout << endl;
        }
        return q.top();
    }
};
