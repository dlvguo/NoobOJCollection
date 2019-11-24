#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class A
{

public:
    A() {
        cout<<"A";
    }
    virtual ~A()
    {
        cout <<"~A";
    }
};
class B:public A
{
private:
    /* data */
public:
    B(){
        cout<<"B";
    }
    virtual ~B(){
        cout<<" ~B";
    }
};

class C:public A,public B{
    public :
    C(){
        cout<<"C";    
    }
    virtual ~C(){
        cout<<"~C";
    }
};


int main()
{
    C c;
    cout<<endl;
}