// vectorsAndMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
Size is not allowed to differ between multiple compilers. The size of a vector is the number of elements that it contains, which is directly controlled by how many elements you put into the vector.

Capacity is the amount of total space that the vector has. Under the hood, a vector just uses an array. The capacity of the vector is the size of that array. 
This is always equal to or larger than the size. The difference between them is the number of elements that you can add to the vector before the array under the hood needs to be reallocated.

You should almost never care about the capacity. It exists to let people with very specific performance and memory constraints do exactly what they want.
*/

//Vectore push back deyip eleman ekleyebiliyoruz biliyorsun, b�yle yap�nca da vector�n kapasitesi artmas� gerekiyor, fakat o an olandan b�y�k arrayler �retiyor gibi d���n. B�ylece her eleman eklemesinde 
//capacity tek tek artm�yor, �ssel olarak art�yor capacity. Belli bi say� elemandan sonra tekrar yetmeyip tekrar art�yor ve
//vector�n capacitysi artt�k�a asl�nda sanki yeni bir array �retip eskisini de ona kopyal�yor gibi d���n.

int main()
{
	vector<double> numbers(0); //En ba�ta 5 elementim var gibi bir �ey bu, bundan sonraki push_backler bunun �zerine ekleme yapar asl�nda. Mesela 5 olsayd� 0 yerine, en son size 10005 olurdu.

	cout<<"Size:" << numbers.size() <<endl;

	int capacity=numbers.capacity();
	cout<< "Capacity:" << capacity<<endl<<endl;

	for(int i=0;i<1000;i++){

		if(numbers.capacity()!=capacity){
			capacity=numbers.capacity();
			cout<<"Capacity:"<<capacity<<endl;
		}
		numbers.push_back(i);
	}

	//numbers.clear(); //Size s�f�rlan�r ama capacity s�f�rlanmaz.
	//numbers.reserve(10000); //Change capacity, daha fazla yapabilirsin olandan ama az�n� yapamazs�n.
	//numbers.resize(20); //Change size
	cout<<numbers[2] <<endl;
	cout <<"Size:"<<numbers.size()<<endl;
	cout<<"Capacity:"<<numbers.capacity()<<endl;


	return 0;
}

