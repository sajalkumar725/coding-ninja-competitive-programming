/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define eb emplace_back
vector<ll> make_sieve(ll n)
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
    vector<ll> all_primes;
    for(ll i=2;i<=n;i++)
    {
        if(sieve[i])
        {
            all_primes.eb(i);
        }
    }
    return all_primes;
}

ll count_divisors(ll n)
{
    ll divisors=1;
    vector<ll> sieve=make_sieve(n);
    for(ll i=0;i<sieve.size();i++)
    {
    	ll count=0;
        ll k=sieve[i];
        while(n/k!=0)
        {
            count=(count%mod+(n/k)%mod)%mod;
            k=k*sieve[i];
        }
        count=(count+1)%mod;
        divisors=(divisors*count)%mod;
    }
    return divisors;
}


int main()
{
	fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<count_divisors(n)<<endl;
    }
	return 0;
}
