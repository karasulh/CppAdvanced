#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;

int main()
{

    Complex c1(2,3);
    Complex c2(c1);
    Complex c3=c2;
    Complex c4;
    c4=c3;

    cout<<c4<<": "<< c3<<endl;

    return 0;
}
