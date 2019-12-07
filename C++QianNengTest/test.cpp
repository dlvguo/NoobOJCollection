#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Material{
    public:
    int m=10;
    Material(int b){
        m=b;
        cout<<m<<"I am Creating"<<endl;
    }
    
    ~Material(){
        cout<<m<< "I am FUCK U"<<m<<endl;
    }
};

Material  K(){
    Material a(777);
    Material m(555);
    return m;
}
int main()
{
    Material(5);//产生一个匿名对象并有一个析构
    Material a(11);
    a=K();//初始后再接是有3个
    Material b(666666);
}
