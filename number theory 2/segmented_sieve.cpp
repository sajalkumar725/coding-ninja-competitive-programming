/*
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int>* sieve(){

	bool isPrime[MAX];
	for(int i=0;i<MAX;i++){
		isPrime[i] = true;
	}
	for(int i=2;i*i<MAX;i++){
		if(isPrime[i]){
			for(int j=i*i;j<MAX;j+=i){
				isPrime[j] = false;
			}
		}
	}
	vector<int>* primes = new vector<int>();
	primes->push_back(2);
	for(int i=3;i<MAX;i+=2){
		if(isPrime[i]){
			primes->push_back(i);
		}
	}
	return primes;
}
void printPrimes(long long l,long long r,vector<int>* & primes){
	bool isPrime[r-l+1];

	for(int i=0;i<=r-l;i++){
		isPrime[i] = true;
	}

	for(int i=0;primes->at(i)*(long long)primes->at(i) <= r;i++){
		int currPrime = primes->at(i);
		// Just smaller or equal value to l
		long long base = (l/(currPrime))*(currPrime);
		if(base < l){
			base = base + currPrime;
		}

		// Mark all mutliples within L To R as false
		for(long long j = base;j<=r ;j+= currPrime){
			isPrime[j-l] = false;
		}

		// There may be a case where base is itself a prime number .
		if(base == currPrime){
			isPrime[base-l] = true;
		}
	}

	for(int i=0;i<=r-l;i++){
		if(isPrime[i] == true){
			cout << i + l << endl;
		}
	}
}
int main(){
	vector<int>* primes = sieve();
	int t;
	cin >> t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		printPrimes(l,r,primes);
	}
	return 0;
}
