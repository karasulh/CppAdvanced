#include <iostream>

using namespace std;

void test(){
    cout<<"Hello"<<endl;
}

void test2(int a){
    cout<<"Hello"<<a<<endl;
}


int main()
{
    test();
                        //void return type'ý function'un.
    void (*pTest)();    //pointer to a function //Bunu bu þekilde parantezli olarak yazmamýz lazým yoksa function pointer void dönüyor gibi olur.
    pTest = &test; //1.Yöntem
    (*pTest)();

    /*
    void (*pTest)();
    pTest=test;     //2.Yöntem //Name of function aslýnda function'ýn pointerý sayýldýðý için böyle de yapabiliyoruz.
    pTest();
    */

    /*
    void (*pTest)() = test; //3. yöntem
    pTest();
    */

    test2(7);
    void (*pTest2)(int)=test2; //Eðer argümanlý bir function pointer isteniyorsa
    pTest2(8);



    return 0;
}
