#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;

int main()
{

    Complex c1(2,3);
    cout<<*c1<<endl; //(2,-3) verecek karma��k say�lardaki e�leni�i d���n.
    cout<<*c1 + *Complex(5,1)<<endl;

    return 0;
}
