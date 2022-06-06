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

        auto pLambda=[this,three,four](){ //Buraya instance variableslar� yazarsak compile hatas� al�r�z one,two gibi variablelar�.
            one=111;                        //Onun yerine this yazarak pass by value ile di�er variablelar� g�rebiliriz.
            cout<<one<<endl;                //[&,this] yazsak da �al���rd�. ama [=,this] yaz�nca �al��m�yor.
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
