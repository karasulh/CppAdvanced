#include <iostream>

using namespace std;

//Template functionlarda auto kullanmak baya yararl� oluyor. Return de�erini "->decltype(value)" �u �ekilde declytpe ile verebiliyoruz.

template<class T,class S>
auto test(T value1,S value2)->decltype(value1+value2){
    return value1+value2;
}


/*
auto test(){ //B�yle yap�nca warning/hata veriyor �rnekte ama burda vermiyor.
    return 100;
}
*/
/*
auto test()->int{ //B�yle yap�nca warning veriyor. B�yle bir kullan�m var yani. return type'�n� bu �ekilde belirtebiliyorsun. Trailing Type diye ge�er.
    return 100;
}
*/

int get(){
    return 999;
}

auto test2()->decltype(get()){
    return get();
}

int main()
{

    auto value=7;
    auto text="Hello";

   // cout << test("Hello there") << endl;
    cout << test(5,6) << endl;
    cout<<test2()<<endl;
    return 0;
}
