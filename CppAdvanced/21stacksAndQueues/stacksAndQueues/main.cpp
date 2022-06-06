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

    testStack.push(Test("Muhammet")); // Biz her push yapt���m�zda stack'a koydu�umuz objemiz stack'a kopyalan�p daha sonra orijinali siliniyor.Destructor �al���yor.
    testStack.push(Test("Bugrahan"));
    testStack.push(Test("Kara"));

    cout<<endl;

    /*
    //This is invalid code because object is destroyed with pop and try to print.
    Test& test1 = testStack.top();
    testStack.pop();
    test1.print(); //Reference refers to destroyed objects
    */


    //testStack.pop(); // Pop'da da Test objesi siliniyor. Destructor �a�r�l�yor.
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

    testQueue.push(Test("Elif")); // Biz her push yapt���m�zda stack objemiz kopyalan�p daha sonra silinip tekrardan eklenmi� hali ile yarat�l�yor.
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
