#include <iostream>

using namespace std;

//template<typename T> //Bu da kullan�labilir.
template<class T>
void print(T obj){
    cout<<obj<<endl;
}


int main()
{
    print<string>("Hello");
    print<int>(5);

    print("Hello there"); //Type vermeden de �al��abiliyor.
    print(8);

    return 0;
}
