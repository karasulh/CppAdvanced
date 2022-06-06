#include <iostream>
#include <set>

using namespace std;

class Test{
    int id;
    string name;
public:

    Test(): id(0), name(""){}
    Test(int id,string name): id(id), name(name){}
    void print() const{
        cout << "id:" <<id << " name:" << name<<endl;
    }

    //Bunu koyarak iteratorda sıralamayı nasıl yapacağını set için belirliyoruz. İsim sırasına göre yapıyor.
    bool operator<(const Test& other) const{
        return name<other.name;
    }

};


int main()
{

   set<int> numbers;
   numbers.insert(50);
   numbers.insert(10);
   numbers.insert(30);
   numbers.insert(30);
   numbers.insert(20);

   for( set<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
        cout<<*it<<endl;
   }

   set<int>::iterator it=numbers.find(30);
   if(it!=numbers.end()){
    cout<<"Found: " << *it <<endl;
   }

    if(numbers.count(30)){ //it returns 0-1, find methodu yerine kullanılabilir.
        cout<<"Number found"<<endl;
    }

    cout<<endl;


    //Class'tan set oluşturma
    set<Test> tests;
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(20,"Mamo"));
    tests.insert(Test(30,"Nano"));
    tests.insert(Test(20,"Tano")); //Eğer operator<'ü id'ye göre ayarlasaydık bu sefer de bunu pas geçerdi.
    tests.insert(Test(200,"Tano")); // Bunu insert etmiyor çünkü burda biz sıralama işini set içinde isime göre yap demiştik ve aynı isimden var olduğu için
                                    // önceden, bunu pas geçiyor. Mapteki tek key value olması gerekiyor mantığıyla aynı.

    for(set<Test>::iterator it=tests.begin(); it!=tests.end(); it++){
        it->print();
   }

    return 0;
}
