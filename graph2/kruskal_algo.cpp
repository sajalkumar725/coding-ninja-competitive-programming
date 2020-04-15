/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int v1,v2,w;
}node;



bool compare(node a,node b)
{
    return a.w<b.w;
}


int union_find_helper(int *parent,int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	return union_find_helper(parent,parent[x]);
}


bool union_find(int *parent,int v1,int v2)
{
	int x=union_find_helper(parent,v1);
	int y=union_find_helper(parent,v2);
	if(x!=y)
	{
		parent[x]=y;
        return 1;
	}
	return 0;
}



int is_cycle(int* parent,int v1,int v2)
{
	if(parent[v1]==parent[v2])
	{
		return 0;
	}
	if(union_find(parent,v1,v2))
        return 1;
	return 0;
}



node *kruskal(node *edge,int n,int e)
{
    sort(edge,edge+e,compare);
    node *result=new node[n-1];
    int m=0;
    int count=0;
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
    	parent[i]=i;
	}
    while(count<n-1)
    {
    	int check=is_cycle(parent,edge[m].v1,edge[m].v2);
    	if(check==1)
    	{
    		result[count].v1=edge[m].v1;
			result[count].v2=edge[m].v2;
			result[count].w=edge[m].w;
			count++;
		}
		m++;
	}
    /*for(int i=0;i<n-1;i++)
    {
    	result[i].v1=edge[i].v1;
    	result[i].v2=edge[i].v2;
    	result[i].w=edge[i].w;
	}*/
	return result;
}

int main()
{
    int n,e;
    cin>>n>>e;
    node *edge=new node[e];
    for(int i=0;i<e;i++)
    {
        cin>>edge[i].v1>>edge[i].v2>>edge[i].w;
    }
    node *result=new node[n-1];
    result=kruskal(edge,n,e);
    for(int i=0;i<n-1;i++)
    {
        if(result[i].v1>result[i].v2)
            cout<<result[i].v2<<" "<<result[i].v1<<" "<<result[i].w<<endl;
        else
            cout<<result[i].v1<<" "<<result[i].v2<<" "<<result[i].w<<endl;
    }
    return 0;
}


