#include <iostream>

using namespace std;

//Functor fonksiyon gibi davranan bir objedir.
//Functor sanki bir fonksiyon gibi oluyor () operat�r� overload ediliyor.
//Aslinda functor sayesinde ba�ka bir fonksiyona bu functoru argument olarak verebiliyoruz. Sanki fonksiyona fonksiyon argumenti vermi� gibi oluyoruz(function pointer gibi)


struct Test{
   virtual bool operator()(string& text) = 0; //abstract
};

struct MatchTest: public Test{ //Bu bir functor'dur.
   virtual bool operator()(string& text){ //sanki "()" bunu overload ediyoruz gibi d�s�n.
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
