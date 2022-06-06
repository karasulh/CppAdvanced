#include <iostream>
#include <memory>

using namespace std;

//Share edilebilen ve bütün shared variablelar destroyed olmadýysa otomatik olarak destroyed olmayan pointer tipidir.

class Test{
public:
    Test(){
        cout << "created" << endl;
    }
    void greet(){
        cout << "Hello" << endl;
    }
    ~Test(){
        cout << "destroyed" << endl;
    }

};


int main()
{
    shared_ptr<Test> pTest2(nullptr);

    {
        shared_ptr<Test> pTest1=make_shared<Test>();
        pTest2=pTest1;
        auto pTest3=pTest1;
    } //Normalde burada direk destroyed olurdu suslu parantez bittigi icin ama shared olduðu için Finished'den sonra destroyed oluyor.

    cout << "Finished" << endl;


    return 0;
}
