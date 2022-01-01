#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        // 枚举 status 通过一次交换操作得到的状态
        auto get = [&](string &status) -> vector<string>
        {
            vector<string> ret;
            int x = status.find('0');
            for (int y : neighbors[x])
            {
                swap(status[x], status[y]);
                ret.push_back(status);
                swap(status[x], status[y]);
            }
            return ret;
        };

        string initial;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                initial += char(board[i][j] + '0');
            }
        }
        if (initial == "123450")
        {
            return 0;
        }

        queue<pair<string, int>> q;
        q.emplace(initial, 0);
        unordered_set<string> seen = {initial};

        while (!q.empty())
        {
            auto [status, step] = q.front();
            q.pop();
            for (auto &&next_status : get(status))
            {
                if (!seen.count(next_status))
                {
                    if (next_status == "123450")
                    {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};
