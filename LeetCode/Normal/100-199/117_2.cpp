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

/*
利用原来的树结构,每一层已经构造的next遍历，遍历的下一层子节点用next连接
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *startroot = root, *pre = NULL;
        while (startroot)
        {
            Node *s = startroot;
            startroot = NULL;
            while (s)
            {
                if (s->left)
                {
                    if (!startroot)
                    {
                        startroot = s->left;
                        pre = s->left;
                    }
                    else
                    {
                        pre->next = s->left;
                        pre = pre->next;
                    }
                }
                if (s->right)
                {
                    if (!startroot)
                    {
                        startroot = s->right;
                        pre = s->right;
                    }
                    else
                    {
                        pre->next = s->right;
                        pre = pre->next;
                    }
                }
                s = s->next;
            }
        }
        return root;
    }
};