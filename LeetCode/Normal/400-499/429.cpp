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
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<Node *> nq;
        nq.push(root);
        while (nq.size())
        {
            int num = nq.size();
            vector<int> v;
            while (num--)
            {
                Node *p = nq.front();
                nq.pop();
                v.push_back(p->val);
                for (int i = 0; i < p->children.size(); i++)
                {
                    nq.push(p->children[i]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};