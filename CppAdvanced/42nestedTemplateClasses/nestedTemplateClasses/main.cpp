#include <iostream>
#include "ring.h"

using namespace std;

int main()
{

    ring<int>::iterator it;
    it.print();

    //Bu alttaki hep standard olarak uygulayabildigimiz kodu nested class'lar ile uygulamaya çalisiyoruz, iterator kullanim mantigiyla.
    /*
    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    for(int i=0;i<textring.size();i++){
        cout<<textring.get(i)<<endl;
    }



    return 0;
}
