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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        //层次遍历
        queue<TreeNode *> tq;
        vector<int> v;
        tq.push(root);
        while (!tq.empty())
        {
            int count = tq.size();
            int tempSize = 0;
            while (count--)
            {
                TreeNode *p = tq.front();
                tq.pop();
                if (p->left)
                {
                    tq.push(p->left);
                    v.push_back(p->left->val);
                    tempSize++;
                }
                else
                {
                    v.push_back(-1);
                }
                if (p->right)
                {
                    tempSize++;
                    tq.push(p->right);
                    v.push_back(p->right->val);
                }
                else
                {
                    v.push_back(-1);
                }
            }
            if (tempSize % 2)
                return false;
            int low = 0, high = v.size() - 1;
            while (low < high)
            {
                if (v[low] != v[high])
                    return false;
                low++;
                high--;
            }
            v.clear();
        }
        return true;
    }
};

//递归法 左节点的左孩子 与 右节点右孩子对比 其余跟平衡二叉树相同
bool dfs(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
}