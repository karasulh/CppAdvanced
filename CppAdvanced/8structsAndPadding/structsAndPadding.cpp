// structsAndPadding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//E�er biz #pragma'y� yazmazsak sizeof 64 gelecekti, 50lik array 50 byte, int 4 byte, double 8 byte, toplam 62 byte ediyor ama struct yap�s�nda packet mekanizmas� var, bunlar packetleniyor ve 
//variablelar�n benzer sizelara sahip olmas� sa�lan�yor. Bu y�zden 64 byte g�z�k�yor. E�er biz bu packetleme i�lemini 1'er bytelar halinde yaparsak o zaman ger�ek size'�n� g�rm�� oluruz. 
//Bu packetleme i�lemlerinin bir stack ile oldu�unu d���n, #prama ile bunun single byte boundaryli oldu�unu s�yledik.

#pragma pack(push,1)
//#pragma pack(pop) //E�er bunu buraya yazarsak, 1lik paketleme i�lemi biter ve gene standart halini al�r. Result:64

struct Person{
	char name[50];
	int age;
	double weight;
};

//#pragma pack(pop) //E�er bunu buraya yazarsak, 1lik paketleme i�lemi biter ve gene standart halini al�r. Result:62

int main()
{
	cout << sizeof(Person) <<endl;
	return 0;
}

