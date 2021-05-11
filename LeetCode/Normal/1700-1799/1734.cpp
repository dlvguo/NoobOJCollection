#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {
        int n = encoded.size();          // 得到编码后的长度
        vector<int> perm(n + 1);         // 定义原本的整数数组perm
        int ABCDE = 0;                   // 初始化，这个变量用于存放perm中所有数值进行异或的结果
        for (int i = 1; i <= n + 1; i++) // perm中所有数值进行异或
            ABCDE ^= i;                  // perm为前n个数的排列过有1-n的值 直接A^B这样
        int BCDE = 0;                    // 为了得到perm的第一个数值，需要初始化一个“BCDE”
        for (int i = 1; i < n; i += 2)   //  “BCDE”的求值，就是encoded中从1开始，步长为2地取值进行异或的结果
            BCDE ^= encoded[i];
        perm[0] = ABCDE ^ BCDE; // 得到第一个数A
        for (int i = 1; i <= n; i++)
            perm[i] = perm[i - 1] ^ encoded[i - 1]; // 此时，本题转换为力扣1720
        return perm;
    }
};