#include <iostream>

using namespace std;

//Functor fonksiyon gibi davranan bir objedir.
//Functor sanki bir fonksiyon gibi oluyor () operatörü overload ediliyor.
//Aslinda functor sayesinde baþka bir fonksiyona bu functoru argument olarak verebiliyoruz. Sanki fonksiyona fonksiyon argumenti vermiþ gibi oluyoruz(function pointer gibi)


struct Test{
   virtual bool operator()(string& text) = 0; //abstract
};

struct MatchTest: public Test{ //Bu bir functor'dur.
   virtual bool operator()(string& text){ //sanki "()" bunu overload ediyoruz gibi düsün.
        return text=="lion";
    }
};

void check(string text,Test& test){
    if(test(text)){
        cout<<"Text matches!"<<endl;
    }
    else{
        cout<<"No match"<<endl;
    }
}

int main()
{
    MatchTest pred;
    string value="lion";
    cout<<pred(value)<<endl;

    MatchTest m;
    check(value,m);
    check("lioned",m);



    return 0;
}
