/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <bits/stdc++.h>
using namespace std;

int get_min_vertex(bool *visited,int *distance,int n)
{
    int min_index=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (min_index==-1 || distance[min_index]>distance[i]))
            min_index=i;
    }
    return min_index;
}

void dijkstra(int **graph,bool *visited,int *parent,int *distance,int n,int src)
{
    distance[src]=0;
    parent[src]=-1;
    for(int i=0;i<n-1;i++)
    {
        int min_vertex=get_min_vertex(visited,distance,n);
        visited[min_vertex]=true;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && graph[min_vertex][j]!=0)
            {
                if(distance[j]>graph[min_vertex][j]+distance[min_vertex])
                {
                    distance[j]=graph[min_vertex][j]+distance[min_vertex];
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
    int *distance=new int[n];
    for(int i=1;i<n;i++)
    {
        visited[i]=false;
        //parent[i]=-1;
        distance[i]=INT_MAX;
    }
    dijkstra(graph,visited,parent,distance,n,0);
    cout<<"0"<<" "<<"0"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    return 0;
}
