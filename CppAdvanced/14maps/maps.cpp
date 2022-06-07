// maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> ages; 

	ages["Mike"]= 40;
	ages["Raj"]= 20;
	ages["Vicky"]= 30;

	ages["Mike"]=70;

	cout<<ages["Raj"]<<endl;
	//cout<<ages["Bugra"]<<endl; //Biz bunu başta vermedik ama bu default olarak map'e 0 initial valuesu ile girecek. Bundan dolayı elimizde "find" komutu var.

	if(ages.find("Bugra")!=ages.end()){
		cout<<"Found Bugra" <<endl;
	}
	else{
		cout<<"Key not found"<<endl;
	}


	pair<string,int> addToMap("Bugrahan",24);
	ages.insert(addToMap); // Böyle map'e eleman eklyebiliriz.
	ages.insert(pair<string,int> ("Muhammet",24)); //Veya böyle
	ages.insert(make_pair("Elif",22)); //Veya böyle


	for(map<string,int>::iterator it =ages.begin(); it!= ages.end();it++){
		
		pair<string,int> age=*it; //Map'in her elemanı aslında bir pair'dir. *
		cout<< age.first <<":"<< age.second <<endl;
	}

	for(map<string,int>::iterator it =ages.begin(); it!= ages.end();it++){
		cout<< it->first <<":"<< it->second <<endl;
	}

	return 0;
}

