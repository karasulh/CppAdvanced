#include <iostream>
//#include <typeinfo>

using namespace std;

int main()
{
    string value;
    int value2;
    cout<<typeid(value).name()<<endl; //typeid ile type'ýn aslýnda id'sine eriþip name ile onun arka plandaki encode edilmiþ halini görebiliyoruz.
    cout<<typeid(value2).name()<<endl;

    decltype(value) value3="Bob"; //Nesnenin type'ýný elde ediyor. O type'da direk yeni nesne tanýmlanabiliyor. //declare variables existing type
    cout<<value3<<endl;

    return 0;
}
