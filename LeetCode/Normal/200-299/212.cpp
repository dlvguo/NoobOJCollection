#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, vector<int>> mb;
    int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
    int vis[13][13] = {0};

    bool dfs(int x, int y, int index, string &s, vector<vector<char>> &board)
    {
        if (index == s.size())
            return true;
        for (int i = 0; i < 8; i++)
        {
            int _x = dir[i][0] + x;
            int _y = dir[i][1] + y;
            if (_x < 0 || _y < 0 || _x >= board.size() || _y >= board[0].size() || vis[_x][_y] || board[_x][_y] != s[index])
                continue;
            vis[_x][_y] = 1;
            if (dfs(_x, _y, index + 1, s, board))
            {
                vis[_x][_y] = 0;
                return true;
            }
            vis[_x][_y] = 0;
        }
        return false;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> vts;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int c = board[i][j] - 'a';
                if (mb.find(c) != mb.end())
                {
                    mb[c].push_back(i);
                    mb[c].push_back(j);
                }
                else
                {
                    vector<int> v{i, j};
                    mb[c] = v;
                }
            }
        }
        for (int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            int c = s[0] - 'a';

            if (mb.find(c) != mb.end())
            {
                auto v = mb[c];
                for (int j = 0; j < v.size(); j += 2)
                {
                    vis[v[j]][v[j + 1]] = 1;
                    if (dfs(v[j], v[j + 1], 1, s, board))
                    {
                        vts.push_back(s);
                        vis[v[j]][v[j + 1]] = 0;
                        break;
                    }
                    vis[v[j]][v[j + 1]] = 0;
                }
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