#include <iostream>
using namespace std;

void process(int a[][4],int n,int m){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<*(*(a+i)+j)<<"/"<<*(*(a+i)+i)<<endl;
            *(*(a+i)+j)/=*(*(a+i)+i);
        }
        /* code */
    }
}

int main(){
    int a[][4]{1,2,3,4,3,4,5,6,5,6,7,8};
    //process(a,3,4);
    freopen("C:/NoobOJCollection/BaiPiShu/C++/P74-21.txt","r",stdin);     
}