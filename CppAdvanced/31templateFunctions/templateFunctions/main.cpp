#include <iostream>

using namespace std;

//template<typename T> //Bu da kullanýlabilir.
template<class T>
void print(T obj){
    cout<<obj<<endl;
}


int main()
{
    print<string>("Hello");
    print<int>(5);

    print("Hello there"); //Type vermeden de çalýþabiliyor.
    print(8);

    return 0;
}
