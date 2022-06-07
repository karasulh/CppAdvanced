// lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

//List'lerin vectorlerden farký vectorler baþa veya sona eklemeye izin verirken, listde istediðin kýsýmdan eleman silip ekleyebilyorsun.

int main()
{
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	list<int>::iterator it=numbers.begin();
	it++;
	numbers.insert(it,100); //inserting 100 to 1. element
	cout<<"Element:"<<*it<<endl;

	list<int>::iterator eraseIt=numbers.begin();
	eraseIt++;
	eraseIt=numbers.erase(eraseIt); //deleting 100 to 1. element //Note: bunu eraseIt'e eþitlememiz gerekiyor yoksa runtime error veriyor, sildiðimiz elemanýn pointerýný okumaya çalýþýyoruz.
	//eðer eþitlersek eraseIt'i 1 arttýrýp bir sonraki elemana point etmiþ oluyor.
	cout<<"Element:"<<*eraseIt<<endl;

	
	for(list<int>::iterator it=numbers.begin();it!=numbers.end();){
		if(*it ==2){
			numbers.insert(it,1234);
		}

		if(*it==1){
			it= numbers.erase(it); //Böyle yapýnca eþitlerken it'i 1 arttýrdýðý için for döngüsünde de 1 arttýrýrsak 2'yi pas geçeriz ondan aþaðýdaki gibi arttýrýyoruz:
		}
		else{
			it++;
		}
	}
	
	for(list<int>::iterator it=numbers.begin();it!=numbers.end();it++){
		cout<<*it<<endl;

	}


	return 0;
}

