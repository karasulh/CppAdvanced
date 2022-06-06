#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Test{
private:
    static const int Size=100;
    int *_pBuffer{nullptr};

public:
    Test(){
        cout<<"constructor"<<endl;
        _pBuffer =new int[Size]{}; //Sonuna {} koyarak, memset(_pBuffer,0,sizeof(int)*Size); yazm�� gibi oluruz.

    }
    Test(int i){
        cout<<"parametrized constructor"<<endl;
        _pBuffer =new int[Size]{};

        for(int i=0;i<Size;i++){
            _pBuffer[i]=7*i;
        }
    }
    Test(Test&& other){ //constructor for temporary variable, ders61
        cout<<"Move Constructor"<<endl;
        _pBuffer= other._pBuffer;
        other._pBuffer=nullptr; //other i�in destructor �al���rken ne oldu�u belirsiz pointer'� silmeye �al���rken sorun olmas�n diye yap�yoruz.
    }                           //Ayr�ca destructor'da other silinirken bizim eldeki e�itledi�imiz objenin _pBuffer'� da silinmesin diye pointer� de�i�tiriyoruz.

    Test(const Test& other){
        cout<<"copy constructor"<<endl;
        _pBuffer =new int[Size]{};

        memcpy(_pBuffer,other._pBuffer,Size*sizeof(int)); //Bununla direk arrayleri kopyalayabiliriz.

    }
    Test& operator=(const Test& other){
        cout<<"assignment"<<endl;
        _pBuffer =new int[Size]{};

        memcpy(_pBuffer,other._pBuffer,Size*sizeof(int));
        return *this;
    }
    Test& operator=(Test&& other){//Move assignment operator, ders62
        cout<<"Move Assingment Operator"<<endl;
        delete[] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer=nullptr;

        return *this;
    }
    ~Test(){
       // cout<<"destructor"<<endl;
        delete[] _pBuffer;
    }
    friend ostream& operator<<(ostream& out,const Test& test);

};

ostream& operator<<(ostream& out,const Test& test){
    out<<"Hello from test";
    return out;
}

Test getTest(){
    return Test();
}

void check(const Test& value){ //ders60
cout<<"lValue function"<<endl;
}

void check(Test&& value){ //&& RValue oldu�unu g�sterir. , ders60
cout<<"rValue function"<<endl;
}



int main()
{


    //Normalde bu i�lemde bir s�r� constructor, copy constructor falan olu�mas� gerekirken sadece constructor olu�uyor,
    //bunu arka planda c++11 sa�l�yor. ��te buna elision and optimization diyoruz.
    Test test1 = getTest();
    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());



    //58.*********RValues and LValues:
    int value1=7;
    int *pValue1 = &value1;
    //int *pValue2 =&7; //7 sabit bir say� oldu�u i�in olmaz.

    Test* pTest1=&test1;
    //Test* pTest2=&getTest(); //Return olan obje fonksiyon biterken silinece�i i�in olmaz.

    int* pValue3= &++value1; //Prefixde �al���r.
    cout<<*pValue3<<endl; //8

    //int* pValue4 = &value1++; //Fakat bu sa�ma olaca�� i�in postfix de olmaz.

    //int* s= &(7+value1); //toplama gibi i�lem oldu�u i�in olmad� gene.
    //int* s= &(value1+value1);



    //59.**********Lvalues reference:
    Test &rTest =test1;

    //Test& rTest2=getTest(); //Fonksiyonun return d�nd��� �ey daha sonra silindi�i i�in bi adresi olmad��� i�in buna compile error verir.
    //Bunu const yaparak a�abiliriz:
    //Prior to C++11, if you had a temporary object, you could use a "regular" or "lvalue reference" to bind it, but only if it was const:
    const Test& rTest2 =getTest();

    Test test2(Test(1)); //copy constructor



    //60.***********Rvalues reference:
    //RValue reference'i tekrardan ihtiyac�m�z olmayacak objelerde kullan�r�z.
    //Daha do�rusu bu durumu koda bildirerek copyconstructor vs u�ra�madan daha optimize bir �ekilde h�zl� bir �ekilde �al��abilmesini sa�lar�z.
    //Now we have a way to determine if a reference variable refers to a temporary object or to a permanent object.
    //n expression is an rvalue if it results in a temporary object.


    Test& ltest1=test1; //LValue Reference
    Test&& rtest1=getTest(); //RValue Reference

    check(test1); //Lvalue
    check(getTest()); //Rvalue
    check(Test()); //Rvalue



    //61.***********Move Constructor:
    //Temporary variable'lar i�in olu�turulan bir constructor vard�r, optimizasyon i�in kullan�l�r.
    //Copy constructor'un s�rekli kullanilmasini engeller. Test(Test&& other){ ... }
    //Copy constructor �nce objeyi kopyalayip sonra yeni obje olu�tururup e�itlerken,
    //Move constructor olu�turulan ge�ici objeyi direk olarak kopyalamadan yeni objeye ba�lar, ge�ici objenin de pointer�n� null yapar. B�ylece vakitten kazan�l�r.
    vector<Test> vec1;
    vec1.push_back(Test()); //Move Constructor


    //62.***********Move Assignment Operators:
    //Bu da optimization i�in move constructor'in devaminda gerekli!

    Test test3= getTest(); //Bunda niye MoveConstructor �alismadi ????????????????????????????

    Test test4;
    test4=getTest();



    return 0;
}
