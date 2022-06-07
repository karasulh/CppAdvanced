// exceptionCatchingOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;

//Bu programda catch'leri yazarken hangi sýraya göre yazmamýz gerektiðini belirtiyor. Catch'leri yazarken class-subclass iliþkisine dikkat etmeliyiz. Subclass catchlerini daha üste yazmalýyýz.
//Çünkü o zaman subclass hatalarý parent class'ýn hatalarýna giriyor çünkü parent'ýn alt classý olduðu için programda ona da uyuyor.


void goesWrong() { // methodun sonuna throw() diye eklersek errorü exception olarak direk altta verir.
	
	bool error1Detected=true;
	bool error2Detected=false;

	if(error1Detected){
		throw bad_alloc(); //subclass	
	}

	if(error2Detected){
		throw exception();	//parent class
	}
}


int main()
{

	try{
		goesWrong();
	}
	catch(exception& e){ //Bu sýra yanlýþ mesela alttaki catch yukarýda olmalý.!
		cout<<"Catching exception: "<< e.what() <<endl;
	}
	catch(bad_alloc& e){
		cout<<"Catching bad_alloc: "<< e.what() <<endl;
	}
	

	return 0;
}

