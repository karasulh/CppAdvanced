#include <iostream>

using namespace std;

//�ok �nemli: Mesela run fonksiyonu gibi herhangi bir yerde abstract function'� implement etmezsek bu sefer compile time error veriyor.
//Yani dog class'�nda mesela run yoksa, dog1'i olu�turmama m�sade etmiyor.


class Animal{
public:
    virtual void run()=0; //Bu =0 standard bir notasyondur ve bu fonksiyonlar abstract olacak, bunlar� i�in bo� bu parent class'ta demektir.
    virtual void speak()=0;
};

class Dog: public Animal{
public:
    virtual void speak(){
        cout<<"Woof!"<<endl;
    }
};

class Labrador:public Dog{
public:
    virtual void run(){ //Burda mesela virtual yazsak da olur yazmasak da.
        cout<<"Labrador running." <<endl;
    }
};

void test(Animal& a){ //Burada Animals yerine derived class'lar�m�z� yazarak polymorphism'den yararlanabiliyoruz.
    a.run();
}

int main()
{

    //Dog dog1; //Bunda hata veriyor, ��nk� run functionun da Dog i�inde implement edilmesini istiyor.
    //dog1.speak();

    Labrador lab1;
    lab1.speak();
    lab1.run();

    //Animal animals[5]; //abstract class oldu�u i�in buna izin vermiyor.
    Animal* animals[5]; //Bunda sorun yok.

    animals[0]=&lab1;
    animals[0]->speak();

    test(lab1);

    return 0;
}
