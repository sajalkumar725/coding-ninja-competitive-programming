/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    long int max_sum=INT_MIN;
    long int sum=0;
    long int best_prefix_sum=INT_MIN;
    long int best_sufix_sum=INT_MIN;
}node;

void build_tree(int *arr,node *tree,int start,int end,int tree_node)
{
    if(start==end)
    {
        tree[tree_node].sum=arr[start];
        tree[tree_node].max_sum=arr[start];
        tree[tree_node].best_prefix_sum=arr[start];
        tree[tree_node].best_sufix_sum=arr[start];
        return;    
	}
	int mid=start+(end-start)/2;
	build_tree(arr,tree,start,mid,tree_node*2);
	build_tree(arr,tree,mid+1,end,tree_node*2+1);
	node left=tree[tree_node*2];
	node right=tree[tree_node*2+1];
	tree[tree_node].sum=left.sum+right.sum;
	tree[tree_node].best_prefix_sum=max(left.best_prefix_sum,left.sum+right.best_prefix_sum);
	tree[tree_node].best_sufix_sum=max(right.best_sufix_sum,right.sum+left.best_sufix_sum);
	tree[tree_node].max_sum=max(left.max_sum,max(right.max_sum,max(left.sum+right.best_prefix_sum,max(right.sum+left.best_sufix_sum,left.best_sufix_sum+right.best_prefix_sum))));
	return;
}

node query(node *tree,int start,int end,int tree_node,int l,int r)
{
	if(start>r || end<l)
	{
		node null_node;
		return null_node;
	}
	if(start>=l && end<=r)
	{
		return tree[tree_node];
	}
	int mid=start+(end-start)/2;
	node left=query(tree,start,mid,tree_node*2,l,r);
	node right=query(tree,mid+1,end,tree_node*2+1,l,r);
	node ans;
	ans.sum=left.sum+right.sum;
	ans.best_prefix_sum=max(left.best_prefix_sum,left.sum+right.best_prefix_sum);
	ans.best_sufix_sum=max(right.best_sufix_sum,right.sum+left.best_sufix_sum);
	ans.max_sum=max(left.max_sum,max(right.max_sum,max(left.sum+right.best_prefix_sum,max(right.sum+left.best_sufix_sum,left.best_sufix_sum+right.best_prefix_sum))));
	return ans;
}

int main() 
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node *tree=new node[4*n];
    build_tree(arr,tree,0,n-1,1);
    /*for(int i=1;i<2*n;i++)
    {
    	cout<<tree[i].sum<<" "<<tree[i].max_sum<<" "<<tree[i].best_prefix_sum<<" "<<tree[i].best_sufix_sum<<endl;
	}*/
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        node ans=query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.max_sum<<endl;
    }
    return 0;
}
