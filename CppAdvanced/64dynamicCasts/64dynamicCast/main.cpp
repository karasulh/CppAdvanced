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

//Static Cast unsafe'idi. Do�ru casting olma garantisi i�in dynamic Cast kullaniliyor.
//Mesela subclass objesi main class pointer�yla tutulabilir ama tam tersi m�mk�n de�il, dynamic cast ile bu durum check edilir.
//Cast'in do�rulu�una run-time'da bak�yor, mant�ks�zsa null d�n�yor.


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
