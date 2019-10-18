#include <iostream>
using namespace std;

bool SelectSort(int a[],int len){
    for(int i=1;i<=n/2;i++){
        int n=i*2;
        if(a[i]>a[n])
            return false;
        if(n+1<=len)
            if(a[i]>a[n+1])
                return false;
    }
    return true;
}