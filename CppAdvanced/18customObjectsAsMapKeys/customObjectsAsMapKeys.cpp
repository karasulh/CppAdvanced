// customObjectsAsMapKeys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;


//Burdaki durum þu, eðer biz bool operator<(const Person &other) const fonksyionu ile "<" operatorünü overload etmezsek, map'teki key value bir class olduðundan sýralama yapamýyor. 
//Yani map kendi içinde bir sorting yapmalý fakat key value karþýlaþtýrýlabilir olmamasýndan kaynaklý bir sýralama yapamýyor. Bizde bunu overloading ile aþýyoruz. Alfabede Z>A mantýðý ile
//küçük olan harfi önce sýralayacak þekilde bir map sort yaptýrýyoruz.

class Person{
private:
	string name;
	int age;
public:
	
	Person():name(""),age(0){ //cout<<"Constructor running"<<endl; 
	} //map<int,Person> people; bunu yazmazsak bu satýrdaki map'te Person için hata veriyor. argumentsiz constructor yazmamýz gerekiyor.
	
	Person(string name, int age): name(name),age(age){ //cout<<"Two parameter constructor running."<<endl;
	}
	
	Person(const Person& other){ //Copy constructor bazen farklý bir þekilde kopyalamak istediðimizde kullanýrýz. Bazý compiler versiyonlarý bunu kullanýrken bazýsý elimine eder.
		//cout<<"Copy constructor running"<<endl;
		name=other.name;
		age=other.age;
	}

	void print() const{
		cout<<name<<":"<<age<<flush;
	}

	//ÖNEMLÝ BURASI YOKSA COMPILE ERROR VERIYOR.
	bool operator<(const Person &other) const{ //operator overloading yapýyoruz for "<" operator.

		if(name==other.name){
			return age<other.age; // Bunu yazarak eðer ayný isimli bir class objesi eklersek, yaþýna bakýp küçük olaný önce yazmasýný istedik. Diðer türlü sadece isme bakýnca ayný isimdekinin üstüne yazýyor.
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
	people[Person("Mike",444)]=123; //Bunu yazýnca name'e göre kýyas ettiðinden üstteki ile ayný obje sanýp üsttekinin üzerine yazýyor. Bunu engellemek için operator< methodu içine if-else attýk.
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

	bool test= test1>test2; // Alfabetik sýraya göre M>B olduðu için sonuç 1 geliyor.
	cout<<test<<endl;

	*/
	return 0;
}

