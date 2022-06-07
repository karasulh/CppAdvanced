// customExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;

//Bu programda kendimizin tan�mlad��� exceptionlar� nas�l kullan�r�z, onu g�r�yoruz.

class MyException:public exception{
public:
	virtual const char* what() const throw(){ //Bu method ismini cpp exceptions diye nete yazd�k cppreference.com sayfas�ndan �ektik.
		return "Something bad happened!";
	}
};

class Test{
public:
	void goesWrong() { // methodun sonuna throw() diye eklersek error� exception olarak direk altta verir.
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

