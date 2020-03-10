/*
Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6 
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4
*/

#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,n) for(i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main()
{
	crap;
	ll n,i,sum1=0,sum2=0;
	cin>>n;
	ll arr[n];
	f(i,n)
	{
		cin>>arr[i];
	}
	f(i,n)
	{
		if(i%2==0 && arr[i]%2==0)
		{
			sum1=sum1+arr[i];
		}
		else if(i%2!=0 && arr[i]%2!=0)
		{
			sum2=sum2+arr[i];
		}
		else
			continue;
	}
	cout<<sum1<<" "<<sum2;
    return 0;
}
