#include <iostream>
using namespace std;

int tst(int a){
    cout<<a<<endl;
    return 5;
}

//类型 +(* +变量名)(+ 函数需要参数)
void BigTest(int (* test)(int a)){
    int c= test(5);
}

int main()
{   
    //传递进来一样的函数
    BigTest(tst);
}