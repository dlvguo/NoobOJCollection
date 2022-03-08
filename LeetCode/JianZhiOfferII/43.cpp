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

class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> curNodes;
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur->left == nullptr || cur->right == nullptr) {
                curNodes.push(cur);
            } // 将存在 [空后代] 的节点放入 curNodes 中

            if (cur->left != nullptr) {
                q.push(cur->left);
            } // 将可能是空的节点按照层序遍历的顺序放入答案中 

            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
    
    int insert(int v) {
        auto cur = curNodes.front();
        if (cur->left == nullptr) {
            cur->left = new TreeNode(v);
            curNodes.push(cur->left);  // 左节点入总队列
        } else if (cur->right == nullptr) {
            cur->right = new TreeNode(v);
            curNodes.push(cur->right); // 右节点入总队列
            curNodes.pop(); // 只有左右全部填满之后才弹出队列
        }
        return cur->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

