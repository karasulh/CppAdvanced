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

//Vectore push back deyip eleman ekleyebiliyoruz biliyorsun, böyle yapýnca da vectorün kapasitesi artmasý gerekiyor, fakat o an olandan büyük arrayler üretiyor gibi düþün. Böylece her eleman eklemesinde 
//capacity tek tek artmýyor, üssel olarak artýyor capacity. Belli bi sayý elemandan sonra tekrar yetmeyip tekrar artýyor ve
//vectorün capacitysi arttýkça aslýnda sanki yeni bir array üretip eskisini de ona kopyalýyor gibi düþün.

int main()
{
	vector<double> numbers(0); //En baþta 5 elementim var gibi bir þey bu, bundan sonraki push_backler bunun üzerine ekleme yapar aslýnda. Mesela 5 olsaydý 0 yerine, en son size 10005 olurdu.

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

	//numbers.clear(); //Size sýfýrlanýr ama capacity sýfýrlanmaz.
	//numbers.reserve(10000); //Change capacity, daha fazla yapabilirsin olandan ama azýný yapamazsýn.
	//numbers.resize(20); //Change size
	cout<<numbers[2] <<endl;
	cout <<"Size:"<<numbers.size()<<endl;
	cout<<"Capacity:"<<numbers.capacity()<<endl;


	return 0;
}

