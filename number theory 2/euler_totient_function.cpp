/*
Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e.,
the numbers whose GCD (Greatest Common Divisor) with n is 1.
formula :- 
n*(1-1/p1)*(1-1/p2)*(1-1/p3)..
where p1,p2,p3... are the numbers whose gcd(pi,n)=1
PROGRAM FOR FINDING NUMBER OF NUMBERS IN RANGE [1,N] WHOSE GCD WITH N IS 1
*/
#include<iostream>
using namespace std;


void eulerPhi(int n){

	int phi[n+1];

	for(int i=1;i<=n;i++){
		phi[i] = i;
	}

	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(int j=2*i;j<=n;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout << "Euler Totient Phi For " << i << "Is :" << phi[i]<<endl;
	}

}
int main(){

  int n;
  cin>>n;
	eulerPhi(n);
	return 0;
}
