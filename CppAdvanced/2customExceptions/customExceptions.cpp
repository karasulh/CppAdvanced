// customExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;

//Bu programda kendimizin tanýmladýðý exceptionlarý nasýl kullanýrýz, onu görüyoruz.

class MyException:public exception{
public:
	virtual const char* what() const throw(){ //Bu method ismini cpp exceptions diye nete yazdýk cppreference.com sayfasýndan çektik.
		return "Something bad happened!";
	}
};

class Test{
public:
	void goesWrong() { // methodun sonuna throw() diye eklersek errorü exception olarak direk altta verir.
		throw MyException();
	}
};

int main()
{
	Test test;

	try{
		test.goesWrong();
	}
	catch(MyException& e){
		cout<<e.what()<<endl;
	}

	return 0;
}

