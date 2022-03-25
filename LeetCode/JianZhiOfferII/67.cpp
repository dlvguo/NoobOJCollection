#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
将所有值构建为二叉树,从最高位开始建树，方便统计
之后所有值跟这棵树进行计算
假如当前位为1的话，肯定希望这个位0有位置，这样异或就能为1
*/
class Solution
{
public:
    typedef struct node
    {
        node *children[2] = {NULL};
    } * Node;

    const int BITMASK = 30;

    int findMaximumXOR(vector<int> &nums)
    {
        Node root = new node;
        unordered_set<int> _set;
        // 先构树
        for (int i = 0; i < nums.size(); i++)
        {
            // 找不到就建树
            if (_set.find(nums[i]) == _set.end())
            {
                int num = nums[i];
                _set.insert(num);
                Node temp = root;

                for (int i = 1 << BITMASK; i; i = i >> 1)
                {
                    if (num & i)
                    {
                        if (!temp->children[1])
                            temp->children[1] = new node;
                        temp = temp->children[1];
                    }
                    else
                    {
                        if (!temp->children[0])
                            temp->children[0] = new node;
                        temp = temp->children[0];
                    }
                }
            }
        }

        // 遍历每个数
        _set.clear();

        int _max = 0;
        // 遍历每个看最大数
        for (int i = 0; i < nums.size(); i++)
        {
            // 没重复就做
            if (_set.find(nums[i]) == _set.end())
            {
                int num = nums[i];
                _set.insert(num);
                Node temp = root;
                int res = 0;
                for (int i = 1 << BITMASK; i; i = i >> 1)
                {
                    // 当前为1 说明去看2有没有
                    if (num & i)
                    {
                        if (temp->children[0])
                        {
                            temp = temp->children[0];
                            res += i;
                        }
                        else
                            temp = temp->children[1];
                    }
                    else
                    {
                        if (temp->children[1])
                        {
                            res += i;
                            temp = temp->children[1];
                        }
                        else
                            temp = temp->children[0];
                    }
                }
                _max = max(res, _max);
            }
        }

        return _max;
    }
};