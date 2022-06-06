#include <iostream>
using namespace std;


class Parent{
public:
    virtual void speak(){ //eðer buna virtual yazmazsak "Parent is not polymorphic" diye compile hatasý verir. Aþaðodaki gibi ters bir cast yapmak istersek.
    cout<<"parent speak"<<endl;//Cunku sanki Brother parent'ýn speak'ine ulaþmasý gerekir gibi düþünüyor.
    }
};

class Brother: public Parent{

};

class Sister: public Parent{

};

//Static Cast unsafe'idi. Reinterpret cast ondan da unsafe, her þeyi cast edebiliyorsun, böyle bir ihtiyaç olursa saçma cast'lere kullanýlabilir.

int main()
{
    Parent parent;
    Brother brother;
    Sister sitter;


    Parent* ppb=&brother; //Polymorphism, subclass main class pointer'ýna baðlanabilir.
    Sister* pbb= reinterpret_cast<Sister*>(ppb);

    if(pbb==nullptr){
        cout<<"Invalid cast"<<endl;
    }
    else{
        cout<<pbb<<endl;
    }



    return 0;
}
