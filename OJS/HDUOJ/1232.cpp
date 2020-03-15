#include <iostream>
#include <cstring>
using namespace std;

int Ns[1002];

int FindHead(int n2)
{
    if (Ns[n2] == -1)
        return n2;
    return FindHead(Ns[n2]);
}



void Union(int n1, int n2)
{
    int n1Head=FindHead(n1);
    int n2Head = FindHead(n2);
    if(n1Head==n2Head)
        return;
    Ns[n2Head] = n1;
}

int main()
{
    int M, N, n1, n2;
    while (cin >> N, N)
    {
        cin >> M;
        //代表头节点
        memset(Ns, -1, sizeof(int) * (N + 1));
        while (M--)
        {
            cin >> n1 >> n2;
            Union(n1, n2);
        }
        //计算Count
        int sum = 0;
        for (int i = 1; i <= N; i++)
        {
            if (Ns[i] == -1)
                sum++;
        }
        cout << sum - 1 << endl;
    }
}