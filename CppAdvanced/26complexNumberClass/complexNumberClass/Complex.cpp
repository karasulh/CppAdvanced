#include "Complex.h"


namespace caveofprogramming{

Complex::Complex():real(0),imaginary(0){}
Complex::Complex(double real,double imaginary):real(real),imaginary(imaginary){};

Complex::Complex(const Complex& other){//Copy Constructor
    cout<<"Copy"<<endl;
    real=other.real;
    imaginary=other.imaginary;
}

const Complex& Complex::operator=(const Complex& other){
    cout<<"Assignment"<<endl;
    real=other.real;
    imaginary=other.imaginary;
    return *this;
}

ostream& operator<<(ostream& out, const Complex& c){
    out<<"(" << c.getReal() <<","<<c.getImaginary()<<")";
    return out;
}

} //namespace end
