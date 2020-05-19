#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string find_winner(int *arr,int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans^arr[i];
	}
	if(ans==0)
	{
		return "player 2";
	}
	return "player 1";
}

int main()
{
    int n;
    cout<<"Enter number of piles : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter stones of every piles : ";
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	cout<<"WInner is : ";
	cout<<find_winner(arr,n);
}
