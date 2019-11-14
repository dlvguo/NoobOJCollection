#include<iostream>
using namespace std;

int a[];

int Max(int n){
    if(n==1)
        return a[1];
    int k=Max(n-1);
    return a[n]>k?a[n]:k;
}