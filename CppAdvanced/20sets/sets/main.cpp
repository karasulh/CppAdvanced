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

    //Bunu koyarak iteratorda s�ralamay� nas�l yapaca��n� set i�in belirliyoruz. �sim s�ras�na g�re yap�yor.
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

    if(numbers.count(30)){ //it returns 0-1, find methodu yerine kullan�labilir.
        cout<<"Number found"<<endl;
    }

    cout<<endl;


    //Class'tan set olu�turma
    set<Test> tests;
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(20,"Mamo"));
    tests.insert(Test(30,"Nano"));
    tests.insert(Test(20,"Tano")); //E�er operator<'� id'ye g�re ayarlasayd�k bu sefer de bunu pas ge�erdi.
    tests.insert(Test(200,"Tano")); // Bunu insert etmiyor ��nk� burda biz s�ralama i�ini set i�inde isime g�re yap demi�tik ve ayn� isimden var oldu�u i�in
                                    // �nceden, bunu pas ge�iyor. Mapteki tek key value olmas� gerekiyor mant���yla ayn�.

    for(set<Test>::iterator it=tests.begin(); it!=tests.end(); it++){
        it->print();
   }

    return 0;
}
