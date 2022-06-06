#include <iostream>

using namespace std;

//Object Slicing: Aslýnda anlatýlmak istenen, base ve derived class'larýn &(reference) kullanarak objelerinin oluþturulmasý ve & kullanmadan oluþturulmasý
//arasýnda fark var. & kullanýlýnca derived class'ýn özelliði kaybolmuyor. Derived object gibi davranýyor. Tam tersi durumda mesela two private elemaný sanki
//o objede yokmuþ gibi davranýlacaktý.

class Parent{
private:
    int one;
public:
    Parent():one(1){}

    Parent(const Parent& other): one(1){
        one=other.one;
        cout<<"copy parent"<<endl;
    }

    virtual void print(){ //Eðer biz buraya virtual yazmazsak child' için print yazsak da parent'ýn printini yazacaktý.
        cout<<"parent"<<endl;// Böylece Parent deðil cast edilmiþ Child objesi varsa onun functionlarý kullanacak.
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
    Parent& p1=c1; //Böyle yapýnca child'a refer eder printte child yazar.
    p1.print();

    Child c2;
    Parent p2=Child();//Parent p2=c2; //Böyle yaparsak ise parent'a refer eder, printte parent yazar.
    p2.print();         //Ayrýca böyle yazýlýnca Parent'ýn copy constructorunu çaðýrýr.

    return 0;
}
