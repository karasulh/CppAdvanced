#include <iostream>
#include <vector>
#include <algorithm> //Sort için gerekli bu!


using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(int id,string name): id(id), name(name){}
    void print(){
        cout<<"id: "<< id <<" name: "<<name << endl;
    }
    bool operator<(const Test& other) const{
        return id < other.id;
        //return name < other.name;
    }
    friend bool compare(const Test& a, const Test& b); //class'a friend olarak fonksiyonu tanıttık.
};



    bool compare(const Test& a, const Test& b){
        return a.name<b.name; //object'in private elemanlarına ulaşmaya çalışıyor,
    }                          //bu yüzden hata vermemesi için, class içinde bu fonksiyonu friend olarak tanımlamamız gerekiyor.


int main()
{
    vector<Test> tests;

    tests.push_back(Test(5,"Mike"));
    tests.push_back(Test(10,"Ru"));
    tests.push_back(Test(7,"Ma"));
    tests.push_back(Test(3,"Tu"));


    //sort(tests.begin(), tests.end()); // operator< yazmazsak hata verecek. Veya :
    sort(tests.begin(), tests.end(),compare);

    for(int i=0; i<tests.size(); i++){
        tests[i].print();
    }


    return 0;
}
