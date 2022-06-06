#include <iostream>

using namespace std;

//Template functionlarda auto kullanmak baya yararlý oluyor. Return deðerini "->decltype(value)" þu þekilde declytpe ile verebiliyoruz.

template<class T,class S>
auto test(T value1,S value2)->decltype(value1+value2){
    return value1+value2;
}


/*
auto test(){ //Böyle yapýnca warning/hata veriyor örnekte ama burda vermiyor.
    return 100;
}
*/
/*
auto test()->int{ //Böyle yapýnca warning veriyor. Böyle bir kullaným var yani. return type'ýný bu þekilde belirtebiliyorsun. Trailing Type diye geçer.
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
