#include <iostream>
using namespace std;

//Pre->Post
//本来前序和后序不能转换，但是满二叉树可以 因为都是55开
// /2大法 后序最后一个是前序的
void PreToPost(int pre[], int post[], int prestart, int preend, int poststart, int postend)
{
    if (prestart <= preend)
    {
        post[postend] = pre[prestart];
        int half = (preend - prestart) / 2;
        //下标数量自行计算 注意！！！！！！！！！！！！
        PreToPost(pre, post, prestart + 1, prestart + half, poststart, poststart + half-1);
        PreToPost(pre, post, prestart + half + 1, preend,poststart+half, postend-1);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[7];
    PreToPost(a, b, 0, 6, 0, 6);
    for(int i=0;i<7;i++)
        cout<<b[i];
}