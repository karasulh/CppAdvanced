#include <iostream>

using namespace std;

//template typename durumunda Lvalue veya Rvalue olarak tipi belirsiz olma ihtimalinde fonksiyonun i�eri�ine ba�l� olarak do�ru object haline g�re
//check fonksiyonu �a�r�ld�. Argument && Rvalue olmas�na kar��n, Lvalue olarak al�n�p check Lvalue hali �agrildi.
//Tabi i�eride static_cast yaparak argument olarak verilen object tipine g�re check' fonksiyonunun type t�r� �a�r�labilir.
//"Forward" yaparak da static_cast ile asl�nda ayn� �eyi yapabiliriz.

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
    auto&& t=test; ////auto ile Lvalue'yu Rvalue'ya e�itleyebiliyoruz. Normalde hata veriyordu.

    call(Test()); //cast'li hali RValue �a��rd�, castsiz hali Lvalue �a��rd�.
    call(test); //�ki t�rl� de Lvalue �a��rd�.


    return 0;
}
