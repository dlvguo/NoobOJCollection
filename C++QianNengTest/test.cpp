#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class A
{
private:
    int a;

public:
    A()
    {
        a = 10;
    }
    A(int a)
    {
        this->a = a;
    }
    A &operator+(int b)
    {
        this->a += b;
        return (*this);
    }
    void print(){
        cout<<a<<endl;
    }
};

void test(int i,int k=0,int c=1){
    cout<<i<<k<<c<<endl;
}
int main()
{
    int maxsize = 15;
    test(maxsize++,++maxsize,++maxsize);
}