#include <iostream>
#include <cstring>
using namespace std;

class B
{
public:
   B(){}
   virtual void show()
   {
      cout << "B" << endl;
   }

   B(const B &b)
   {
      cout << "I am Fuck ";
   }
};

void func3(B *b)
{
   b->show();
}

int main()
{int a=5;	
   cout<<(a=10);
}
