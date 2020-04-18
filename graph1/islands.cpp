/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/
#include<bits/stdc++.h>

vector<int> v;
vector<vector<int>> ans;
void dfs(int **graph,int n,bool *visited,int src)
{
    v.emplace_back(src);
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

void dfs_disconnected(int **graph,int n)
{
	bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
    	v.clear();
    	if(!visited[i])
    	{
    		dfs(graph,n,visited,i);
    		sort(v.begin(),v.end());
    		ans.emplace_back(v);
		}
	}
	delete [] visited;
}

int solve(int n,int m,vector<int>u,vector<int>z)
{
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x=u[i]-1;
        int y=z[i]-1;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    dfs_disconnected(graph,n);
    return ans.size();
}





