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
    //设置状态位0表示无覆盖 1表示覆盖 2表示摄像头
    int res = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 1;
        int l = dfs(root->left), r = dfs(root->right);
        if (!l || !r)
        {
            res++;
            return 2;
        }
        if (l == 2 || r == 2)
            return 1;
        return 0;
    }

    int minCameraCover(TreeNode *root)
    {
        if (!dfs(root))
            res++;
        return res;
    }
};