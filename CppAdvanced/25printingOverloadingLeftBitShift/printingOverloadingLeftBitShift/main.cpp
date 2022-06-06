#include <iostream>

using namespace std;

class Test {
private:
    int id;
    string name;

public:
    Test():id(0),name(""){}
    Test(int id,string name): id(id), name(name){}

    void print(){
        cout<<"id: "<< id <<" name: "<<name << endl;
    }

    const Test& operator=(const Test& other) { //Return type'a dikkat!
        cout<<"Assignment running"<<endl;
        id=other.id;
        name=other.name;

        return *this; //Bunu unutma return type'� Test o y�zden b�yle d�nd�k.
    }

    Test(const Test& other){
        cout<<"Copy Constructor running"<<endl;
        *this=other; //Bunu yazarsak assignment operator de �al���r.
        //id=other.id;
        //name=other.name;
    }

    // "<<" bunun solundaki first argument oluyor,sa��ndaki second argument. Yani cout<<test1 derken out=cout, test=test1 oluyor.
    friend ostream &operator<<(ostream &out, const Test &test){//Burdaki friend'i bunu d��ar� yazabiliriz diye ekledik.
        out<< test.id << ": " << test.name;
        return out;
    }

};

int main()
{
    Test test1(10,"Mike");
    Test test2(5,"Bob");
    cout << test1 << endl; // Normalde b�yle yaz�nca sa�ma olaca��ndan hata al�r�z, bunu �nlemek i�in << operator'�n� overload ediyoruz.
    cout << test1 << test2 <<endl; //Bu da �al���r, nas�l m� ? "cout<<test1"i first argument olarak al�r,��nk� return out yap�yoruz.
                                    //Sonras�nda da "test2"yi second argument olarak al�r.

    return 0;
}
