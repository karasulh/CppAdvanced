#include <iostream>
using namespace std;

template<class T>
class ring{
private:
    int m_pos;
    int m_size;
    T* m_values;
public:
    class iterator;

public:
    ring(int size):m_pos(0),m_size(size),m_values(NULL){
        m_values=new T[size];
    }
    ~ring(){
        delete [] m_values;
    }
    int size(){
        return m_size;
    }
    void add(T value){
        m_values[m_pos++]=value;

        if(m_pos==m_size)
            m_pos=0;
    }
    T& get(int i){ //Return'ü reference olmasý daha iyi çünkü, eðer array elementi silindiyse falan reference invalid olur.
        return m_values[i];
    }


    iterator begin(){
        return iterator(0,*this);
    }
    iterator end(){
        return iterator(m_size,*this);
    }
};

template<class T>
class ring<T>::iterator{
private:
    int m_pos;
    ring& m_ring;
public:
    iterator(int pos,ring& aRing):m_pos(pos),m_ring(aRing){}

    iterator& operator++(){//Bu ++prefix type'ýna denk oluyor. ++it
        m_pos++;
        return *this;
    }
    iterator& operator++(int){//Bu postfix++ type'ýna denk oluyor. it++
        m_pos++;
        return *this;
    }
    T& operator*(){// cout<<*it diye yazarken kullanacaðýz.
        return m_ring.get(m_pos);
    }
    bool operator!=(const iterator& other)const{//it!=textring.end()
        return m_pos!=other.m_pos;
    }
};

