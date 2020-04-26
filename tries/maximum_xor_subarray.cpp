/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct trienode
{
    ll value=0;
    trienode *left;
    trienode *right;
}trienode;

void insert(trienode *head,ll pre_xor)
{
    trienode *curr=head;
    for(ll i=31;i>=0;i--)
    {
        ll b=(pre_xor>>i)&1;
        if(b==0)
        {
            if(!curr->left)
            {
                curr->left=new trienode();
                curr->left->value=pre_xor;
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right=new trienode();
                curr->right->value=pre_xor;
            }
            curr=curr->right;
        }
    }
}

ll query(trienode *head,ll pre_xor)
{
    trienode *curr=head;
    ll value=0;
    for(ll i=31;i>=0;i--)
    {
        ll b=(pre_xor>>i)&1;
        if(b==0)
        {
            if(curr->right)
                curr=curr->right;
            else
                curr=curr->left;
        }
        else
        {
            if(curr->left)
                curr=curr->left;
            else
                curr=curr->right;
        }
    }
    return pre_xor^curr->value;
}

ll max_xor(ll *arr,ll n)
{
    ll pre_xor=0;
    ll result=INT_MIN;
    trienode *head=new trienode();
    for(ll i=0;i<n;i++)
    {
        pre_xor=pre_xor^arr[i];
        insert(head,pre_xor);
        result=max(result,query(head,pre_xor));
    }
    return result;
}
int main()
{
	ll n;
	cin>>n;
	ll *arr=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<max_xor(arr,n)<<endl;
}
