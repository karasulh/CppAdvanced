#include <iostream>

using namespace std;

//template<typename T> //Bu da kullanýlabilir.
template<class T>
void print(T obj){
    cout<<"Template Version "<<obj<<endl;
}

void print(int value){
    cout<<"Non-template Version "<<value<<endl;
}

template<class T>
void show(){
    cout<<T()<<endl; // Çaðýrdýðýmýz template type'ýn default unitialized deðerini verir. Double verince 0, string verince null dönüyor.
}                     //Yani T'yi return type olarak kullanabiliyoruz.

int main()
{
    print<string>("Hello");
    print<int>(5);

    print("Hello there"); //Type vermeden de çalýþabiliyor.
    print(8); //Non-Template function kullanýlýr direk type'lar uyuþtuðu için.
    print<>(8); //Bunda ise Template versiyon kullanýlýr. Otomatik olarak kod inference(çýkarým) yapýyor template tipini.

    show<string>(); //type'ý return type olarak kullanabiliriz.
    show<double>();

    return 0;
}
