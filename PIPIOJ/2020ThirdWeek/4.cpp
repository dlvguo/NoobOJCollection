#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#include<hash_set>
using namespace __gnu_cxx;
using namespace std;

//0-15 故用位运算来做 一个int 够了
void Set(int &num, int n)
{
    num = num | (1 << n);
}

struct N
{
    int k[15]={0};
};


bool bitTst(int &mask, int n)
{
    if ((mask & (1 << n)) >> n)
    {
        return true;
    }
    return false;
}

bool bitClr(int &mask, int n)
{
    mask = mask & (~(1 << n));
    return true;
}

bool bitRev(int &mask, int n)
{
    if (bitTst(mask, n))
    {
        bitClr(mask, n);
    }
    else
    {
        Set(mask, n);
    }

    return true;
}

int minFlips(vector<vector<int>> &mat)
{
    int n, m, num;
    cin >> n >> m;
    queue<vector<int>> statusQ;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; i < m; j++)
        {
            cin >> num;
            if (num)
            {
                //m-i位设置
                Set(t, m - j);
            }
        }
        v.push_back(t);
    }

    int d[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
}
int main()
{      
    N n;
    hash_set<N> v;
    v.insert(n);
}