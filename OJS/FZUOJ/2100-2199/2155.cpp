#include <iostream>
#include <cstring>
using namespace std;

//假爹法 祖先是无论都不会出现的元素

int countryroot[100005];
int countryreverseroot[100005];

int FindAncesor(int a)
{
    if (countryroot[a] == -1)
        return a;
    return FindAncesor(countryroot[a]);
}
//并查集联合
void Union(int a, int b)
{
    int aroot = FindAncesor(a);
    int broot = FindAncesor(b);
    if (aroot != broot)
    {
        //连a即可
        countryroot[broot] = a;
        countryreverseroot[a] = b;
    }
}

int main()
{
    int N, M;
    while (scanf("%d%d", &N, &M), N || M)
    {
        //-1表示未访问过
        memset(countryroot, -1, sizeof(int) * N + 1);
        memset(countryreverseroot, -1, sizeof(int) * N + 1);

        char a;
        int b, c;

        while (M--)
        {
            scanf("%c", &a);
            if (a == 'M')
            {
                scanf("%d%d", &b, &c);
            }
            else
            {
                scanf("%d%d", &b);
            }
        }
        return 0;
    }