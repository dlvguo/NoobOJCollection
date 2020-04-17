#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
	思路:并查集的操作 涉及到并查集的删除 用俩个数组存储
		使用虚根法，即每次指向根节点是未出现的过的，因此要保证数组开足够大
		其中real[i]=p,表示节点i所存放的位置在father[p]，在father数组进行并查集的操作
		这样可以保证当i节点删除的时候，不会影响原来的节点树结构
*/

const int N = 300003;
int real[N];   //存放i节点的真正位置
int father[N]; //用以并查集操作
int visit[N];
int t; //代表数组末尾未出现的点,用来删除操作存放

//寻找祖先 并使用路径压缩 可以缩短并查集的查找时间
int FindAncestor(int a)
{
    if (father[a] == a)
        return a;
    return father[a] = FindAncestor(father[a]);
}
//并查集联合
void Union(int a, int b)
{
    int an = FindAncestor(real[a]);
    int bn = FindAncestor(real[b]);
    if (an != bn)
    {
        //连a即可
        father[bn] = an;
    }
}

//删除操作
void del(int x)
{
    //指向一个新的未使用的位置，不会影响原先树结构
    real[x] = t;
    father[t] = t++;
}

int main()
{
    int N, M, ans = 1;
    while (scanf("%d%d", &N, &M), N || M)
    {
        t = N;

        for (int i = 0; i < N; i++)
        {
            real[i] = i;
            father[i] = i;
        }

        char a;
        int b, c;
        getchar();
        while (M--)
        {
            scanf("%c", &a);
            if (a == 'M')
            {
                scanf("%d%d", &b, &c);
                Union(b, c);
            }
            else
            {
                scanf("%d", &b);
                del(b);
            }
            getchar();
        }
        memset(visit, 0, sizeof(visit));
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            //查找根  若根未使用过 联盟数+1
            int temp = FindAncestor(real[i]);
            if (!visit[temp])
            {
                visit[temp] = 1;
                res++;
            }
        }
        printf("Case #%d: %d\n", ans++, res);
    }
    return 0;
}