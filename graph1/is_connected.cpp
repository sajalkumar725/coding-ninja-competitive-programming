/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <iostream>
using namespace std;

void dfs(int **graph,int n,bool *visited,int src)
{
    visited[src]=true;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && graph[src][i]==1)
        {
            dfs(graph,n,visited,i);
        }
    }
    return;
}

int is_connected(int **graph,int n,bool *visited)
{
    dfs(graph,n,visited,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            return 0;
        }
    }
    return 1;
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
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    int ans=is_connected(graph,n,visited);
    if(ans==1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
