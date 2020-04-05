/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/
#include<bits/stdc++.h>
using namespace std;

void build_tree(int *a,int *b,int *tree,int start,int end,int tree_node)
{
    if(start==end)
    {
        tree[tree_node]=start;
        return;
    }
    int mid=start+(end-start)/2;
    build_tree(a,b,tree,start,mid,tree_node*2);
    build_tree(a,b,tree,mid+1,end,tree_node*2+1);
    int left=tree[tree_node*2];
    int right=tree[tree_node*2+1];
    if(a[left]>a[right])
    {
        tree[tree_node]=left;
	}
    else if(a[left]<a[right])
    {
        tree[tree_node]=right;
    }
    else
    {
        if(b[left]>b[right])
        {
            tree[tree_node]=right;
        }
        else if(b[left]<b[right])
        {
            tree[tree_node]=left;
        }
        else
        {
            tree[tree_node]=min(left,right);
        }
    }
    return;
}

int query(int *a,int *b,int *tree,int start,int end,int tree_node,int l,int r)
{
	if(start>r || l>end)
	{
		return l;
	}
	if(start>=l && end<=r)
	{
		return tree[tree_node];
	}
	int mid=start+(end-start)/2;
	int left=query(a,b,tree,start,mid,tree_node*2,l,r);
	int right=query(a,b,tree,mid+1,end,tree_node*2+1,l,r);
	int ans;
	if(a[left]>a[right])
    {
        ans=left;
	}
    else if(a[left]<a[right])
    {
        ans=right;
    }
    else
    {
        if(b[left]>b[right])
        {
            ans=right;
        }
        else if(b[left]<b[right])
        {
            ans=left;
        }
        else
        {
            ans=min(left,right);
        }
    }
    return ans;
}

int main() 
{
    int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int *tree=new int[4*n];
    build_tree(a,b,tree,0,n-1,1);
    /*for(int i=1;i<2*n;i++)
    	cout<<tree[i]+1<<endl;*/
    int q;
    cin>>q;
    while(q--)
    {
    	int l,r;
    	cin>>l>>r;
    	int ans=query(a,b,tree,0,n-1,1,l-1,r-1)+1;
    	cout<<ans<<endl;
	}
	return 0;
}
