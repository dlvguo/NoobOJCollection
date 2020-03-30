#include <iostream>
using namespace std;
/*最大排线问题 即求最大不相交子集 求解也类似背包问题
  Net[i][j]表示上方接线柱i 连接到下面j
  size[i][i]表示 i到i最大规模 
  解结构 若i > j size(i,j)=0 //无法连线
  若 i<=j 则Max(size(i-1,j),size(i-1,net[i]-1)+1)
  意思为 要么我这个柱子不放 要么放了就加上旁边柱子即  net[i]-1)+1
*/

int Figure(int c[],int len){
    int size[][];
    //初始化
    for (int i = 1; i <= len; i++)
    {
        size[1][i]=i<c[i]?0:1;
    }
    //开始咯
    for (int i = 2; i <=len; i++)
    {
        for (int j = 1; i <=len ; i++)
        {
            if(j<c[i])
                size[i][j]=size[i-1][j];
            else
            {
                size[i][j]=max(size[i-1][j],size[i-1][c[i]-1]+1);
            }
        }
    }
    //回溯输出点集的话
    int t=len;
    for (int j = len; j> 1; i++)
    {
        if(size[j][t]!=size[j-1][t]){
            cout<<j;
            t=c[j]-1;
        }
    }
    if(c[1]<j)
        cout<<1;
    return s[len][len];
}
