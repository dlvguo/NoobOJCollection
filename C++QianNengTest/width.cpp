#include <iostream>
#include <cstring>
using namespace std;

class Car
{
    public:
    static int i;
    static void Add(){
        i++;
        cout<<i<<endl;
    }
    void Fuck(){
        cout<<"I am a test"<<endl;
        Add();
    }
};
int Car::i = 2;


int main()
{
    Car c;
    c.Add();
    c.Fuck();
    cout<<Car::i<<endl;
    
}