#include <iostream>
using namespace std;
/* 凸边最多三角形问题
   与矩阵连乘一样 只不过p换成w[][][]
*/

void MatrixChain(int p[], int n, int **m, int **s)
{
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    //类似冒泡的说法 1-n 1-n-1 这样遍历所有的
    for (int r = 2; r <= n; r++)
    {
        //因为后面有一个故n-r+1
        for (int i = 1; i <= n - r + 1; i++)
        {
            //1-2先遍历
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + w[i - 1,i,p];
            s[i][j] = i;
            //然后从i+1——j间寻找值
            for (int k = i + 1; k < j; i++)
            {
                int t = m[i][k] + m[k + 1][j] + w[i - 1,k,j];;
                if (t < m[i][j])
                {
                    m[j][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

//递归法 每个都遍历 若i==j返回0
//并使用备忘录算法 即存储计算过的值
int m[][], p[], n, s[][];

int LookMateri(int i, int j)
{
    if (i == j)
        return 0;
    else if (m[i][j])
        return m[i][j];
    int u = m[i + 1][j] + p[i - 1] * p[i] * [j];
    s[i][j] = i;
    for (int k = i + 1; k < j; k++)
    {
        int t = m[i][k] + m[k + 1][j] + w[i - 1,k,j];;
        if (u > t)
        {
            u = t;
            s[i][j] = k;
        }
    }
    return u;
}

void Materi(int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            LookMateri(i,j);
}