#include <iostream>

using namespace std;

//Object Slicing: Asl�nda anlat�lmak istenen, base ve derived class'lar�n &(reference) kullanarak objelerinin olu�turulmas� ve & kullanmadan olu�turulmas�
//aras�nda fark var. & kullan�l�nca derived class'�n �zelli�i kaybolmuyor. Derived object gibi davran�yor. Tam tersi durumda mesela two private eleman� sanki
//o objede yokmu� gibi davran�lacakt�.

class Parent{
private:
    int one;
public:
    Parent():one(1){}

    Parent(const Parent& other): one(1){
        one=other.one;
        cout<<"copy parent"<<endl;
    }

    virtual void print(){ //E�er biz buraya virtual yazmazsak child' i�in print yazsak da parent'�n printini yazacakt�.
        cout<<"parent"<<endl;// B�ylece Parent de�il cast edilmi� Child objesi varsa onun functionlar� kullanacak.
    }


    virtual ~Parent(){}

};

class Child: public Parent{
private:
    int two;
public:
    Child(): two(2){}

    void print(){
        cout<<"child"<<two<<endl;
    }

};

int main()
{
    Child c1;
    Parent& p1=c1; //B�yle yap�nca child'a refer eder printte child yazar.
    p1.print();

    Child c2;
    Parent p2=Child();//Parent p2=c2; //B�yle yaparsak ise parent'a refer eder, printte parent yazar.
    p2.print();         //Ayr�ca b�yle yaz�l�nca Parent'�n copy constructorunu �a��r�r.

    return 0;
}
