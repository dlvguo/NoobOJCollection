#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

//重点是找到矩阵
struct Matrix
{
    //OJ上面可能不支持这个直接赋值
    int m[5][5];

    Matrix()
    {
        memset(m, 0, sizeof(m));
    }

    void init()
    {
        m[1][1] = 1;
        m[1][2] = 1;
        m[2][2] = 3;
        m[2][3] = 2;
        m[2][4] = 7;
        m[3][2] = 1;
        m[4][3] = 1;
    }

    void unit()
    {
        for (int i = 1; i <= 4; i++)
        {
            m[i][i] = 1;
        }
    }
};

//矩阵相乘
Matrix mul(Matrix a, Matrix b)
{
    Matrix c;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % 2009;
            }
        }
    }
    return c;
}

//计算矩阵平方
Matrix Pow(int n)
{
    Matrix res;
    Matrix mt;
    mt.init();
    res.unit();
    //化成单位矩阵

    while (n)
    {
        if (n & 1)
            res = mul(res, mt);
        mt = mul(mt, mt);
        n = n >> 1;
    }
    return res;
}

int main()
{

    int m, n, c = 1, ans;
    cin >> m;
    Matrix initM;
    initM.m[1][1] = 4;
    initM.m[2][1] = 5;
    initM.m[3][1] = 3;
    initM.m[4][1] = 1;
    while (m--)
    {
        cin >> n;
        if (n == 0)
        {
            ans = 1;
        }
        else
        {
            Matrix p = mul(Pow(n - 1), initM);
            ans = p.m[1][1];
        }
        printf("Case %d: %d\n", c++, ans);
    }
}