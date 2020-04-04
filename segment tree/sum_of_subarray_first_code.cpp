/*
find sum of the subarray from a given array.
build tree
update array
find queries
*/
#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

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
	tree[tree_node]=tree[tree_node*2]+tree[tree_node*2+1];
}

int query(int *tree, int start,int end,int tree_node,int left,int right)
{
	if(start>right || end<left)
	{
		return 0;
	}
	if(start>=left && end<=right)
	{
		return tree[tree_node];
	}
	int mid=start+(end-start)/2;
	int ans1=query(tree,start,mid,tree_node*2,left,right);
	int ans2=query(tree,mid+1,end,tree_node*2+1,left,right);
	return ans1+ans2;
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
	{
		update(arr,tree,mid+1,end,tree_node*2+1,idx,value);
	}
	else
	{
		update(arr,tree,start,mid,tree_node*2,idx,value);
	}
	tree[tree_node]=tree[tree_node*2]+tree[tree_node*2+1];
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	cout<<"Enter array elements : ";
	int *arr=new int[n];
	f(i,n)
		cin>>arr[i];
	int *tree=new int[2*n];
	build_tree(arr,tree,0,n-1,1);
	cout<<"Build Tree is : "<<endl;
	for(int i=1;i<2*n;i++)
		cout<<tree[i]<<endl;
	cout<<"Enter index and value to change : ";
	int idx,value;
	cin>>idx>>value;
	update(arr,tree,0,n-1,1,idx,value);
	cout<<"Tree after update : "<<endl;
	for(int i=1;i<2*n;i++)
		cout<<tree[i]<<endl;
	cout<<"Enter subarray range : ";
	int left,right;
	cin>>left>>right;
	cout<<"sum of the subarray is : "<<endl;
	int ans=query(tree,0,n-1,1,left,right);
	cout<<ans<<endl;
	return 0;
}
