#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;


//count_if: Baþý ve sonu verilen listedeki elemanlarý verilen fonksiyonun boolean sonucuna göre uyanlarý sayar.
//count_if'e fonksiyon argument olarak verebildiðimiz gibi lambda ve functor'u da argument olarak verebiliriz.
//Burada ayrýca Standart function oluþturmayý ve lambda ile eþitlenerek de oluþturulabileceðini de görmüþ olduk.

bool check(string& test){
    return test.size()==3;
}

class Check{
public:
    bool operator()(string& test){
        return test.size()==5;
    }
} check1; //check1 objesi //functor

//Standard Functioný argument olarak vermek:
//Function'ý argument olarak tanýmlamak için:
//Functional kütüphanesinden gelen function kullanýlacak. Return type of function bool olacak. Parantez içinde de parametreler olacak.
//Function ismine de check diyeceðiz.
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
     //Üsttekini böyle ayrý ayrý yazabiliriz.
    auto lambda = [size](string test){return test.size()==size;};
    count=count_if(vec.begin(),vec.end(),lambda);
    cout<<count<<endl;

    count=count_if(vec.begin(),vec.end(),check);
    cout<<count<<endl;

    count=count_if(vec.begin(),vec.end(),check1);
    cout<<count<<endl;

    run(lambda);
    run(check1); //functorla kullanýmý.
    run(check);

    //Standard function:
    function<int(int,int)> add =[](int one, int two){return one+two;};
    cout<< add(7,3)<<endl;

    return 0;
}
