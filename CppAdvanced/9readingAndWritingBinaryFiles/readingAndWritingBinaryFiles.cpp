// readingAndWritingBinaryFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//Binary tan�ml� file'larda .read ve .write fonksiyonlar� var, bunlar� kullanaca��z burada struct yap�s�yla birle�tiriece�iz. Bunlara arg�man olarak address of stream ve size of stream verdik.

#pragma pack(push,1) //Bu packetleme i�lemlerinin bir stack ile oldu�unu d���n, #prama ile bunun single byte boundaryli oldu�unu s�yledik.

struct Person{
	char name[50];
	int age;
	double weight;
};

#pragma pack(pop) //E�er bunu buraya yazarsak, 1lik paketleme i�lemi biter ve gene standart halini al�r. Result:62

int main()
{
	Person someone={"Bugra",24,87.5};
	string fileName="test.bin";


	////Writing Binary File ///// 


	ofstream outputFile;

	outputFile.open(fileName,ios::binary); //ios::binary �nemli "ios::binary | ios::out" diye de yazabilirdik ofstream yazmasayd�k.


	if(outputFile.is_open()){

	outputFile.write(reinterpret_cast<char*>(&someone),sizeof(Person)); //reinterpret_cast yaparak char* cast ettik. Ayr�ca pointer istiyor arg�man olarak.
	outputFile.close();

	}
	else{
		cout<<"couldnot create file" + fileName <<endl;
	}



	////Reading Binary File /////

	Person someoneElse={};

	ifstream inputFile;

	inputFile.open(fileName,ios::binary); //ios::binary �nemli "ios::binary | ios::out" diye de yazabilirdik ofstream yazmasayd�k.


	if(inputFile.is_open()){

	inputFile.read(reinterpret_cast<char*>(&someoneElse),sizeof(Person)); //reinterpret_cast yaparak char* cast ettik. Ayr�ca pointer istiyor arg�man olarak ondan &someone.
	inputFile.close();

	}
	else{
		cout<<"couldnot read file" + fileName <<endl;
	}


	cout<<someoneElse.name<< "," << someoneElse.age << "," << someoneElse.weight <<endl;

	return 0;
}

