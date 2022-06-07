// parsingTextFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	string FileName="stats.txt";
	ifstream input; //input file stream demek.
	
	input.open(FileName);

	if(!input.is_open()){
		return 1;
	}


	while(input){ 
		
		string line;
		getline(input,line,':'); //getline "delimiter"a sahip. Biz ":" gelene kadar line'i al diyoruz burda.
		
		int population;
		input >> population;

		//input.get(); //Bir sonraki karakteri almak i�in kullan�l�r. newLine characteri printlerken s�k�nt� ��kar�yor, ondan kullan�yoruz. 
		input>>ws; //whitespace karaterleri ignore etmek i�in kullan�l�r. input.get() yerine kullanabilirsin.
		
		if(!input){ //En son bo�luktan dolay� bo�lu�u line olarak almasn� engellemek i�in yap�yoruz. Tekrar While'a girmeden line bitti�ini anlatmam�z gerekiyormu�.
			break;
		}//Veya while(!input.eof()) yazarak da durumu ��zebiliriz, bu if'i yazmadan.
		
		cout<<"'" <<line << "'" << "--"<< population <<endl;

	}
	
	
	input.close();
		
	return 0;
}
