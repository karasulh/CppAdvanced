#include <iostream>

using namespace std;

//Lambda expression used when write an inline function which can be used for short snippets of code that are not going to be reuse and not worth naming
/*
    [ capture clause ] (parameters) -> return-type
    {
       definition of method
    }

*/

void test(void (*pFunc)()){ //return type of pFunc/lambda'nýn void olmalý.
    pFunc();
}

int main()
{
    [](){cout << "Hello world!" << endl;}; //Bu hata vermez ama bir þey yazdýrmaz! Eðer function'ýn ismini vermek istemiyorsak bunu [] kullanýyoruz.
    [](){cout << "Hello world!" << endl;}(); //Sonuna () yazarak, bu sanki fonksiyonu çaðýrmýþ gibi ekrana yazdýrýr.

    //simple Lambda expression:
    auto func = [](){cout << "Hello world!" << endl;}; // return'un sorun olmamasý için auto kullanarak bunu bir isme eþitleyebiliyoruz.
    func();

    test(func);
    test([](){cout << "Hello world!" << endl;});


    return 0;
}
