#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, unordered_set<int>> graph;

    void dfs(TreeNode *root)
    {
        if (root->left)
        {
            graph[root->val].emplace(root->left->val);
            graph[root->left->val].emplace(root->val);
            dfs(root->left);
        }

        if (root->right)
        {
            graph[root->val].emplace(root->right->val);
            graph[root->right->val].emplace(root->val);
            dfs(root->right);
        }
    }

    int amountOfTime(TreeNode *root, int start)
    {
        if (!root)
            return 0;
        dfs(root);
        queue<int> q;
        q.push(root->val);

        int res = -1;
        while (q.size())
        {
            int count = q.size();
            while (count--)
            {
                int num = q.front();
                q.pop();
                for (auto t : graph[num])
                {
                    q.push(t);
                    graph[t].erase(num);
                }
            }
            res++;
        }
        return res;
    }
};