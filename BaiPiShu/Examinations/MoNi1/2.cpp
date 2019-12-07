#include<iostream>
#include<algorithm>
#include<iostream>
using namespace std;

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
//用贪心 每次选最大的切割就能保证每次木板每次变最短
int Shortest(int woodLen,int len[],int n){//这个方法是可以的 但主流发现是Hauman
    //给len从大到小排序
    qsort(len,n,sizeof(len),cmp);
    int sum=0;
    for (int i = 1; i <=n; i++)
    {
        sum+=woodLen;
        woodLen-=len[i];
    }
    return sum;
}

//哈夫曼 每次选最小的俩个 这个就是当初切的 之后网上累加即可