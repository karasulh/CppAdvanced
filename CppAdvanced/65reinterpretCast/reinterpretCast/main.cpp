#include <iostream>
using namespace std;


class Parent{
public:
    virtual void speak(){ //e�er buna virtual yazmazsak "Parent is not polymorphic" diye compile hatas� verir. A�a�odaki gibi ters bir cast yapmak istersek.
    cout<<"parent speak"<<endl;//Cunku sanki Brother parent'�n speak'ine ula�mas� gerekir gibi d���n�yor.
    }
};

class Brother: public Parent{

};

class Sister: public Parent{

};

//Static Cast unsafe'idi. Reinterpret cast ondan da unsafe, her �eyi cast edebiliyorsun, b�yle bir ihtiya� olursa sa�ma cast'lere kullan�labilir.

int main()
{
    Parent parent;
    Brother brother;
    Sister sitter;


    Parent* ppb=&brother; //Polymorphism, subclass main class pointer'�na ba�lanabilir.
    Sister* pbb= reinterpret_cast<Sister*>(ppb);

    if(pbb==nullptr){
        cout<<"Invalid cast"<<endl;
    }
    else{
        cout<<pbb<<endl;
    }



    return 0;
}
