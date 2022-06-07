// twoDVectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//2D vector için

int main()
{
	vector< vector<int> > grid(3, vector<int>(4,7)); // 3 row'u gösterir. 4 column sayýsýný gösterir. 7 ise elemanlarýn initial valuesunu gösterir.

	grid[1].push_back(8); //1. rowun sonuna 8 ekler.

	for(int row=0;row<grid.size();row++){
		for(int col=0; col<grid[row].size();col++){
			cout<<grid[row][col] <<flush;
		}
		cout<<endl;
	}


	return 0;
}

