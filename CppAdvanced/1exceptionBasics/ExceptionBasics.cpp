// ExceptionBasics.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string.h>
using namespace std;

void mightGoWrong() {
	
	bool error1=false;
	bool error2=false;
	bool error3=true;

	
	if(error1){
		throw 13; //Send error message or code
	}
	
	if(error2){
		throw "Something went wrong(primitive string)";
	}
	
	if(error3){
		throw string("Something else went wrong(non-primitive string)");
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{

	try{
		mightGoWrong();
	}

	catch(int e){
		cout<< "Error Code: " << e <<endl;
	}

	catch(char const* e){ //Bu error3 için çalýþmýyor, yani string yapýsýný char* ile çekemiyoruz. 
		cout<< "Error Message: " << e <<endl;
	}

	catch(string& e){
		cout<< "String error Message: " << e.c_str() <<endl; //c.str() pointer dönüyor, bunu yazmayýnca hata veriyor.
	}

	cout<<"Still Running"<<endl;

	return 0;
}

