/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
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
0 1 3
1 2 1
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

int get_min_vertex(bool *visited,int *weight,int n)
{
    int min_index=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (min_index==-1 || weight[min_index]>weight[i]))
            min_index=i;
    }
    return min_index;
}

void prims(int **graph,bool *visited,int *parent,int *weight,int n,int src)
{
    weight[src]=0;
    parent[src]=-1;
    for(int i=0;i<n-1;i++)
    {
        int min_vertex=get_min_vertex(visited,weight,n);
        visited[min_vertex]=true;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && graph[min_vertex][j]!=0)
            {
                if(weight[j]>graph[min_vertex][j])
                {
                    weight[j]=graph[min_vertex][j];
                    parent[j]=min_vertex;
                }
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)
            graph[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y]=w;
        graph[y][x]=w;
    }
    bool *visited=new bool[n];
    int *parent=new int[n];
    int *weight=new int[n];
    for(int i=1;i<n;i++)
    {
        visited[i]=false;
        //parent[i]=-1;
        weight[i]=INT_MAX;
    }
    prims(graph,visited,parent,weight,n,0);
    for(int i=1;i<n;i++)
    {
        if(i<parent[i])
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else
        {
        	cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
    return 0;
}
