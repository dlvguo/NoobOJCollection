#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0)
            return {};
        sort(arr.begin(),arr.end());
        vector<int> a(arr.begin(),arr.begin()+(k-1));
        return a;
    }
};