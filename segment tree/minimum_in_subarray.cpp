/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;

void build_tree(int *arr,int *tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		tree[tree_node]=arr[start];
		return;
	}
	int mid=start+(end-start)/2;
	build_tree(arr,tree,start,mid,tree_node*2);
	build_tree(arr,tree,mid+1,end,tree_node*2+1);
	tree[tree_node]=min(tree[tree_node*2],tree[tree_node*2+1]);
}

void update(int *arr,int *tree,int start,int end,int tree_node,int idx,int value)
{
    if(start==end)
    {
        arr[idx]=value;
        tree[tree_node]=value;
        return;
    }
    int mid=start+(end-start)/2;
    if(idx>mid)
        update(arr,tree,mid+1,end,tree_node*2+1,idx,value);
    else
        update(arr,tree,start,mid,tree_node*2,idx,value);
    tree[tree_node]=min(tree[tree_node*2],tree[tree_node*2+1]);
}

int query(int *tree,int start,int end,int tree_node,int left,int right)
{
    if(start>right || end <left)
    {
        return INT_MAX;
	}
    if(start>=left && end<=right)
    {
        return tree[tree_node];
    }
    int mid=start+(end-start)/2;
    int ans1=query(tree,start,mid,tree_node*2,left,right);
    int ans2=query(tree,mid+1,end,tree_node*2+1,left,right);
    return min(ans1,ans2);
}


int main() 
{
    int n,Q;
    cin>>n>>Q;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
		cin>>arr[i];
    int *tree=new int[4*n];
    build_tree(arr,tree,0,n-1,1);
    char c;
    int l,r;
    while(Q--)
    {
        cin>>c>>l>>r;
        if(c=='q')
        {
            int ans=query(tree,0,n-1,1,l-1,r-1);
            cout<<ans<<endl;
		}
        if(c=='u')
        {
            update(arr,tree,0,n-1,1,l-1,r);
        }
    }
}
