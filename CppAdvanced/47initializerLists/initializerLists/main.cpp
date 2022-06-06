#include <iostream>
#include <vector>
#include <initializer_list> //Bunu eklemeliyiz!

using namespace std;

class Test{
public:
    Test(initializer_list<string> texts){
        for(auto text:texts){
            cout<<text<<endl;
        }
    }
    void print(initializer_list<string> texts){
        for(auto text:texts){
            cout<<text<<endl;
        }
    }
};


int main()
{
    vector<int> numbers{1,3,5,6};
    cout << numbers[2] << endl;

    Test test{"one","two","three"}; //Test test({"one","two","three"});
    test.print({"hey","hi","merhaba","selam"});

    return 0;
}
