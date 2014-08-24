//============================================================================
// Name        : Euler9.cpp
// Author      : Ieuan Richards
// Version     :
// Copyright   : Your copyright notice
// Description : Euler9
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct triplet {
	int a;
	int b;
	int c;
};

void addChildPairs(int m, int n, vector<pair<int, int> > &pairs);
int doesCoprimeProduceSpecialTriplet(int m, int n);
triplet getTriplet(int m, int n, int k);

int main() {

	vector<pair<int, int> > coprimePairs;
	pair<int, int> firstPair(2,1);
	pair<int, int> secondPair(3,1);
	coprimePairs.push_back(firstPair);
	coprimePairs.push_back(secondPair);

	triplet specialTriplet;
	int k = -1;

	for (size_t i=0; i<coprimePairs.size(); i++)
	{
		int m = coprimePairs[i].first;
		int n = coprimePairs[i].second;
		if ((k = doesCoprimeProduceSpecialTriplet(m, n)) > 0)
		{
			specialTriplet = getTriplet(m, n, k);
			break;
		}
		addChildPairs(m, n, coprimePairs);
	}

	int product = specialTriplet.a * specialTriplet.b * specialTriplet.c;

	cout << "Answer is: " << product << endl;

	return 0;
}

triplet getTriplet(int m, int n, int k)
{
	triplet specialTriplet;
	specialTriplet.a = k * ((m*m) - (n*n));
	specialTriplet.b = k * (2*m*n);
	specialTriplet.c = k * ((m*m) + (n*n));
	return specialTriplet;
}

int doesCoprimeProduceSpecialTriplet(int m, int n)
{
	int x = m * (m + n);

	for (int k=1; (k * x) <= 500; k++)
	{
		if ((k * x) == 500)
		{
			return k;
		}
	}
	return -1;
}
void addChildPairs(int m, int n, vector<pair<int, int> > &pairs)
{
	pair<int, int> firstPair;
	pair<int, int> secondPair;
	pair<int, int> thirdPair;

	firstPair.first = (2 * m) - n;
	firstPair.second = m;
	secondPair.first = (2 * m) + n;
	secondPair.second = m;
	thirdPair.first = m + (2 * n);
	thirdPair.second = n;

	pairs.push_back(firstPair);
	pairs.push_back(secondPair);
	pairs.push_back(thirdPair);
}
