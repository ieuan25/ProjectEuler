//============================================================================
// Name        : Euler7.cpp
// Author      : Ieuan Richards
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(long int factor);
int getNthPrime(int n);

int main() {

	clock_t begin = clock();

	int ans = getNthPrime(10001);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Answer is: " << ans << " found in " << elapsed_secs << "s"<< endl;
	return 0;
}

int getNthPrime(int n)
{
	int count = 0;
	for (int i=2; ; i++)
	{
		if (is_prime(i))
		{
			count++;
			if (count == n)
				return i;
		}
	}
	return -1;
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
