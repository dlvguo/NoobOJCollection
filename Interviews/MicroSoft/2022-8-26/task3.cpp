#include <bits/stdc++.h>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/**
 * 题目：
 * 有两个数组 A 和 B，每个数组由 N 个整数组成。 我们想将它们合并到数组 C 中。对于每个索引 K（从 0 到 N - 1），C[K] 可以是 A[K] 或 B[K]。 例如，数组 A = [1, 2, 4, 3] 和 B = [1, 3, 2, 3]
我们的目标是获得一个数组 C，使得 C 中不存在的最小正整数尽可能小。 在上面的例子中，我们可以创建 C = [1, 3, 4, 3] 并且结果是 2，因为从 C 中排除的最小正整数是 2。
 **/

// 思路：用表存1-（N+1） 然后从小到大遍历不存在的
int solution(vector<int> &A, vector<int> &B)
{
    int res = 1;
    vector<int> temp(1e5 + 2, 0);
    for (int i = 0; i < A.size(); i++)
    {
        temp[max(A[i], B[i])]++;
    }
    for (int i = 1; i <= 1e5 + 1; i++)
        if (!temp[i])
        {
            res = i;
            break;
        }
    return res;
}
