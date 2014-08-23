//============================================================================
// Name        : Euler5.cpp
// Author      : Ieuan Richards
// Version     :
// Copyright   : Your copyright notice
// Description : Euler5
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void printComposition(int n, vector<int>& comp);
int getHighestPowerOfPrime(int prime, const vector<vector<int> > &compositions);
int getOcurrencesOfPrimeInComposition(int prime, const vector<int> &composition);
void insertPrimeCompositionOfN(int n, vector<int>&, vector<int>&);
void insertPrimesUpTo(int upperBound, vector<int> &primes);

int main() {

	clock_t begin = clock();
	int nums[] = {11,12,13,14,15,16,17,18,19,20};
	vector<int> primes;
	insertPrimesUpTo(20, primes);

	vector<vector<int> > primeCompositions;
	for (int i=0; i<10; i++)
	{
		vector<int> pc;
		insertPrimeCompositionOfN(nums[i], primes, pc);
		primeCompositions.push_back(pc);
	}

	int total = 1;

	for (size_t i=0; i<primes.size(); i++)
	{
		int highestPower = getHighestPowerOfPrime(primes[i], primeCompositions);

		if (highestPower != 0)
		{
			total = total * pow((double)primes[i],highestPower);
		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Answer is: " << total << " found in " << elapsed_secs << "s"<< endl;

	return 0;
}

void printComposition(int n, vector<int>& comp)
{
	cout << "The composition of " << n << " is:" << endl;
	for (size_t i=0; i<comp.size(); i++)
	{
		cout << comp[i] << ", ";
	}
	cout<<endl;
}

int getHighestPowerOfPrime(int prime, const vector<vector<int> > &compositions)
{
	int highestPower = 0;
	for (size_t i=0; i<compositions.size(); i++)
	{
		int occurrences = getOcurrencesOfPrimeInComposition(prime, compositions[i]);
		if (occurrences > highestPower)
		{
			highestPower = occurrences;
		}
	}
	return highestPower;
}

int getOcurrencesOfPrimeInComposition(int prime, const vector<int> &composition)
{
	int occurences = 0;
	for (size_t i=0; i<composition.size(); i++)
	{
		if (composition[i] == prime)
		{
			occurences++;
		}
	}
	return occurences;
}

void insertPrimeCompositionOfN(int n, vector<int> &primes, vector<int> &primeComposition)
{
	if (find(primes.begin(), primes.end(), n) != primes.end())
	{
		primeComposition.push_back(n);
	}
	else
	{
		for (size_t i=0; i<primes.size(); i++)
		{
			if ((n % primes[i]) == 0)
			{
				primeComposition.push_back(primes[i]);
				insertPrimeCompositionOfN(n/primes[i], primes, primeComposition);
				break;
			}
		}
	}
}

void insertPrimesUpTo(int upperBound, vector<int> &primes)
{
	int* possiblePrimes = new int[upperBound];

	possiblePrimes[0] = 1;
	possiblePrimes[1] = 1;

	for (int i=0; i<upperBound;i++)
	{
		if (possiblePrimes[i] != 1)
		{
			primes.push_back(i);

			for (int p=2; p<(upperBound/i); p++)
			{
				possiblePrimes[p*i] = 1;
			}
		}
	}
	delete possiblePrimes;
}
