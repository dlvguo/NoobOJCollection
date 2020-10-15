#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> rq;
        rq.push(root);
        while (rq.size())
        {
            int len = rq.size();
            Node *pre = rq.front();
            rq.pop();
            len--;
            if (pre->left)
            {
                rq.push(pre->left);
            }
            if (pre->right)
            {
                rq.push(pre->right);
            }
            while (len--)
            {
                Node *temp = rq.front();
                rq.pop();
                pre->next = temp;
                pre = temp;
                if (pre->left)
                {
                    rq.push(pre->left);
                }
                if (pre->right)
                {
                    rq.push(pre->right);
                }
            }
        }
        return root;
    }
};