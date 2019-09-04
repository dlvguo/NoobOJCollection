#include <iostream>
using namespace std;
#define PI 5.5
#define S(X) PI *X *X
class C
{
public:
    int v;

public:
    C()
    {
        v = 0;
    }
    C &addOne()
    {
        v++;
        return *this;
    }
    void print()
    {
        cout << v << endl;
    }
};
typedef struct test
{
    //int num;
    //char name[20];
    //char sex;
    //int age;
    char s[5];
    char l;
    float score;
    char sex;
    double b;
    //char addr[30];

    /* data */
} test2, test3;

int main()
{
   
    cout << sizeof(test) << endl;
}