#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;


//count_if: Ba�� ve sonu verilen listedeki elemanlar� verilen fonksiyonun boolean sonucuna g�re uyanlar� sayar.
//count_if'e fonksiyon argument olarak verebildi�imiz gibi lambda ve functor'u da argument olarak verebiliriz.
//Burada ayr�ca Standart function olu�turmay� ve lambda ile e�itlenerek de olu�turulabilece�ini de g�rm�� olduk.

bool check(string& test){
    return test.size()==3;
}

class Check{
public:
    bool operator()(string& test){
        return test.size()==5;
    }
} check1; //check1 objesi //functor

//Standard Function� argument olarak vermek:
//Function'� argument olarak tan�mlamak i�in:
//Functional k�t�phanesinden gelen function kullan�lacak. Return type of function bool olacak. Parantez i�inde de parametreler olacak.
//Function ismine de check diyece�iz.
void run(function<bool(string&)> check){
    string test="stars";
    cout<<check(test)<<endl;
}

int main()
{
    int size=5;

    vector<string> vec{"one","two","three"};

    int count=count_if(vec.begin(),vec.end(),[size](string test){return test.size()==size;}); //lambda functionu verdik parametre olarak count if'e.
    cout<<count<<endl;
     //�sttekini b�yle ayr� ayr� yazabiliriz.
    auto lambda = [size](string test){return test.size()==size;};
    count=count_if(vec.begin(),vec.end(),lambda);
    cout<<count<<endl;

    count=count_if(vec.begin(),vec.end(),check);
    cout<<count<<endl;

    count=count_if(vec.begin(),vec.end(),check1);
    cout<<count<<endl;

    run(lambda);
    run(check1); //functorla kullan�m�.
    run(check);

    //Standard function:
    function<int(int,int)> add =[](int one, int two){return one+two;};
    cout<< add(7,3)<<endl;

    return 0;
}
