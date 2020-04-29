/*
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

ll min_cost(ll **arr,ll n)
{
	ll *dp=new ll[1<<n];
	//fill_n(arr,(1<<n),INT_MAX);
	for(ll i=0;i<(1<<n);i++)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	ll minimum=INT_MAX;
	for(int mask=0;mask<(1<<n)-1;mask++)
	{
		ll temp=mask;
		ll k=0;
		//count number of set bits for finding the person whom we are assigning job 
		while(temp>0)
		{
			if(temp%2==1)
				k++;
			temp=temp/2;
		}
		for(ll j=0;j<n;j++)
		{
			if(!(mask&(1<<j)))
			{
				dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+arr[k][j]);
			}
		}
	}
	return dp[(1<<n)-1];
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
	cout<<min_cost(arr,n);
	for(ll i=0;i<n;i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
}
