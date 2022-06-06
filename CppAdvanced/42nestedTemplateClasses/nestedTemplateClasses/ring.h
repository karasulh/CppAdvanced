#include <iostream>
using namespace std;

/* Böyle yapsak da olurdu ama çirkin dururdu.
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
            cout<<"Hello from iterator "<<T()<<endl; //Default constructor of T yazýlýr. int iççin 0, string için boþluk
        }
};
/* Böyle de yazabiliyoruz, ama okumasý kolay olsun diye sadece burada class'larý nested yapacaðýz.
void ring::iterator::print(){
            cout<<"Hello from iterator"<<endl;
        }
*/
