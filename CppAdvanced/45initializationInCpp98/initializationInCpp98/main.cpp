#include <iostream>

using namespace std;

int main()
{
    int values[]={1,13,5};
    cout<<values[1]<<endl;

    class C{
    public:
        string text;
        int id;
    };

    C c1={"Hello",7}; //Bu þekilde class ve structu initialize edebiliyoruz.
    cout<<c1.text<<endl;

    struct S{
        string text;
        int id;
    };

    S s1= {"Hello",7};
    cout<<s1.text<<endl;

    struct R{
        string text;
        int id;
    }r1 = {"Hello",7},r2 = {"Hi",78} ; //Burda variable'lari virgülle initialize edebiliriz.


    cout<<r1.text<<endl;
    cout<<r2.text<<endl;

    //Cpp98'de mesela vectorler için initialize ederken bir kýsayol yok ve þu þekilde yazýyoruz:
    /*
    vector<string> strings;

    strings.push_back("One");
    strings.push_back("we");
    strings.push_back("ne");
    */

    return 0;
}
