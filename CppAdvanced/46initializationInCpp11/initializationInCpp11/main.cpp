#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int value{5};
    cout<<value<<endl;

    string text{"Hello"};
    cout<<text<<endl;

    int numbers[]{1,2,4};
    cout<<numbers[0]<<endl;

    int* pInts = new int[3]{1,6,5};
    cout<<pInts[1]<<endl;
    delete pInts;

    int value1{};//default value atar.
    cout<<value1<<endl;

    int* pSomething{&value};
    cout<<*pSomething<<endl;

    int* pSomething2{}; //Equivalent to int* pSomething2 = nullptr
    cout<<pSomething2<<endl; //Null 0 yazdýrýr.

    int numbers1[5]{};
    cout<<numbers1[1]<<endl;//Null 0 yazdýrýr.

    struct S{
        string text;
        int id;
    }s1{"Hello",7};

    cout<<s1.text<<endl;

    vector<string> strings{"one","two","three"}; //Vectorü bu þekilde cpp11 de initialize edebiliyoruz.
    cout<<strings[1]<<endl;




    return 0;
}
