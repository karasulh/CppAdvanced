#include <iostream>

using namespace std;

//Delegate=temsilci
//Default implicit constructor:
//Cpp11 constructor delegation ile bir class�n i�indeki constructorla di�er constructorunu �a��rabiliyor olaca��z.

class Parent{
    int dogs{5};
    string text{"Hello"};
public:
    Parent():Parent("Hello"){ //Parametresiz constructor �a�r�l�nca, �nce Parent(string text)'i �al��t�r�l�r sonra Parent() �al��t�r�l�r.
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
    Child child; //Child i�in 2 constructor �a�r�ld� b�ylece birisi parametreli di�eri parametresiz olan.

    return 0;
}
