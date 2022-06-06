#include <iostream>

using namespace std;

//Çok önemli: Mesela run fonksiyonu gibi herhangi bir yerde abstract function'ý implement etmezsek bu sefer compile time error veriyor.
//Yani dog class'ýnda mesela run yoksa, dog1'i oluþturmama müsade etmiyor.


class Animal{
public:
    virtual void run()=0; //Bu =0 standard bir notasyondur ve bu fonksiyonlar abstract olacak, bunlarý için boþ bu parent class'ta demektir.
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

void test(Animal& a){ //Burada Animals yerine derived class'larýmýzý yazarak polymorphism'den yararlanabiliyoruz.
    a.run();
}

int main()
{

    //Dog dog1; //Bunda hata veriyor, çünkü run functionun da Dog içinde implement edilmesini istiyor.
    //dog1.speak();

    Labrador lab1;
    lab1.speak();
    lab1.run();

    //Animal animals[5]; //abstract class olduðu için buna izin vermiyor.
    Animal* animals[5]; //Bunda sorun yok.

    animals[0]=&lab1;
    animals[0]->speak();

    test(lab1);

    return 0;
}
