/*
Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/
//simple method
/*#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool is_prime(ll i)
{
    ll count=0;
    for(ll j=1;j<=sqrt(i);j++)
    {
        if(i%j==0)
        {
            if(j==sqrt(i))
                count+=1;
            else
            	count+=2;
        }
    }
    if(count==2)
    {
        return true;
    }
    return false;
}

int main(){
	// Write your code here
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll count=0;
    for(ll i=1;i<=n;i++)
    {
        if(is_prime(i))
            count++;
    }
    cout<<count<<"\n";
	return 0;
}*/



//sieve method
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool *make_sieve(ll n)
{
	bool *sieve=new bool[n+1];
	for(ll i=0;i<n+1;i++)
	{
		sieve[i]=true;
	}
	sieve[0]=sieve[1]=false;
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(sieve[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                sieve[j]=false;
            }
        }
	}
	return sieve;
}

int main()
{
    fast;
    ll n;
    cin>>n;
	bool *sieve=make_sieve(n);
	ll count=0;
    for(ll i=1;i<=n;i++)
    {
    	if(sieve[i])
    		count++;
    		//cout<<i<<" ";
	}
	cout<<count<<endl;
	delete [] sieve;
}
