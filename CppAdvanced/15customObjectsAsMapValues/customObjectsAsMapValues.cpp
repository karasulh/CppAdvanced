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
	
	Person():name(""),age(0){ cout<<"Constructor running"<<endl; } //map<int,Person> people; bunu yazmazsak bu sat�rdaki map'te Person i�in hata veriyor. argumentsiz constructor yazmam�z gerekiyor.
	
	Person(string name, int age): name(name),age(age){ cout<<"Two parameter constructor running."<<endl;}
	
	Person(const Person& other){ //Copy constructor bazen farkl� bir �ekilde kopyalamak istedi�imizde kullan�r�z. Baz� compiler versiyonlar� bunu kullan�rken baz�s� elimine eder.
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

	people[50]=Person("Mike",40); //Burda mesela constructor �al���r sonra assignment operator �al���r.
	//people[20]=Person("Vicky",30);
	//people[13]=Person("Raj",20);

	
	//Bunda mesela make_pair'in 2.argumentine Personumuz kopyalan�r, sonra make_pair'den return ederken pair'imiz kopyalan�r, sonra insert fonksiyonu argument olarak onlar� al�rken (pass by value) gene kopyalan�r.
	//B�ylece 3 kez copy constructor �a�r�l�r:
	people.insert(make_pair(55,Person("Sue",13)));

	for(map<int, Person>::iterator it =people.begin(); it!= people.end();it++){
		cout<< it->first <<":"<< flush;
		it->second.print();
	}

	return 0;
}

