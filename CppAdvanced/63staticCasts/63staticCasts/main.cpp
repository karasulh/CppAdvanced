#include <iostream>
using namespace std;


class Parent{
public:
    speak(){
    cout<<"parent speak"<<endl;
    }
};

class Brother: public Parent{

};

class Sister: public Parent{

};

//Static Cast ile compile error vermesini engelleyebiliriz, olmayacak þeyleri cast ederek. Fakat bu unsafe anlaþýlacaðý üzere.


int main()
{
    Parent parent;
    Brother brother;

    float value=3.23;
    cout<<int(value)<<endl;
    cout<<(int)value<<endl;
    cout<<static_cast<int>(value)<<endl;

    //Subclass olan ama main class'a baðlý type'ý geri subclass haline cast ile dönüþtürebiliriz:
    Parent* pp=&brother; //Polymorphism, subclass main class pointer'ýna baðlanabilir.
    //Brother* bp=&parent; //Ama tam tersi çalýþmaz.
    Brother* pb= static_cast<Brother*>(&parent); //Bu ise hata vermez.


    Parent &&p= static_cast<Parent&&>(parent); //Bir Lvalue'yu Rvalue yapacaksak Rvalue'ya da cast etmemizi ister mesela.
    p.speak();


    return 0;
}
