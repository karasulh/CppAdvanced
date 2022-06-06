#include <iostream>

using namespace std;

class Test{
private:
    int one;
    int two;
public:
    void run(){
        int three{3};
        int four{4};

        auto pLambda=[this,three,four](){ //Buraya instance variableslarý yazarsak compile hatasý alýrýz one,two gibi variablelarý.
            one=111;                        //Onun yerine this yazarak pass by value ile diðer variablelarý görebiliriz.
            cout<<one<<endl;                //[&,this] yazsak da çalýþýrdý. ama [=,this] yazýnca çalýþmýyor.
            cout<<three<<endl;
            cout<<four<<endl;
        };
        pLambda();
    }
};

int main()
{
    Test test;
    test.run();
    return 0;
}
