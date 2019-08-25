#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class A
{
private:
    int a;
    int c = 55;

public:
    A(int a, int c = 789)
    {
        this->a = a;
        this->c = c;
        cout << "A:" << a << endl;
    }

    A(const A &a)
    {
        this->a = a.a;
        cout << "FUCKa" << endl;
    }
    void print()
    {
        cout << "B:" << a << endl;
        cout << "C:" << c << endl;
    }
    ~A(){
        cout<<"FUCk";
    }
    
};

int main()
{
    //A a(6, 1), c = a, b(666,999);
    A b = A(6,1);
    b.print();
}