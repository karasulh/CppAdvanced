// customObjectsAsMapKeys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;


//Burdaki durum �u, e�er biz bool operator<(const Person &other) const fonksyionu ile "<" operator�n� overload etmezsek, map'teki key value bir class oldu�undan s�ralama yapam�yor. 
//Yani map kendi i�inde bir sorting yapmal� fakat key value kar��la�t�r�labilir olmamas�ndan kaynakl� bir s�ralama yapam�yor. Bizde bunu overloading ile a��yoruz. Alfabede Z>A mant��� ile
//k���k olan harfi �nce s�ralayacak �ekilde bir map sort yapt�r�yoruz.

class Person{
private:
	string name;
	int age;
public:
	
	Person():name(""),age(0){ //cout<<"Constructor running"<<endl; 
	} //map<int,Person> people; bunu yazmazsak bu sat�rdaki map'te Person i�in hata veriyor. argumentsiz constructor yazmam�z gerekiyor.
	
	Person(string name, int age): name(name),age(age){ //cout<<"Two parameter constructor running."<<endl;
	}
	
	Person(const Person& other){ //Copy constructor bazen farkl� bir �ekilde kopyalamak istedi�imizde kullan�r�z. Baz� compiler versiyonlar� bunu kullan�rken baz�s� elimine eder.
		//cout<<"Copy constructor running"<<endl;
		name=other.name;
		age=other.age;
	}

	void print() const{
		cout<<name<<":"<<age<<flush;
	}

	//�NEML� BURASI YOKSA COMPILE ERROR VERIYOR.
	bool operator<(const Person &other) const{ //operator overloading yap�yoruz for "<" operator.

		if(name==other.name){
			return age<other.age; // Bunu yazarak e�er ayn� isimli bir class objesi eklersek, ya��na bak�p k���k olan� �nce yazmas�n� istedik. Di�er t�rl� sadece isme bak�nca ayn� isimdekinin �st�ne yaz�yor.
		}
		else{
			return name < other.name;
		}
	}

};



int main()
{
	
	map<Person,int> people; 

	people[Person("Mike",40)]=40; 
	people[Person("Mike",444)]=123; //Bunu yaz�nca name'e g�re k�yas etti�inden �stteki ile ayn� obje san�p �sttekinin �zerine yaz�yor. Bunu engellemek i�in operator< methodu i�ine if-else att�k.
	people[Person("Vicky",30)]=30;
	people[Person("Raj",20)]=20;
	

	

	for(map<Person, int>::iterator it =people.begin(); it!= people.end();it++){
		
		cout<< it->second <<":"<< flush;
		it->first.print();
		cout<<endl;
	}

	

/*
	string test1="Mike";
	string test2="Bob";

	bool test= test1>test2; // Alfabetik s�raya g�re M>B oldu�u i�in sonu� 1 geliyor.
	cout<<test<<endl;

	*/
	return 0;
}

