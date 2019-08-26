#include <iostream>
#include <cstring>
using namespace std;

int* CreatyIntArr(int n){
    int *p=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        p[i]=a;
    }
    return p;
}