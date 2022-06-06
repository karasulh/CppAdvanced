#include <iostream>

using namespace std;

//Delegate=temsilci
//Default implicit constructor:
//Cpp11 constructor delegation ile bir classýn içindeki constructorla diðer constructorunu çaðýrabiliyor olacaðýz.

class Parent{
    int dogs{5};
    string text{"Hello"};
public:
    Parent():Parent("Hello"){ //Parametresiz constructor çaðrýlýnca, önce Parent(string text)'i çalýþtýrýlýr sonra Parent() çalýþtýrýlýr.
        cout<<"No parameter parent constructor"<<endl;
    }
    Parent(string text){
        cout<<"String parent constructor"<<endl;
    }
};

class Child: public Parent{
public:
    Child() = default;
    //veya Child(){}
};


int main()
{
    Parent parent("Hello");
    Child child; //Child için 2 constructor çaðrýldý böylece birisi parametreli diðeri parametresiz olan.

    return 0;
}
