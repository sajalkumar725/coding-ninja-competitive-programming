/*
find maximum xor pair
input: 6 8 1 2 15 10 5
output: 15
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define crap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef struct trienode
{
	trienode *left;
	trienode *right;
}trienode;

void insert_trienode(trienode *head,ll value)
{
	trienode *curr=head;
	for(ll i=31;i>=0;i--)
	{
		ll b=(value>>i)&1;
		if(b==0)
		{
			if(!curr->left)
			{
				curr->left=new trienode();
			}
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				curr->right=new trienode();
			}
			curr=curr->right;
		}
	}
}

ll find_max_xor(trienode *head,ll *arr,ll n)
{
	ll max_xor=-1;
	for(ll i=0;i<n;i++)
	{
		ll curr_xor=0;
		ll value=arr[i];
		trienode *curr=head;
		for(ll j=31;j>=0;j--)
		{
			ll b=(value>>j)&1;
			if(b==0)
			{
				if(curr->right)
				{
					curr_xor=curr_xor+pow(2,j);
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
				}
			}
			else
			{
				if(curr->left)
				{
					curr_xor=curr_xor+pow(2,j);
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
		}
		max_xor=max(max_xor,curr_xor);
	}
	return max_xor;
}

int main()
{
	crap;
	ll n;
	cin>>n;
	ll *arr=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	trienode *head=new trienode();
	for(ll i=0;i<n;i++)
	{
		insert_trienode(head,arr[i]);
	}
	ll max_xor=find_max_xor(head,arr,n);
	cout<<max_xor<<endl;
	delete [] arr;
}
