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
                        //void return type'� function'un.
    void (*pTest)();    //pointer to a function //Bunu bu �ekilde parantezli olarak yazmam�z laz�m yoksa function pointer void d�n�yor gibi olur.
    pTest = &test; //1.Y�ntem
    (*pTest)();

    /*
    void (*pTest)();
    pTest=test;     //2.Y�ntem //Name of function asl�nda function'�n pointer� say�ld��� i�in b�yle de yapabiliyoruz.
    pTest();
    */

    /*
    void (*pTest)() = test; //3. y�ntem
    pTest();
    */

    test2(7);
    void (*pTest2)(int)=test2; //E�er arg�manl� bir function pointer isteniyorsa
    pTest2(8);



    return 0;
}
