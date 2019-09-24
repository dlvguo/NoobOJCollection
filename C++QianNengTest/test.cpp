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

int main()
{
    int maxsize = 15;
    A b(11);
    (b+10).print();
    b.print();
}