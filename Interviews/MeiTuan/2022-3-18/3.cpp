#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
#define NMAX = 1000000000 + 5

vector<int> arr1, arr2;

int main()
{
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    arr1.resize(n + 1);
    arr2.resize(n + 1);
    vector<int> m_1(m1);

    for (int i = 0; i < m1; i++)
    {
        scanf("%d", &m_1[i]);
    }
    for (int i = 0; i < m1; i++)
    {
        int r;
        scanf("%d", &r);
        arr1[m_1[i]] += 1;
        arr1[r + 1] -= 1;
    }

    m_1.clear();
    m_1.resize(m2);

    for (int i = 0; i < m2; i++)
    {
        scanf("%d", &m_1[i]);
    }
    for (int i = 0; i < m2; i++)
    {
        int r;
        scanf("%d", &r);
        arr2[m_1[i]] += 1;
        arr2[r + 1] -= 1;
    }

    for (int i = 1; i < arr1.size(); i++)
    {
        arr1[i] += arr1[i - 1];
        arr2[i] += arr2[i - 1];
    }
    int res = 0;
    for (int i = 1; i < arr1.size(); i++)
    {
        if (arr1[i] && arr2[i])
            res++;
    }
    cout << res << endl;
}
