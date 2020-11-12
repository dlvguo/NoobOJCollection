#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int left = 0;
        int firstOdd = 0, firstEven = 0;
        while (left < A.size())
        {
            while (left < A.size() && left % 2 == A[left] % 2)
            {
                left++;
            }
            if (left % 2)
            {
                if (!firstOdd)
                {
                    firstOdd = left + 1;
                    //找偶数为奇数
                    if (firstOdd % 2)
                        firstOdd += 1;
                }

                while (firstOdd < A.size() && firstOdd % 2 == A[firstOdd] % 2)
                {
                    firstOdd += 2;
                }
                swap(A[left], A[firstOdd]);
                firstOdd += 2;
            }
            else
            {
                if (!firstEven)
                {
                    firstEven = left + 1;
                    //找奇数
                    if (!firstEven % 2)
                        firstEven += 1;
                }

                while (firstEven < A.size() && firstEven % 2 == A[firstEven] % 2)
                {
                    firstEven += 2;
                }
                swap(A[left], A[firstEven]);
                firstEven += 2;
            }
            left++;
        }
        return A;
    }
};

int main()
{
    vector<int> vts = {4,2,5,7};
    Solution s;
    s.sortArrayByParityII(vts);
}