#include <iostream>
#include <memory>

using namespace std;

//C++'da memory leak s�k ya�anan bir sorun, bunu ��zmek i�in otomatik deallocated olan ve unique bir �e�it pointer tasarlanmis. Buna unique pointer diyoruz.
//Asl�nda san�rsam bizim normal pointerlarda buna cast ediyor.

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

class Temp{
private:
    unique_ptr<Test[]> pTest;
public:
    Temp():pTest(new Test[2]){} //Bu �ekilde constructorda initialize edilebilir.
};

int main()
{

    unique_ptr<int> pTest(new int); //Allocationg ve deallocating otomatik olarak yap�l�yor.
    *pTest=7;

    cout << *pTest << endl;


    {
        //unique_ptr<Test> pTest2(new Test);
        auto_ptr<Test> pTest2(new Test); //unique_ptr=auto_ptr
        pTest2->greet();
    }

    unique_ptr<Test[]> pTest3(new Test[2]);
    pTest3[1].greet();



    Temp temp;


    cout << "Finished" << endl;


    return 0;
}
