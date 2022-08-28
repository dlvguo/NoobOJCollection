#include <bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int M)
{

    unordered_map<int, int> umap;

    int res = 0;

    for (int i = 0; i < A.size(); i++)
    {

        int temp = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (j != i)
            {
                if (abs(A[i] - A[j]) % M == 0)
                    temp++;
            }
        }

        if (temp == 0)
        {
            if (A[i] && A[i] % M == 0)
                temp++;
        }
        else
        {
            temp++;
        }

        res = max(res, temp);
    }

    return res;
}

int main()
{
    vector<int> A = {-3, -2, 1, 0, 8, 7, 1};
    cout << solution(A, 3) << endl;
}