#include <iostream>

using namespace std;

class Test{
    int id{3};
    string name{"Mike"};
public:
    Test()=default; // Test(){}
    Test(const Test& other) =delete;
    Test &operator=(const Test& other)=delete;
    //Normalde bu �ekilde ama biz bunlar� silince copy constructor ve "=" operator operationlar� hata verecek.
    /*
    Test(const Test& other) =default;
    Test &operator=(const Test& other)=default;
    */

    Test(int id): id(id){}

    void print(){
        cout<<id<<":"<<name<<endl;
    }

};


int main()
{
    Test test;
    test.print();

    Test test1(777);
    test1.print();

    /* //Bunlar hata veriyor, delete ile �sttekileri silince.
    Test test2=test1;
    test2=test;
    */

    return 0;
}
