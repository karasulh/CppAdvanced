// readingTextFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	string inFileName="text.txt";
	ifstream inFile; //input file stream demek.
	
	inFile.open(inFileName);

	if(inFile.is_open()){

		string line;

		//inFile >> line; // Bununla inFile içindeki kelimeler yazdýrýlabilir. Ama biz line olarak istiyoruz, yazdýrmak için.
	
		while(inFile){ //!inFile.eof() yazabilirsin.
			getline(inFile,line); //getline içinn string kütüphanesi lazým!
			cout<< line <<endl;
		}
		inFile.close();
	}	
	else{
		cout<<"Could not open file:" << inFileName.c_str() <<endl;
	}


	return 0;
}
