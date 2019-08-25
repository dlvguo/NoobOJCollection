#include <iostream>
using namespace std;
class C
{
public:
    int v;
    public :
    C(){
        v=0;
    }
    C &addOne(){
        v++;
        return *this;
    }
    C addOne(){
        C temp;
        temp.v=v++;
        return temp;
    }
    void print(){
        cout<<v<<endl;
    }
};

int main()
{
    
}