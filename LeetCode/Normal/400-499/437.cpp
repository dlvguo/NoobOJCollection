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

// class Solution
// {
// public:
//     int res = 0;

//     void dfs(TreeNode *root, int targetSum)
//     {
//         if (!root)
//             return;
//         if (root->val == targetSum)
//             res++;
//         dfs(root->left, targetSum - root->val);
//         dfs(root->right, targetSum - root->val);
//     }

//     int pathSum(TreeNode *root, int targetSum)
//     {
//         stack<TreeNode *> ts;
//         if (!root)
//             return res;
//         ts.push(root);
//         while (ts.size())
//         {
//             TreeNode *temp = ts.top();
//             ts.pop();
//             if (temp->left)
//                 ts.push(temp->left);
//             if (temp->right)
//                 ts.push(temp->right);
//             dfs(temp, targetSum);
//         }

//         return res;
//     }
// };

class Solution
{
public:
    int res = 0;
    unordered_map<int, int> preMap;

    void dfs(TreeNode *root, int targetSum, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        if (preMap.find(sum - targetSum) != preMap.end())
            res += preMap[sum - targetSum];
        if (preMap.find(sum) != preMap.end())
            preMap[sum]++;
        else
            preMap[sum] = 1;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        preMap[sum]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        //前缀和注意0的时候为1
        preMap[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};
