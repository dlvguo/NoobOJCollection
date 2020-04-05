#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> vs;
        if (root)
            q.push(root);
        int level = 1;
        while (!q.empty())
        {
            vector<int> v;
            int count = q.size();
            while (count--)
            {
                root = q.front();
                q.pop();
                v.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            //反转是最快的 原来左右放的时候 其实顺序是错的
            if (level % 2 == 0)
                reverse(v.begin(), v.end());
            level++;
            vs.push_back(v);
        }
        return vs;
    }
};