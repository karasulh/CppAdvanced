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

//Static Cast unsafe'idi. Doðru casting olma garantisi için dynamic Cast kullaniliyor.
//Mesela subclass objesi main class pointerýyla tutulabilir ama tam tersi mümkün deðil, dynamic cast ile bu durum check edilir.
//Cast'in doðruluðuna run-time'da bakýyor, mantýksýzsa null dönüyor.


int main()
{
    Parent parent;
    Brother brother;


    Parent* ppb=&parent;
    Brother* pbb= dynamic_cast<Brother*>(ppb);

    if(pbb==nullptr){
        cout<<"Invalid cast"<<endl;
    }
    else{
        cout<<pbb<<endl;
    }



    return 0;
}
