/*
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4
*/
#include<bits/stdc++.h>
typedef long long ll;
ll find_lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
void func(long long n)
{
    ll *sieve=new ll[n+1];
    for(ll i=1;i<n+1;i++)
    {
        sieve[i]=find_lcm(i,n);
	}
    
    ll *result=new ll[n+1];
    result[0]=0;
    for(ll i=1;i<n+1;i++)
    {
        result[i]=result[i-1]+sieve[i];
    }
    cout<<result[n]<<endl;
    delete [] result;
    delete [] sieve;
}
