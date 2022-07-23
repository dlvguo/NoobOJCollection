#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> r;

    deque<TreeNode *> dq;

    vector<vector<int>> BSTSequences(TreeNode *root)
    {
        if (!root)
            return {{}};
        dq.push_back(root);
        dfs();
        return res;
    }
    void dfs()
    {
        if (!dq.size())
        {
            res.push_back(r);
            return;
        }

        int s = dq.size();
        while (s--)
        {

            TreeNode *temp = dq.front();
            dq.pop_front();
            //寻找候选节点

            r.push_back(temp->val);

            if (temp->left)
                dq.push_back(temp->left);
            if (temp->right)
                dq.push_back(temp->right);

            dfs();

            if (temp->right)
                dq.pop_back();
            if (temp->left)
                dq.pop_back();

            dq.push_back(temp);
            r.pop_back();
        }
    }
};