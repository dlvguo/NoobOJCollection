#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, vector<int>> mb;
    unordered_map<string, int> mwords;
    vector<string> vts;

    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int vis[13][13] = {0};

    void dfs(int x, int y, int index, vector<vector<char>> &board, string &s)
    {
        if (index > 10)
            return;
        if (mwords.find(s) != mwords.end() && mwords[s])
        {
            vts.push_back(s);
            mwords[s] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int _x = dir[i][0] + x;
            int _y = dir[i][1] + y;
            if (_x < 0 || _y < 0 || _x >= board.size() || _y >= board[0].size() || vis[_x][_y])
                continue;
            vis[_x][_y] = 1;
            s.push_back(board[_x][_y]);
            dfs(_x, _y, index + 1, board, s);
            vis[_x][_y] = 0;
            s.pop_back();
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        for (auto w : words)
        {
            mwords[w]++;
        }
        string s;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                s.push_back(board[i][j]);
                vis[i][j] = 1;
                dfs(i, j, 1, board, s);
                vis[i][j] = 0;
                s.pop_back();
            }
        }

        return vts;
    }
};

int main()
{
    vector<vector<char>> board;
    vector<char> vc = {'o', 'a', 'a', 'n'};
    board.push_back(vc);
    vector<char> vc2 = {'e', 't', 'a', 'e'};
    board.push_back(vc2);
    vector<char> vc3 = {'i', 'h', 'k', 'r'};
    board.push_back(vc3);
    vector<char> vc4 = {'i', 'f', 'l', 'v'};
    board.push_back(vc4);
    vector<string> v = {"oath", "pea", "eat", "rain"};
    Solution s;
    s.findWords(board, v);
}