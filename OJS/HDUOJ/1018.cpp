#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
int a[500000];

void reset(int m){
    for(int i=0;i<=m;i++)
        a[i]=0;
}

void countn(int num,ll t){
    int k=0;
    a[0]=1;
    for(ll i=2;i<=t;i++)
        for(int j=0;j<num;j++){
            a[j]*=i;
            a[j]+=k;
            k=a[j]/10;
            a[j]%=10;
        }
    for(int i=num-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;

}

int main(){
    ll t,num=1;
    double m;
    while(cin>>t){
        m=0;
        for(int i=2;i<=t;i++)
            m+=log10(i);
        num=(int)m+1;
        reset(num);
        countn(num,t);
    }


}

