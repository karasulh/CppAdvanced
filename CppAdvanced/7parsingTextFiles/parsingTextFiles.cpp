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

		//input.get(); //Bir sonraki karakteri almak için kullanýlýr. newLine characteri printlerken sýkýntý çýkarýyor, ondan kullanýyoruz. 
		input>>ws; //whitespace karaterleri ignore etmek için kullanýlýr. input.get() yerine kullanabilirsin.
		
		if(!input){ //En son boþluktan dolayý boþluðu line olarak almasný engellemek için yapýyoruz. Tekrar While'a girmeden line bittiðini anlatmamýz gerekiyormuþ.
			break;
		}//Veya while(!input.eof()) yazarak da durumu çözebiliriz, bu if'i yazmadan.
		
		cout<<"'" <<line << "'" << "--"<< population <<endl;

	}
	
	
	input.close();
		
	return 0;
}
