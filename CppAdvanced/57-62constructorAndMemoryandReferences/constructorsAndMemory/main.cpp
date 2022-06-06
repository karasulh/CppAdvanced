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
        _pBuffer =new int[Size]{}; //Sonuna {} koyarak, memset(_pBuffer,0,sizeof(int)*Size); yazmýþ gibi oluruz.

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
        other._pBuffer=nullptr; //other için destructor çalýþýrken ne olduðu belirsiz pointer'ý silmeye çalýþýrken sorun olmasýn diye yapýyoruz.
    }                           //Ayrýca destructor'da other silinirken bizim eldeki eþitlediðimiz objenin _pBuffer'ý da silinmesin diye pointerý deðiþtiriyoruz.

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

void check(Test&& value){ //&& RValue olduðunu gösterir. , ders60
cout<<"rValue function"<<endl;
}



int main()
{


    //Normalde bu iþlemde bir sürü constructor, copy constructor falan oluþmasý gerekirken sadece constructor oluþuyor,
    //bunu arka planda c++11 saðlýyor. Ýþte buna elision and optimization diyoruz.
    Test test1 = getTest();
    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());



    //58.*********RValues and LValues:
    int value1=7;
    int *pValue1 = &value1;
    //int *pValue2 =&7; //7 sabit bir sayý olduðu için olmaz.

    Test* pTest1=&test1;
    //Test* pTest2=&getTest(); //Return olan obje fonksiyon biterken silineceði için olmaz.

    int* pValue3= &++value1; //Prefixde çalýþýr.
    cout<<*pValue3<<endl; //8

    //int* pValue4 = &value1++; //Fakat bu saçma olacaðý için postfix de olmaz.

    //int* s= &(7+value1); //toplama gibi iþlem olduðu için olmadý gene.
    //int* s= &(value1+value1);



    //59.**********Lvalues reference:
    Test &rTest =test1;

    //Test& rTest2=getTest(); //Fonksiyonun return döndüðü þey daha sonra silindiði için bi adresi olmadýðý için buna compile error verir.
    //Bunu const yaparak aþabiliriz:
    //Prior to C++11, if you had a temporary object, you could use a "regular" or "lvalue reference" to bind it, but only if it was const:
    const Test& rTest2 =getTest();

    Test test2(Test(1)); //copy constructor



    //60.***********Rvalues reference:
    //RValue reference'i tekrardan ihtiyacýmýz olmayacak objelerde kullanýrýz.
    //Daha doðrusu bu durumu koda bildirerek copyconstructor vs uðraþmadan daha optimize bir þekilde hýzlý bir þekilde çalýþabilmesini saðlarýz.
    //Now we have a way to determine if a reference variable refers to a temporary object or to a permanent object.
    //n expression is an rvalue if it results in a temporary object.


    Test& ltest1=test1; //LValue Reference
    Test&& rtest1=getTest(); //RValue Reference

    check(test1); //Lvalue
    check(getTest()); //Rvalue
    check(Test()); //Rvalue



    //61.***********Move Constructor:
    //Temporary variable'lar için oluþturulan bir constructor vardýr, optimizasyon için kullanýlýr.
    //Copy constructor'un sürekli kullanilmasini engeller. Test(Test&& other){ ... }
    //Copy constructor önce objeyi kopyalayip sonra yeni obje oluþtururup eþitlerken,
    //Move constructor oluþturulan geçici objeyi direk olarak kopyalamadan yeni objeye baðlar, geçici objenin de pointerýný null yapar. Böylece vakitten kazanýlýr.
    vector<Test> vec1;
    vec1.push_back(Test()); //Move Constructor


    //62.***********Move Assignment Operators:
    //Bu da optimization için move constructor'in devaminda gerekli!

    Test test3= getTest(); //Bunda niye MoveConstructor çalismadi ????????????????????????????

    Test test4;
    test4=getTest();



    return 0;
}
