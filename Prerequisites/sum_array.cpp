/*
Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
Constraints:
1<=n<=100
Output:
Print a single integer denoting the sum.
Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45
*/

#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,n) for(i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main()
{
	crap;
	ll n,i,j,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
	cin>>n;
	int center = n/2;
	ll arr[n][n];
	f(i,n)
	{
		f(j,n)
		{
			cin>>arr[i][j];
		}
	}
	f(i,n)
	{
		sum1=sum1+arr[i][i];
		sum2=sum2+arr[i][n-i-1];
	}
	f(i,n)
	{
		f(j,n)
		{
			if(i==0 || j==0 || i==n-1 || j==n-1)
			{
				sum3=sum3+arr[i][j];
			}
		}
	}
	sum4=sum1+sum2-arr[0][0]-arr[0][n-1]-arr[n-1][0]-arr[n-1][n-1];
	if(n%2!=0)
	{
		sum4=sum4-arr[center][center];
	}
	sum5=sum4+sum3;
	cout<<sum5;
}
