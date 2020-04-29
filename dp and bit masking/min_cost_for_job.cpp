/*
given a matrix of n persons and n jobs 
find way of giving n jobs to nperson at minimum cost.
input:
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
output: 
34
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min_cost(ll **arr,ll n,ll p,ll mask,ll *dp)
{
	ll minimum=INT_MAX;
	if(p>=n)
	{
		return 0;
	}
	if(dp[mask]!=INT_MAX)
	{
		return dp[mask];
	}
	for(ll i=0;i<n;i++)
	{
		if(!(mask&(1<<i)))
		{
			ll ans=min_cost(arr,n,p+1,(mask|(1<<i)),dp)+arr[p][i];
			minimum=min(ans,minimum);
		}
	}
	dp[mask]=minimum;
	return minimum;
}


int main()
{
	ll n;
	cin>>n;
	ll **arr=new ll*[n];
	for(ll i=0;i<n;i++)
	{
		arr[i]=new ll[n];
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	ll *dp=new ll[1<<n];
	for(ll i=0;i<(1<<n);i++)
	{
		dp[i]=INT_MAX;
	}
	cout<<min_cost(arr,n,0,0,dp)<<endl;
	delete [] dp;
	for(ll i=0;i<n;i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
}
