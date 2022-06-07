// vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Vector is is resizable array.

//vector<string>::iterator'u kullanarak vector elemanlarý üzerinde dolaþacaðýz.

int main()
{
	vector<string> strings; //Herhangi bir size vermeye gerek yok. vermek istersek ==> vector<string> strings(5) diye verebiliriz.

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	//cout<<strings[1]<<endl;
	//cout<<strings.size()<<endl;

	for(int i=0; i<strings.size(); i++){
		cout<<strings[i] <<endl;
	}

	for(vector<string>::iterator it=strings.begin(); it!= strings.end();it++){
		cout<< *it <<endl;
	}

	vector<string>::iterator it=strings.begin();
	it+=2;

	cout<<*it<<endl;


	return 0;
}

