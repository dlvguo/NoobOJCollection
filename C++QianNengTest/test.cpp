#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Complex
{
private:
    int x, y;

public:
    Complex(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    friend Complex &operator++(Complex &c)
    {
        c.x++;
        c.y++;
        return c;
    }
    Complex operator++(int)
    {
        Complex temp = *this;
        ++(*this);
        return temp;
    }
    void Print(){
        cout<<x<<y;
    }
};
int main()
{
    Complex c(10,20);
    ++++++c;
    c.Print();
}
