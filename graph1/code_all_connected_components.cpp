/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/
#include <bits/stdc++.h>
using namespace std;
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
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
	dfs_disconnected(graph,n);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
    
}
