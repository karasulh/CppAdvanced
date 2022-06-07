// readingAndWritingBinaryFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//Binary tanýmlý file'larda .read ve .write fonksiyonlarý var, bunlarý kullanacaðýz burada struct yapýsýyla birleþtirieceðiz. Bunlara argüman olarak address of stream ve size of stream verdik.

#pragma pack(push,1) //Bu packetleme iþlemlerinin bir stack ile olduðunu düþün, #prama ile bunun single byte boundaryli olduðunu söyledik.

struct Person{
	char name[50];
	int age;
	double weight;
};

#pragma pack(pop) //Eðer bunu buraya yazarsak, 1lik paketleme iþlemi biter ve gene standart halini alýr. Result:62

int main()
{
	Person someone={"Bugra",24,87.5};
	string fileName="test.bin";


	////Writing Binary File ///// 


	ofstream outputFile;

	outputFile.open(fileName,ios::binary); //ios::binary önemli "ios::binary | ios::out" diye de yazabilirdik ofstream yazmasaydýk.


	if(outputFile.is_open()){

	outputFile.write(reinterpret_cast<char*>(&someone),sizeof(Person)); //reinterpret_cast yaparak char* cast ettik. Ayrýca pointer istiyor argüman olarak.
	outputFile.close();

	}
	else{
		cout<<"couldnot create file" + fileName <<endl;
	}



	////Reading Binary File /////

	Person someoneElse={};

	ifstream inputFile;

	inputFile.open(fileName,ios::binary); //ios::binary önemli "ios::binary | ios::out" diye de yazabilirdik ofstream yazmasaydýk.


	if(inputFile.is_open()){

	inputFile.read(reinterpret_cast<char*>(&someoneElse),sizeof(Person)); //reinterpret_cast yaparak char* cast ettik. Ayrýca pointer istiyor argüman olarak ondan &someone.
	inputFile.close();

	}
	else{
		cout<<"couldnot read file" + fileName <<endl;
	}


	cout<<someoneElse.name<< "," << someoneElse.age << "," << someoneElse.weight <<endl;

	return 0;
}

