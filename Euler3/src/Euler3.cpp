//============================================================================
// Name        : Euler3.cpp
// Author      : Ieuan Richards
// Version     :
// Copyright   : Your copyright notice
// Description : Euler3
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

bool is_prime(long int);

int main() {

	clock_t begin = clock();
	long int highestPrimeFactor = 0;
	long int target_num = 600851475143;

	for (long int i = 2; i<=target_num; i++)
	{
		if ((target_num % i) == 0)
		{
			long int factor = target_num / i;
			if (is_prime(factor))
			{
				highestPrimeFactor = factor;
				break;
			}
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Answer is: " << highestPrimeFactor << " found in " << elapsed_secs << "s"<< endl;
	return 0;
}

bool is_prime(long int factor)
{
	for (long int i=2; i<=sqrt(factor); i++)
	{
		if ((factor%i) == 0)
		{
			return false;
		}
	}
	return true;
}



