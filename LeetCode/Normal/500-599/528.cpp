#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> w;
public:
    Solution(vector<int>& W) {
        partial_sum(W.begin(), W.end(), back_inserter(w));
        //等同于 w.push_back(W[0]); for(int i = 1; i < W.size(); ++i) w.push_back(w.back() + W[i]);
    }
    
    int pickIndex() {
        int weight = rand() % w.back();
        return upper_bound(w.begin(), w.end(), weight) - w.begin();
    }
};
