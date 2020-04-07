/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/
#include<bits/stdc++.h>
using namespace std;
void update(long long int *lazy,long long int *tree,long long int start,long long int end,long long int tree_node,long long int left,long long int right,int value)
{
   if(start>end)
       return;
    if(lazy[tree_node]!=0)
    {
        tree[tree_node]+=(end-start+1)*lazy[tree_node];
        if(start!=end)
        {
            lazy[2*tree_node]+=lazy[tree_node];
            lazy[2*tree_node+1]+=lazy[tree_node];
        }
        lazy[tree_node]=0;
    }
    if(right<start || left>end)
    {
        return;
    }
    if(start>=left && end <=right)
    {
        tree[tree_node]+=(end-start+1)*value;
        if(start!=end)
        {
            lazy[tree_node*2]+=value;
            lazy[tree_node*2+1]+=value;
        }
        return;
	}
    long long int mid=start+(end-start)/2;
    update(lazy,tree,start,mid,tree_node*2,left,right,value);
    update(lazy,tree,mid+1,end,tree_node*2+1,left,right,value);
    tree[tree_node]=tree[tree_node*2]+tree[tree_node*2+1];
}




long long int query(long long int *lazy,long long int *tree,long long int start,long long int end,long long int tree_node,long long int left,long long int right)
{
    if(start>end)
        return 0;
    
    if(lazy[tree_node]!=0)
    {
        tree[tree_node]+=(end-start+1)*lazy[tree_node];
        if(start!=end)
        {
            lazy[2*tree_node]+=lazy[tree_node];
            lazy[2*tree_node+1]+=lazy[tree_node];
        }
        lazy[tree_node]=0;
    }
    if(right<start || left>end)
    {
        return 0;
    }
    if(start>=left && end<=right)
    {
        return tree[tree_node];
	}
    long long int mid=start+(end-start)/2;
    long long int ans1=query(lazy,tree,start,mid,tree_node*2,left,right);
    long long int ans2=query(lazy,tree,mid+1,end,tree_node*2+1,left,right);
    long long int final_ans=ans1+ans2;
    return final_ans;
}


int main() 
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,c;
        cin>>n>>c;
        long long int *tree=new long long int[4*n]();
        long long int *lazy=new long long int[4*n]();
        while(c--)
        {
            long long int check;
        
            cin>>check;
            if(check==0)
            {
                long long int p,q,v;
                cin>>p>>q>>v;
                update(lazy,tree,0,n-1,1,p-1,q-1,v);
            }
            else
            {
                long long int p,q;
                cin>>p>>q;
                long long ans=query(lazy,tree,0,n-1,1,p-1,q-1);
                cout<<ans<<endl;
            }
        }
        delete [] tree;
        delete [] lazy;
    }
}
