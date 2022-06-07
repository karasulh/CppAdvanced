// exceptionCatchingOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;

//Bu programda catch'leri yazarken hangi s�raya g�re yazmam�z gerekti�ini belirtiyor. Catch'leri yazarken class-subclass ili�kisine dikkat etmeliyiz. Subclass catchlerini daha �ste yazmal�y�z.
//��nk� o zaman subclass hatalar� parent class'�n hatalar�na giriyor ��nk� parent'�n alt class� oldu�u i�in programda ona da uyuyor.


void goesWrong() { // methodun sonuna throw() diye eklersek error� exception olarak direk altta verir.
	
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
	catch(exception& e){ //Bu s�ra yanl�� mesela alttaki catch yukar�da olmal�.!
		cout<<"Catching exception: "<< e.what() <<endl;
	}
	catch(bad_alloc& e){
		cout<<"Catching bad_alloc: "<< e.what() <<endl;
	}
	

	return 0;
}

