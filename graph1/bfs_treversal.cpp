/*
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs_helper(ll **graph,ll n,bool *visited,ll source)
{
    visited[source]=true;
    queue<ll> q;
    q.push(source);
    while(!q.empty())
    {
        ll s=q.front();
        cout<<s<<" ";
        q.pop();
        for(ll i=0;i<n;i++)
        {
            if(!visited[i] && graph[s][i]==1)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return;
}

void bfs(ll **graph,ll n)
{
    bool *visited=new bool[n];
    for(ll i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs_helper(graph,n,visited,i);
        }
    }
    delete [] visited;
    return;
}

int main() 
{
    ll n, E;
    cin >> n >> E;
    //ll n=V;
    ll **graph=new ll*[n];
    for(ll i=0;i<n;i++)
    {
        graph[i]=new ll[n];
        for(ll j=0;j<n;j++)
            graph[i][j]=0;
    }
    for(ll i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    
    bfs(graph,n);
    for(int i=0;i<n;i++)
        delete [] graph[i];
    delete [] graph;
  	return 0;
}
