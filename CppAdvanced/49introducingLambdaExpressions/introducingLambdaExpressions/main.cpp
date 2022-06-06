#include <iostream>

using namespace std;

//Lambda expression used when write an inline function which can be used for short snippets of code that are not going to be reuse and not worth naming
/*
    [ capture clause ] (parameters) -> return-type
    {
       definition of method
    }

*/

void test(void (*pFunc)()){ //return type of pFunc/lambda'n�n void olmal�.
    pFunc();
}

int main()
{
    [](){cout << "Hello world!" << endl;}; //Bu hata vermez ama bir �ey yazd�rmaz! E�er function'�n ismini vermek istemiyorsak bunu [] kullan�yoruz.
    [](){cout << "Hello world!" << endl;}(); //Sonuna () yazarak, bu sanki fonksiyonu �a��rm�� gibi ekrana yazd�r�r.

    //simple Lambda expression:
    auto func = [](){cout << "Hello world!" << endl;}; // return'un sorun olmamas� i�in auto kullanarak bunu bir isme e�itleyebiliyoruz.
    func();

    test(func);
    test([](){cout << "Hello world!" << endl;});


    return 0;
}
