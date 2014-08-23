//============================================================================
// Name        : Euler2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Euler2
//============================================================================

#include <iostream>
using namespace std;

int main() {

	clock_t begin = clock();
	unsigned int i = 1;
	unsigned int n = 2;
	unsigned int sum = 0;

	while (n < 4000000)
	{
		if ((n % 2) == 0)
		{
			sum += n;
		}
		int temp = n;
		n = n + i;
		i = temp;
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Answer is: " << sum << " found in " << elapsed_secs << "s"<< endl;
	return 0;
}
