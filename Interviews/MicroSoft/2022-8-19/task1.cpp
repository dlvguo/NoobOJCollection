#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &X, vector<int> &Y, int W)
{
    sort(X.begin(), X.end());
    int ans = 1, start = X[0];
    for (int i = 0; i < X.size(); i++)
    {
        if (start + W < X[i])
        {
            ans++;
            start = X[i];
        }
    }

    return ans;
    // write your code in C++ (C++14 (g++ 6.2.0))
}

int main()
{
    vector<int> X={0,2,3,1000000001};
    vector<int> Y={};
    int W=1000000000;
    cout<<solution(X,Y,W);
}
