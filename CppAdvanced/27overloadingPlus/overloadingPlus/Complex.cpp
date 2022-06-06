#include "Complex.h"


namespace caveofprogramming{

/* //Eðer operator+ overloading class içine yazýlýrsa:
Complex Complex::operator+(const Complex& other){
    return Complex(other.getReal()+this->getReal(),other.getImaginary()+this->getImaginary());
}
*/

Complex operator+(const Complex& c1,const Complex& c2){
    return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex& c1,double c2){
    return Complex(c1.getReal()+c2,c1.getImaginary());
}
Complex operator+(double c1,const Complex& c2){
    return Complex(c1+c2.getReal(),c2.getImaginary());
}

ostream& operator<<(ostream& out, const Complex& c){
    out<<"(" << c.getReal() <<","<<c.getImaginary()<<")";
    return out;
}

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


} //namespace end
