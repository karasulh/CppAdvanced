#include <iostream>
using namespace std;

/* B�yle yapsak da olurdu ama �irkin dururdu.
class ring{
public:
    class iterator{
    public:
        void print(){
            cout<<"Hello from iterator"<<endl;
        }
    };
};
*/

template <class T>
class ring{
public:
    class iterator;
};

template <class T>
class ring<T>::iterator{
    public:
        void print(){
            cout<<"Hello from iterator "<<T()<<endl; //Default constructor of T yaz�l�r. int i��in 0, string i�in bo�luk
        }
};
/* B�yle de yazabiliyoruz, ama okumas� kolay olsun diye sadece burada class'lar� nested yapaca��z.
void ring::iterator::print(){
            cout<<"Hello from iterator"<<endl;
        }
*/
