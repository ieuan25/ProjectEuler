//============================================================================
// Name        : Euler1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Euler 1
//============================================================================

#include <iostream>
using namespace std;

int main() {

	clock_t begin = clock();
	unsigned int sum = 0;

	for(int i=3; i<1000; i++)
	{
		if ((i%3) == 0 || (i%5) == 0)
		{
			sum += i;
		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Answer is: " << sum << " found in " << elapsed_secs << "s"<< endl;
	return 0;
}
