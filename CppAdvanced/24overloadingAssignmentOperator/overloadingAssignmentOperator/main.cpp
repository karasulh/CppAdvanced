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

};

int main()
{
    Test test1(10,"Mike");
    test1.print();

    Test test2(20,"Bob");

    test2=test1; //assignment operator �al���r.
    test2.print();

    Test test3;
    //test3=test2=test1;


    test3.operator=(test2);//test3=test2; ikisi de ayn� �ey oluyor. //assignment operator �al���r.
    test3.print();

    Test test4=test3; //Bunda ise copy initialization oldu�undan, copy constructor �al���r.
    test4.print();

    return 0;
}
