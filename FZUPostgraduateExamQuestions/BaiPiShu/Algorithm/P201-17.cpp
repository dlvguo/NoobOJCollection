#include<iostream>
using namespace std;
//寻找逆序数 从n往1前面做最长递增序列 数量inc[]表示从n-1中最长的递增序列 若a[i]>inc[len]说明此时a[i]=len
//若a[i]<inc[len]那么就在inc中找到一个离a[i]最进比a[i]小的值 这个值的在inc中的下标就是inc的逆序数 之后把这个值后面替换成a[i]
//用折半查找能保证总复杂度为nlog(n)

int Search(int a[], int alen,int v){//找到跟v差最小的且比v小的值 
    int low=1,high=alen;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<=v)
            low=mid+1;
        else
        {
            high=mid-1;
        }    
    }
    //low就是比v大的第一个数 把这个替换成v low-1就是下标
    a[low]=v;
    return low-1;
}

int main(){
    //因为是从n往前计算逆序数 用个数组存放 最后输出
    int arr[7],inc[7],inclen=1;
    int a[]={0,3,11,8,12,24,6};
    inc[1]=6;
    arr[6]=0;
    for (int n = 5; n>=1 ; n--)
    {
        if(a[n]>inc[inclen]){
            arr[n]=inclen;
            inclen++;
            inc[inclen]=a[n];
        }
        else{
            int len=Search(inc,inclen,a[n]);
            arr[n]=len;
            cout<<n<<len<<endl;
        }
    }
    for (int i = 1; i <=6; i++)
    {
        cout<<arr[i];
    }
    
}