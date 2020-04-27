/*
find sum of subarray of given range
input: 
8
1 2 3 4 5 6 7 8
2 6
output:
20
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void update(ll *bit,ll index,ll n,ll value)
{
	for(;index<n+1;index+=index&(-index))
	{
		bit[index]+=value;
	}
}

ll query(ll index,ll *bit)
{
	ll sum=0;
	for(;index>0;index-=index&(-index))
	{
		sum+=bit[index];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	ll *arr=new ll[n+1]();
	ll *bit=new ll[n+1]();
	for(ll i=1;i<n+1;i++)
	{
		cin>>arr[i];
		update(bit,i,n,arr[i]);
	}
	cout<<"range: "<<endl;
	ll l,r;
	cin>>l>>r;
	cout<<query(r,bit)-query(l-1,bit)<<endl;
}
