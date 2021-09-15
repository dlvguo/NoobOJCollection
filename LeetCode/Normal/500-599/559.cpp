#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int _max = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            _max = max(maxDepth(root->children[i]), _max);
        }

        return _max + 1;
    }
};