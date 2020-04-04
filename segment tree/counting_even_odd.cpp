/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    long int even_count=0;
    long int odd_count=0;
}node;

void build_tree(int *arr,node *tree,int start,int end,int tree_node)
{
    if(start==end)
    {
        if(arr[start]%2==0)
        {
            tree[tree_node].even_count=1;
            tree[tree_node].odd_count=0;
        }
        else
        {
        	tree[tree_node].even_count=0;
            tree[tree_node].odd_count=1;
		}
		return;
    }
    int mid=start+(end-start)/2;
    build_tree(arr,tree,start,mid,tree_node*2);
    build_tree(arr,tree,mid+1,end,tree_node*2+1);
    node left=tree[tree_node*2];
    node right=tree[tree_node*2+1];
    tree[tree_node].even_count=left.even_count+right.even_count;
    tree[tree_node].odd_count=left.odd_count+right.odd_count;
    return;
}

void update(int *arr,node *tree,int start,int end,int tree_node,int idx,int value)
{
	if(start==end)
	{
		arr[idx]=value;
		if(value%2==0)
		{
			tree[tree_node].even_count=1;
			tree[tree_node].odd_count=0;
		}
		else
		{
			tree[tree_node].even_count=0;
			tree[tree_node].odd_count=1;
		}
		return;
	}
	int mid=start+(end-start)/2;
	if(idx<=mid)
		update(arr,tree,start,mid,tree_node*2,idx,value);
	else	
		update(arr,tree,mid+1,end,tree_node*2+1,idx,value);
	node left=tree[tree_node*2];
	node right=tree[tree_node*2+1];
	tree[tree_node].even_count=left.even_count+right.even_count;
    tree[tree_node].odd_count=left.odd_count+right.odd_count;
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
	ans.even_count=left.even_count+right.even_count;
	ans.odd_count=left.odd_count+right.odd_count;
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
    int Q;
    cin>>Q;
    while(Q--)
    {
        int check,x,y;
        cin>>check>>x>>y;
        if(check==0)
        {
            //update
            update(arr,tree,0,n-1,1,x-1,y);
        }
        else if(check==1)
        {
            //count even
            node ans=query(tree,0,n-1,1,x-1,y-1);
            cout<<ans.even_count<<endl;
        }
        else
        {
            //count_odd
            node ans=query(tree,0,n-1,1,x-1,y-1);
            cout<<ans.odd_count<<endl;
        }
    }
    return 0;
}
