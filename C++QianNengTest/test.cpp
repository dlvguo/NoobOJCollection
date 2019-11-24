#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class P
{
private:
    static int a;

public:
    int x = 10;

    P()
    {
        cout << "I am Creating" << endl;
    }
    P(P &p)
    {
        this->x=p.x;
        p.x=666;
        a++;
        cout << "p的拷贝" << endl;
    }
    ~P()
    {
        cout << "I am p end" << endl;
    }
    void Print()
    {
        cout << a << endl;
    }
    void SetP(int x)
    {
        this->x = x;
    }
};
int P::a = 0;
class A
{
private:
    P p;

public:
    A(P p)
    {
        this->p = p;
        p.Print();
    }
    A()
    {
    }
    ~A()
    {
        cout << "I am end" << endl;
    }
};

int main()
{
    //A b;
    P p;
    cout << p.x<<endl;
    p.SetP(20);
    cout<<p.x<<endl;
    P t=p;
    cout<<t.x<<endl;
    cout<<p.x<<endl;
    t.x=10000;
    cout<<t.x<<endl;
    cout<<p.x<<endl;
    /* 输出结果
    I am Creating
    10
    20
    p的拷贝
    20
    666
    10000
    666
    I am p end
    I am p end
    */
}
