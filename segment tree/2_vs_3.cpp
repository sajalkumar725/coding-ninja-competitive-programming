/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;
#define maximum 100000
int power[maximum];

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
    tree[tree_node]=(tree[tree_node*2+1]+(power[end-mid]*tree[tree_node*2]))%3;
    return;
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
    if(idx<=mid)
    	update(arr,tree,start,mid,tree_node*2,idx,value);
    else
    	update(arr,tree,mid+1,end,tree_node*2+1,idx,value);
    tree[tree_node]=(tree[tree_node*2+1]+(power[end-mid]*tree[tree_node*2]))%3;
    return;
}

int query(int *tree,int start,int end,int tree_node,int l,int r)
{
    if(start>r || end<l)
    {
        return 0;
    }
    if(start>=l && end<=r)
    {
        return (tree[tree_node]*power[r-end])%3;
    }
    int mid=start+(end-start)/2;
    int left=query(tree,start,mid,tree_node*2,l,r);
    int right=query(tree,mid+1,end,tree_node*2+1,l,r);
    int ans;
    ans=(left+right);
    return ans%3;
}

int main() 
{
    int n;
    cin>>n;
    string str;
    getline(cin>>ws,str);
    power[0]=1;
    for(int i=1;i<maximum;i++)
    {
        power[i]=(power[i-1]*2)%3;
    }
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=str[i]-'0';
    }
    int *tree=new int[4*n];
    build_tree(arr,tree,0,n-1,1);
    /*for(int i=1;i<2*n;i++)
    {
    	cout<<tree[i]<<endl;
	}*/
    int Q;
    cin>>Q;
    while(Q--)
    {
        int q,l,r,idx;
        cin>>q;
        if(q==0)
        {
            //int l,r;
            cin>>l>>r;
            int ans=query(tree,0,n-1,1,l,r);
            cout<<ans<<endl;
        }
        if(q==1)
        {
            //int idx;
            cin>>idx;
            if(str[idx]=='0');
            {
                update(arr,tree,0,n-1,1,idx,1);
            }
        }
    }
    return 0;
}
