#include <iostream>
#include "../../Headers/set.h"
using namespace std;

int main()
{
    Set s = InitSet(100);
    SetInsert(10,s);
    SetInsert(16,s);
    cout<<SetMember(9,s);
    return 0;
}
