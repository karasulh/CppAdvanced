#include <iostream>

using namespace std;

//template typename durumunda Lvalue veya Rvalue olarak tipi belirsiz olma ihtimalinde fonksiyonun içeriðine baðlý olarak doðru object haline göre
//check fonksiyonu çaðrýldý. Argument && Rvalue olmasýna karþýn, Lvalue olarak alýnýp check Lvalue hali çagrildi.
//Tabi içeride static_cast yaparak argument olarak verilen object tipine göre check' fonksiyonunun type türü çaðrýlabilir.
//"Forward" yaparak da static_cast ile aslýnda ayný þeyi yapabiliriz.

class Test{

};

/*
template<typename T>
void call(T&& arg){
    check(arg);
}
*/

/*
template<typename T>
void call(T&& arg){
    check(static_cast<T>(arg));
}
*/

template<typename T>
void call(T&& arg){
    check(forward<T>(arg));
}


void check(Test& test){
    cout<<"Lvalue"<<endl;
}

void check(Test&& test){
    cout<<"Rvalue"<<endl;
}

int main()
{
    Test test;
    auto&& t=test; ////auto ile Lvalue'yu Rvalue'ya eþitleyebiliyoruz. Normalde hata veriyordu.

    call(Test()); //cast'li hali RValue çaðýrdý, castsiz hali Lvalue çaðýrdý.
    call(test); //Ýki türlü de Lvalue çaðýrdý.


    return 0;
}
