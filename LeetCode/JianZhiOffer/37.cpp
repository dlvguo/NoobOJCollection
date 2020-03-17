#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str;
        if (!root)
            return str;
        queue<TreeNode *> tqueue;
        tqueue.push(root);
        str += to_string(root->val);
        while (!tqueue.empty())
        {
            TreeNode *t = tqueue.front();
            tqueue.pop();
            if (t->left)
            {
                tqueue.push(t->left);
                str.push_back(',');
                str += to_string(t->left->val);
            }
            else
            {
                str += ",null";
            }
            if (t->right)
            {
                tqueue.push(t->right);
                str.push_back(',');
                str += to_string(t->right->val);
            }
            else
            {
                str += ",null";
            }
        }
        while (str.back() == 'l')
        {
            for (int i = 0; i < 5; i++)
            {
                str.pop_back();
            }
        }
        return str;
    }

    //转化问题重注意大小写和不止一个字符的可能
    int Figure(string str, int &index)
    {
        int tag=1;
        if(str[index]=='-'){
            tag=-1;
            index++;
        }
        int num = 0;
        while (index < str.size() && str[index] >= '0' && str[index] <= '9')
        {
            num = num * 10 + str[index] - '0';
            index++;
        }
        index++;
        return num*tag;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        TreeNode *root = new TreeNode(data[0] - '0');
        int index = 2;
        queue<TreeNode *> tqueue;
        tqueue.push(root);
        while (index < data.size() && !tqueue.empty())
        {
            TreeNode *t = tqueue.front();
            tqueue.pop();
            if (data[index] == 'n')
            {
                index += 5;
            }
            else
            {
                TreeNode *p = new TreeNode(Figure(data, index));
                t->left = p;
                tqueue.push(p);
            }
            if (index < data.size())
            {
                if (data[index] == 'n')
                    index += 5;
                else
                {
                    TreeNode *p = new TreeNode(Figure(data, index));
                    t->right = p;
                    tqueue.push(p);
                }
            }
        }
        return root;
    }
};

int main()
{
    Codec c;
    string str = "1,-1,2,-2";
    TreeNode *t = c.deserialize(str);
    cout << c.serialize(t) << endl;
    system("pause");
}
