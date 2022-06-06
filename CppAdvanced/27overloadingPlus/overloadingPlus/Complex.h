#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace caveofprogramming{

class Complex{

private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real,double imaginary);
    Complex(const Complex& other);
    const Complex& operator=(const Complex& other);

    double getReal()const{
        return real;
    }

    double getImaginary()const{
        return imaginary;
    }
    //Complex operator+(const Complex& other);//E�er operator+ overloading class i�ine yaz�l�rsa:
};

ostream& operator<<(ostream& out, const Complex& c);
Complex operator+(const Complex& c1,const Complex& c2);
Complex operator+(const Complex& c1,double c2);
Complex operator+(double c1,const Complex& c2);



} //namespace end
#endif // COMPLEX_H_
