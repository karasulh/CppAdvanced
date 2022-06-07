// lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

//List'lerin vectorlerden fark� vectorler ba�a veya sona eklemeye izin verirken, listde istedi�in k�s�mdan eleman silip ekleyebilyorsun.

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
	eraseIt=numbers.erase(eraseIt); //deleting 100 to 1. element //Note: bunu eraseIt'e e�itlememiz gerekiyor yoksa runtime error veriyor, sildi�imiz eleman�n pointer�n� okumaya �al���yoruz.
	//e�er e�itlersek eraseIt'i 1 artt�r�p bir sonraki elemana point etmi� oluyor.
	cout<<"Element:"<<*eraseIt<<endl;

	
	for(list<int>::iterator it=numbers.begin();it!=numbers.end();){
		if(*it ==2){
			numbers.insert(it,1234);
		}

		if(*it==1){
			it= numbers.erase(it); //B�yle yap�nca e�itlerken it'i 1 artt�rd��� i�in for d�ng�s�nde de 1 artt�r�rsak 2'yi pas ge�eriz ondan a�a��daki gibi artt�r�yoruz:
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

