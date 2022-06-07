// structsAndPadding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Eðer biz #pragma'yý yazmazsak sizeof 64 gelecekti, 50lik array 50 byte, int 4 byte, double 8 byte, toplam 62 byte ediyor ama struct yapýsýnda packet mekanizmasý var, bunlar packetleniyor ve 
//variablelarýn benzer sizelara sahip olmasý saðlanýyor. Bu yüzden 64 byte gözüküyor. Eðer biz bu packetleme iþlemini 1'er bytelar halinde yaparsak o zaman gerçek size'ýný görmüþ oluruz. 
//Bu packetleme iþlemlerinin bir stack ile olduðunu düþün, #prama ile bunun single byte boundaryli olduðunu söyledik.

#pragma pack(push,1)
//#pragma pack(pop) //Eðer bunu buraya yazarsak, 1lik paketleme iþlemi biter ve gene standart halini alýr. Result:64

struct Person{
	char name[50];
	int age;
	double weight;
};

//#pragma pack(pop) //Eðer bunu buraya yazarsak, 1lik paketleme iþlemi biter ve gene standart halini alýr. Result:62

int main()
{
	cout << sizeof(Person) <<endl;
	return 0;
}

