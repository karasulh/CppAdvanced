#include <iostream>
//#include <typeinfo>

using namespace std;

int main()
{
    string value;
    int value2;
    cout<<typeid(value).name()<<endl; //typeid ile type'�n asl�nda id'sine eri�ip name ile onun arka plandaki encode edilmi� halini g�rebiliyoruz.
    cout<<typeid(value2).name()<<endl;

    decltype(value) value3="Bob"; //Nesnenin type'�n� elde ediyor. O type'da direk yeni nesne tan�mlanabiliyor. //declare variables existing type
    cout<<value3<<endl;

    return 0;
}
