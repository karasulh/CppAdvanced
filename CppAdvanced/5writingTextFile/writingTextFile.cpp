// writingTextFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outFile; //output file stream demek.
	//Normal outputsuz yapmak istersek:
	//(1) fstream outFile;
	string outputFileName="text.txt";

	//(2) outFile.open(outputFileName, ios::out);
	outFile.open(outputFileName);

	if(outFile.is_open()){
		outFile << "Hello there"<<endl;
		outFile << 123 <<endl;
		outFile.close(); //Bu önemli unutma

	}
	else{
		cout<<"Could not create file:" << outputFileName.c_str() <<endl;
	}


	return 0;
}

