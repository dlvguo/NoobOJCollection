#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 100010

/*
    思路：树形dp题注意将树的序列映射成二叉树，根据图形和序列可观察，序列是按先序二叉树给出，序列长度就为二叉树节点个数，并且第一个为根节点

    状态转移方程: 其中1表示最大值 0表示最小值
    dp[i][green][0]表示以节点i为根节点的子树中含有绿色的个数，其中节点i为绿色

    若有俩个孩节点
    dp[i][green][0]=min(dp[i->leftChild][red][0]+dp[i->rightChild][blue][0],dp[i->leftChild][blue][0]+dp[i->rightChild][red][0])+1  除了绿色其他颜色不需要+1

    若有1个孩节点 统一映射在左孩子
    dp[i][green][0]=min(dp[i->leftChild][red][0],dp[i->leftChild][blue][0])+1  除了绿色其他颜色不需要+1
    
    若无孩节点有
    dp[i][green][0]=1 dp[i][red][0]=0
    
*/

enum color
{
    red = 0,
    green = 1,
    blue = 2
};

int dp[N][3][2], index; //dp[n][2][1]表示以n为父节点染色为绿色的最大和

//Trees[1]表示编号为1的节点
struct TreeNode
{
    int leftChild, rightChild; //表示左右子节点的ID 若为0说明为不存在子节点
} Trees[N];

//映射二叉树 先序遍历
void MapBinTree(string &str)
{
    if (index >= str.size())
        return;
    if (str[index] == '0')
    { //说明没有子节点返回
        Trees[index].leftChild = 0;
        Trees[index].rightChild = 0;
        index++;
        return;
    }
    else if (str[index] == '1')
    {
        //说明只有一个子节点 子节点就为先序下一个遍历的节点
        Trees[index].leftChild = index + 1;
        Trees[index].rightChild = 0;
        index++;
        MapBinTree(str);
    }
    else //说明有俩个孩子节点
    {
        int temp = index;
        index++;
        //先序下一个节点为左孩子
        Trees[temp].leftChild = index;
        //拓展左节点
        MapBinTree(str);
        //拓展右节点
        Trees[temp].rightChild = index;
        MapBinTree(str);
    }
}

int main()
{
    string seq; //seq节点编号会与Trees编号对应
    while (cin >> seq)
    {
        index = 0;
        MapBinTree(seq);
        //0表示最小值 1表示最大值
        index = seq.size() - 1;
        //从后往前递归即可遍历所有节点
        while (index >= 0)
        {
            //说明有俩个节点
            if (seq[index] == '2')
            {
                dp[index][green][1] = max(dp[Trees[index].leftChild][red][1] + dp[Trees[index].rightChild][blue][1], dp[Trees[index].leftChild][blue][1] + dp[Trees[index].rightChild][red][1]) + 1;
                dp[index][blue][1] = max(dp[Trees[index].leftChild][red][1] + dp[Trees[index].rightChild][green][1], dp[Trees[index].leftChild][green][1] + dp[Trees[index].rightChild][red][1]);
                dp[index][red][1] = max(dp[Trees[index].leftChild][green][1] + dp[Trees[index].rightChild][blue][1], dp[Trees[index].leftChild][blue][1] + dp[Trees[index].rightChild][green][1]);

                dp[index][green][0] = min(dp[Trees[index].leftChild][red][0] + dp[Trees[index].rightChild][blue][0], dp[Trees[index].leftChild][blue][0] + dp[Trees[index].rightChild][red][0]) + 1;
                dp[index][blue][0] = min(dp[Trees[index].leftChild][red][0] + dp[Trees[index].rightChild][green][0], dp[Trees[index].leftChild][green][0] + dp[Trees[index].rightChild][red][0]);
                dp[index][red][0] = min(dp[Trees[index].leftChild][green][0] + dp[Trees[index].rightChild][blue][0], dp[Trees[index].leftChild][blue][0] + dp[Trees[index].rightChild][green][0]);
            }
            //一个节点
            else if (seq[index] == '1')
            {
                dp[index][green][1] = max(dp[Trees[index].leftChild][red][1], dp[Trees[index].leftChild][blue][1]) + 1;
                dp[index][blue][1] = max(dp[Trees[index].leftChild][red][1], dp[Trees[index].leftChild][green][1]);
                dp[index][red][1] = max(dp[Trees[index].leftChild][green][1], dp[Trees[index].leftChild][blue][1]);

                dp[index][green][0] = min(dp[Trees[index].leftChild][red][0], dp[Trees[index].leftChild][blue][0]) + 1;
                dp[index][blue][0] = min(dp[Trees[index].leftChild][red][0], dp[Trees[index].leftChild][green][0]);
                dp[index][red][0] = min(dp[Trees[index].leftChild][green][0], dp[Trees[index].leftChild][blue][0]);
            }
            else
            {
                dp[index][green][0] = 1;
                dp[index][red][0] = 0;
                dp[index][blue][0] = 0;

                dp[index][green][1] = 1;
                dp[index][red][1] = 0;
                dp[index][blue][1] = 0;
            }
            index--;
        }
        //注意判断下 根节点不一定染绿
        printf("%d %d\n", max(dp[0][green][1], max(dp[0][red][1], dp[0][blue][1])), min(dp[0][green][0], min(dp[0][red][0], dp[0][blue][0])));
    }
    return 0;
}