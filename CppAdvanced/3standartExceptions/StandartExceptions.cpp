// StandartExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CanGoWrong{
public:
	CanGoWrong(){
		char *pMemory = new char[999999999999]; //Bu kadar fazla alan isteyince prorgam allocate edemeyip bad allocation diye error veriyor. 
		delete[] pMemory;
	}

};

int main()
{
	CanGoWrong wrong;
	
	try{
		CanGoWrong wrong;
	}
	catch(bad_alloc &e){                    //Normalde bad_alloc diye errror veriyor ama galiba bu versiyonda direk d�z hataya �evirdikleri i�in bu program �al��m�yor.
		cout<<"Caught exception" << e.what() <<endl; //what() ile hatan�nn ne oldu�unu yaz�yor.
	}
	
	
	cout<<"Still running"<<endl;

	return 0;
}

