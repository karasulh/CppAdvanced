#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test{
public:
    int add(int a,int b,int c){
    cout<<a<<","<<b<<","<<c<<endl;
    return a+b+c;
}

};


int add(int a,int b,int c){
    cout<<a<<","<<b<<","<<c<<endl;
    return a+b+c;
}

int run(function<int(int,int)> func){
    func(7,3);
}

int main()
{
    //cout << add(1,2,3) << endl;

    auto calculate = bind(add, 1,2,3); //Bind fonksiyon ve argümanlarý böyle birleþtirir.
    cout<<calculate()<<endl;

    //Stakeholders sayesinde oraya _1 gibi yaparak, argümanlarý daha sonra verebiliriz.
    //_1 1.sýradaa 1. argüman verilecek, _3 2.sýrada 3.argüman verilecek demektir.
    auto calculate2 =bind(add, _1, _3, _2);
    cout<<calculate2(10,20,30)<<endl;

    //Eðer argümanýn birisi hep sabit olacaksa:
    auto calculate3= bind(add, _1, 100, _2);
    cout<<calculate3(10,30)<<endl;


    cout<<run(calculate3)<<endl;

    Test test;

    //Eðer bir class'ýn methodu kullanýlacaksa, bind baðlamak için için bir de o class'ýn objesini istiyor.
    auto calculate4 = bind(&Test::add, test, _2,100,_1);
    cout<<run(calculate4)<<endl;

    return 0;
}
