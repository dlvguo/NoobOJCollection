#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
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
        queue<Node *> q;
        q.push(root);
        while (q.size())
        {
            int count = q.size();
            count--;
            Node *pre = q.front();
            q.pop();
            if (pre->left)
            {
                q.push(pre->left);
            }
            if (pre->right)
            {
                q.push(pre->right);
            }
            while (count--)
            {
                Node *temp = q.front();
                q.pop();
                pre->next = temp;
                pre = temp;
                if (pre->left)
                {
                    q.push(pre->left);
                }
                if (pre->right)
                {
                    q.push(pre->right);
                }
            }
        }
        return root;
    }
};