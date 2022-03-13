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
    typedef long long LL;
    unordered_map<LL, int> preAns;
    int res = 0;
    int p;
    int pathSum(TreeNode *root, LL targetSum)
    {
        p = targetSum;
        preAns[0] = 1;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, LL total)
    {
        if (!root)
            return;
        // 代表当前的和
        total += root->val;
        LL n = total - p;
        if (preAns.find(n) != preAns.end())
        {
            res += preAns[n];
        }
        preAns[total]++;
        dfs(root->left, total);
        dfs(root->right, total);
        if (preAns[total] == 1)
            preAns.erase(total);
        else
            preAns[total]--;
    }
};