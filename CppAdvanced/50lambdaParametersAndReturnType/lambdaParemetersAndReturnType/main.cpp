#include <iostream>

using namespace std;


/*
    [ capture clause ] (parameters) -> return-type
    {
       definition of method
    }

*/

void testGreet(void (*greet)(string)){ //herhangi bir isim versek oldu argüman için. // void (*...) (function pointer) bu önemli!
    greet("Bob");
}

void runDivide(double (*divide)(double a,double b)){
    auto rval= divide(9,3);
    cout<<rval<<endl;
}

int main()
{
    auto pGreet= [](string name){cout << "Hello " << name << endl;};
    pGreet("Mike");

    testGreet(pGreet);

    auto pDivide= [](double a, double b)->double{ //Return type'i c++'da belirtmemiz gerekiyor ->double diyerek belirttik.
        if(b==0.0){
            return 0;
        }
        return a/b;
    };

    cout<<pDivide(10.0,5.0)<<endl;
    runDivide(pDivide);

    return 0;
}
