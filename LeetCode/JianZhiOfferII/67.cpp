#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    typedef struct node
    {
        node *children[2]={NULL};
    } * Node;
    const int 

    int findMaximumXOR(vector<int> &nums)
    {
        Node root = new node;
        unordered_set<int> _set;
        for (int i = 0; i < nums.size(); i++)
        {
            // 找不到就建树
            if (_set.find(nums[i]) == _set.end())
            {
                int num = nums[i];
                _set.insert(num);
                Node temp = root;
                while (num)
                {
                    if (num & 1)
                    {
                        if (!temp->children[1])
                        {
                            temp->children[1] = new node;
                        }
                        temp = temp->children[1];
                    }
                    else
                    {
                        if (!temp->children[0])
                        {
                            temp->children[0] = new node;
                        }
                        temp = temp->children[0];
                    }

                    num = num >> 1;
                }
            }
        }
        int res = 0;
        int bit = 1;
        while (root)
        {
            if (root->children[1])
            {
                res += bit;
                root = root->children[1];
            }
            else if (root->children[0])
            {
                root = root->children[0];
            }
            else
                break;
            bit = bit << 1;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vts = {3, 10, 5, 25, 2, 8};
    s.findMaximumXOR(vts);
}