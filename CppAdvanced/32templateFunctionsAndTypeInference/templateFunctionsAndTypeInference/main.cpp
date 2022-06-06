#include <iostream>

using namespace std;

//template<typename T> //Bu da kullan�labilir.
template<class T>
void print(T obj){
    cout<<"Template Version "<<obj<<endl;
}

void print(int value){
    cout<<"Non-template Version "<<value<<endl;
}

template<class T>
void show(){
    cout<<T()<<endl; // �a��rd���m�z template type'�n default unitialized de�erini verir. Double verince 0, string verince null d�n�yor.
}                     //Yani T'yi return type olarak kullanabiliyoruz.

int main()
{
    print<string>("Hello");
    print<int>(5);

    print("Hello there"); //Type vermeden de �al��abiliyor.
    print(8); //Non-Template function kullan�l�r direk type'lar uyu�tu�u i�in.
    print<>(8); //Bunda ise Template versiyon kullan�l�r. Otomatik olarak kod inference(��kar�m) yap�yor template tipini.

    show<string>(); //type'� return type olarak kullanabiliriz.
    show<double>();

    return 0;
}
