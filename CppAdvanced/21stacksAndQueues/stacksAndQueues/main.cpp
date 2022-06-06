#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class Test {
private:
    string name;
public:
    Test(string name):name(name){}
    ~Test(){
        //cout<<"Object destroyed"<<endl;
    }
    void print(){
        cout<<"name: "<<name << endl;
    }
};

int main()
{
    //Stack
    //LIFO
    stack<Test> testStack;

    testStack.push(Test("Muhammet")); // Biz her push yaptýðýmýzda stack'a koyduðumuz objemiz stack'a kopyalanýp daha sonra orijinali siliniyor.Destructor çalýþýyor.
    testStack.push(Test("Bugrahan"));
    testStack.push(Test("Kara"));

    cout<<endl;

    /*
    //This is invalid code because object is destroyed with pop and try to print.
    Test& test1 = testStack.top();
    testStack.pop();
    test1.print(); //Reference refers to destroyed objects
    */


    //testStack.pop(); // Pop'da da Test objesi siliniyor. Destructor çaðrýlýyor.
    //Test test2= testStack.top();
    //est2.print();


    while(testStack.size()>0){
        Test& test = testStack.top();
        test.print();
        testStack.pop();
    }
    cout<<endl;



    //Queue
    //FIFO
    queue<Test> testQueue;

    testQueue.push(Test("Elif")); // Biz her push yaptýðýmýzda stack objemiz kopyalanýp daha sonra silinip tekrardan eklenmiþ hali ile yaratýlýyor.
    testQueue.push(Test("Hilal"));
    testQueue.push(Test("Kara"));

    cout<<endl;

    testQueue.back().print();

    cout<<endl;

    while(testQueue.size()>0){
        Test& test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    cout<<endl;






    return 0;
}
