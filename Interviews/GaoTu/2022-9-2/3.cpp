#include <bits/stdc++.h>
using namespace std;

int main()
{
    string nums1, nums2;
    cin >> nums1 >> nums2;

    if (nums1 == "0" || nums2 == "0")
    {
        cout << "0" << endl;
    }
    else
    {
        vector<int> n1, n2, res;
        if (nums1.size() > nums2.size())
        {
            for (int i = nums1.size() - 1; i >= 0; i--)
                n1.push_back(nums1[i] - '0');
            for (int i = nums2.size() - 1; i >= 0; i--)
                n2.push_back(nums2[i] - '0');
        }
        else
        {
            for (int i = nums1.size() - 1; i >= 0; i--)
                n2.push_back(nums1[i] - '0');
            for (int i = nums2.size() - 1; i >= 0; i--)
                n1.push_back(nums2[i] - '0');
        }

        int carry = 0;

        for (int i = 0; i < n2.size(); i++)
        {
            carry = 0;
            for (int j = 0; j < n1.size(); j++)
            {
                int num = n2[i] * n1[j] + carry;

                if (i + j >= res.size())
                {
                    carry = num / 10;
                    num %= 10;
                    res.push_back(num);
                }
                else
                {
                    num += res[i + j];
                    carry = num / 10;
                    res[i + j] = num % 10;
                }
            }
            if (carry)
                res.push_back(carry);
        }
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i];
        cout << endl;
    }
}