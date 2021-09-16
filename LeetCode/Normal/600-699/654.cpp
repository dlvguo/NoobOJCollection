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
    TreeNode *search(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        //寻找最大值
        int _max = nums[l], _maxIndex = l;
        for (int i = l + 1; i <= r; i++)
        {
            if (_max < nums[i])
            {
                _max = nums[i];
                _maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(nums[_maxIndex]);
        root->left = search(nums, l, _maxIndex - 1);
        root->right = search(nums, _maxIndex + 1, r);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return search(nums, 0, nums.size() - 1);
    }
};