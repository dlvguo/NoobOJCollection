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
    unordered_set<int> _set;

    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (findTarget(root->left, k))
            return true;
        if (_set.find(k - root->val) == _set.end())
        {
            _set.insert(root->val);
            return findTarget(root->right, k);
        }
        else
            return true;
    }
};