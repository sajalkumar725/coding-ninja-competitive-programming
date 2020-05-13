/*
Send Feedback
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//fibonaaci number
#define MOD 1000000007
void multiply(unsigned long long a[2][2],unsigned long long m[2][2])
{
    unsigned long long f,g,h,i;

    f = ( (a[0][0]%MOD * m[0][0]%MOD) %MOD + (a[0][1]%MOD * m[1][0]%MOD) %MOD )%MOD;
    g = ( (a[0][0]%MOD * m[0][1]%MOD) %MOD + (a[0][1]%MOD * m[1][1]%MOD) %MOD )%MOD;
    h = ( (a[1][0]%MOD * m[0][0]%MOD) %MOD + (a[1][1]%MOD * m[1][0]%MOD) %MOD )%MOD;
    i = ( (a[1][0]%MOD * m[0][1]%MOD) %MOD + (a[1][1]%MOD * m[1][1]%MOD) %MOD )%MOD;
    
    a[0][0] = f;
    a[0][1] = g;
    a[1][0] = h;
    a[1][1] = i;

}

void power(ll a[2][2],ll n)
{
	if(n==0 || n==1)
		return;
	power(a,n/2);
	multiply(a,a);
	if(n%2!=0)
	{
		ll m[2][2]={{1,1},{1,0}};
		multiply(a,m);
	}
	return;
}

ll matrix_exponention(ll n)
{
    if(n==0) 
        return 0; 
    if(n==1) 
        return 1;
	ll a[2][2]={{1,1},{1,0}};
	power(a,n-1);
	return a[0][0];
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	ll sum=0;
	for(ll i=m;i<=n;i++)
	{
	sum=(sum%MOD+matrix_exponention(i)%MOD+MOD)%MOD;
	}
	return sum%MOD;
}

