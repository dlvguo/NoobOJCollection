#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        x = 100;
    }

    A(const A &X){
        cout<<"FUCK"<<endl;
    }
    int x;
    ~A(){
        cout<<"I am end"<<endl;
    }
};

int main()
{
    int x=1;
    cout<<(x=2);
}
