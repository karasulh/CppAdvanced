// customObjectsAsMapValues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person{
private:
	string name;
	int age;
public:
	
	Person():name(""),age(0){ cout<<"Constructor running"<<endl; } //map<int,Person> people; bunu yazmazsak bu satýrdaki map'te Person için hata veriyor. argumentsiz constructor yazmamýz gerekiyor.
	
	Person(string name, int age): name(name),age(age){ cout<<"Two parameter constructor running."<<endl;}
	
	Person(const Person& other){ //Copy constructor bazen farklý bir þekilde kopyalamak istediðimizde kullanýrýz. Bazý compiler versiyonlarý bunu kullanýrken bazýsý elimine eder.
		cout<<"Copy constructor running"<<endl;
		name=other.name;
		age=other.age;
	}

	void print() const{
		cout<<name<<":"<<age<<endl;
	}

};



int main()
{
	map<int,Person> people; 

	people[50]=Person("Mike",40); //Burda mesela constructor çalýþýr sonra assignment operator çalýþýr.
	//people[20]=Person("Vicky",30);
	//people[13]=Person("Raj",20);

	
	//Bunda mesela make_pair'in 2.argumentine Personumuz kopyalanýr, sonra make_pair'den return ederken pair'imiz kopyalanýr, sonra insert fonksiyonu argument olarak onlarý alýrken (pass by value) gene kopyalanýr.
	//Böylece 3 kez copy constructor çaðrýlýr:
	people.insert(make_pair(55,Person("Sue",13)));

	for(map<int, Person>::iterator it =people.begin(); it!= people.end();it++){
		cout<< it->first <<":"<< flush;
		it->second.print();
	}

	return 0;
}

