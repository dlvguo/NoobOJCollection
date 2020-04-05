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
     unordered_map<TreeNode *, int> sums;
public:
    //动态dp树
    int rob(TreeNode* root) {
        return dfsRob(root);
    }
    
    int dfsRob(TreeNode* node) {
        if (!node) return 0;
        if (sums.count(node)) return sums[node];
        //偷取该节点
        int res1 = 0;
        if (node->left) {
            res1 += (dfsRob(node->left->left) + dfsRob(node->left->right));
        }
        if (node->right) {
            res1 += (dfsRob(node->right->left) + dfsRob(node->right->right));
        }
        res1 += node->val;
        //不偷取该节点
        int res2 = dfsRob(node->left) + dfsRob(node->right);
        sums[node] = max(res1, res2);
        return sums[node];
    }
};