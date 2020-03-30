#include <iostream>
using namespace std;
//桥墩问题 有N个石墩 设有数组Distan[N-1] Dis[i]表示i到i+1的距离
//思路：从a石墩向俩边扩张 每次比较左右俩边小的那个石墩 直至找完
void SearchK(int Dis[], int n, int a, int k)
{
    //Dis[]下标为1-N-1 left表示左边到dis距离 right表示右边距离 因为a到下一个距离为dis[a]于是right=a初始
    int left = a - 1, right = a, leftdis = 0, rightdis = 0; 
    while (k--)//k次循环每次找一个
    {
        if (left < 1)
        { //说明左边到顶了 只能选右边
            right++;
            cout << right; //表示右边的节点
            continue;
        }
        else if (right >= n)
        { //表面右边到底了于是只能选左边的点
            cout << left;
            left--;
            continue;
        }
        else if (leftdis + Dis[left] > rightdis + Dis[right])
        {
            rightdis += Dis[right];
            right++;
            cout << right;
        }
        else
        {
            leftdis += Dis[left];
            cout << left;
            left--;
        }
    }
}