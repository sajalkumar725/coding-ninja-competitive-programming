/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int max1,sec_max;
}node;
//build tree
void build_tree(int *arr,node *tree,int start,int end,int tree_node)
{
    if(start==end)
    {
        tree[tree_node].max1=arr[start];
        tree[tree_node].sec_max=INT_MIN;
        return;
    }
    int mid=start+(end-start)/2;
    build_tree(arr,tree,start,mid,tree_node*2);
    build_tree(arr,tree,mid+1,end,tree_node*2+1);
    tree[tree_node].max1=max(tree[tree_node*2].max1,tree[tree_node*2+1].max1);
    tree[tree_node].sec_max=min(max(tree[tree_node*2].max1,tree[tree_node*2+1].sec_max),max(tree[tree_node*2].sec_max,tree[tree_node*2+1].max1));
}
//update tree
void update(int *arr,node *tree,int start,int end,int tree_node,int idx,int value)
{
	if(start==end)
	{
		arr[idx]=value;
		tree[tree_node].max1=value;
		tree[tree_node].sec_max=INT_MIN;
		return;
	}
	int mid=start+(end-start)/2;
	if(idx>mid)
		update(arr,tree,mid+1,end,tree_node*2+1,idx,value);
	else
		update(arr,tree,start,mid,tree_node*2,idx,value);
	tree[tree_node].max1=max(tree[tree_node*2].max1,tree[tree_node*2+1].max1);
    tree[tree_node].sec_max=min(max(tree[tree_node*2].max1,tree[tree_node*2+1].sec_max),max(tree[tree_node*2].sec_max,tree[tree_node*2+1].max1));
	return;
}
//find queries
node query(node *tree,int start,int end,int tree_node,int left,int right)
{
	if(start>right || end<left)
	{
		node temp;
		temp.max1=INT_MIN;
		temp.sec_max=INT_MIN;
		return temp;
	}
	if(start>=left && end<=right)
	{
		return tree[tree_node];
	}
	int mid=start+(end-start)/2;
	node ans1=query(tree,start,mid,tree_node*2,left,right);
	node ans2=query(tree,mid+1,end,tree_node*2+1,left,right);
	node ans3;
	ans3.max1=max(ans1.max1,ans2.max1);
	ans3.sec_max=min(max(ans1.max1,ans2.sec_max),max(ans1.sec_max,ans2.max1));
	return ans3;
}

int main() 
{
    int n,Q;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
		cin>>arr[i];
    cin>>Q;
    node *tree=new node[4*n];
    build_tree(arr,tree,0,n-1,1);
    char c;
    int l,r;
    while(Q--)
    {
        cin>>c>>l>>r;
        if(c=='Q')
        {
            node ans=query(tree,0,n-1,1,l-1,r-1);
            cout<<ans.max1+ans.sec_max<<endl;
		}
        if(c=='U')
        {
            update(arr,tree,0,n-1,1,l-1,r);
        }
    }
    /*for(int i=1;i<2*n;i++)
    	cout<<tree[i].max1<<" "<<tree[i].sec_max<<endl;*/
    return 0;
}
