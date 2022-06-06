#include <iostream>
#include "ring.h"

using namespace std;

int main()
{

    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    //C++ 98 style
    for(ring<string>::iterator it=textring.begin();it!=textring.end();it++){
        cout<<*it<<endl;
    }

    cout<<endl;


    for(string value: textring){ //Auto yerine böyle yazarsak warning veriyor sadece.
        cout<<value<<endl;
    }

    cout<<endl;
    //C++ 11 style
    for(auto value: textring){
        cout<<value<<endl;
    }

    return 0;
}
