#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxNum = num;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(charArray[i], charArray[j]);
                maxNum = max(maxNum, stoi(charArray));
                swap(charArray[i], charArray[j]);
            }
        }
        return maxNum;
    }
};

