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

        return *this; //Bunu unutma return type'ý Test o yüzden böyle döndük.
    }

    Test(const Test& other){
        cout<<"Copy Constructor running"<<endl;
        *this=other; //Bunu yazarsak assignment operator de çalýþýr.
        //id=other.id;
        //name=other.name;
    }

    // "<<" bunun solundaki first argument oluyor,saðýndaki second argument. Yani cout<<test1 derken out=cout, test=test1 oluyor.
    friend ostream &operator<<(ostream &out, const Test &test){//Burdaki friend'i bunu dýþarý yazabiliriz diye ekledik.
        out<< test.id << ": " << test.name;
        return out;
    }

};

int main()
{
    Test test1(10,"Mike");
    Test test2(5,"Bob");
    cout << test1 << endl; // Normalde böyle yazýnca saçma olacaðýndan hata alýrýz, bunu önlemek için << operator'ünü overload ediyoruz.
    cout << test1 << test2 <<endl; //Bu da çalýþýr, nasýl mý ? "cout<<test1"i first argument olarak alýr,çünkü return out yapýyoruz.
                                    //Sonrasýnda da "test2"yi second argument olarak alýr.

    return 0;
}
