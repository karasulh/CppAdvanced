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

		//inFile >> line; // Bununla inFile i�indeki kelimeler yazd�r�labilir. Ama biz line olarak istiyoruz, yazd�rmak i�in.
	
		while(inFile){ //!inFile.eof() yazabilirsin.
			getline(inFile,line); //getline i�inn string k�t�phanesi laz�m!
			cout<< line <<endl;
		}
		inFile.close();
	}	
	else{
		cout<<"Could not open file:" << inFileName.c_str() <<endl;
	}


	return 0;
}
