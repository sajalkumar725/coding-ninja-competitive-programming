                                               /*CONNECTED COMPONENTS*/
/*
input :
8 6
0 2
0 1
1 3
2 3
4 5
6 7
output:
0 2 3 1
4 5
6 7
*/




#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

void dfs(vector<int> *graph,int n,vector<int> &temp,bool *visited,int src)
{
	visited[src]=true;
	temp.eb(src);
	for(auto it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(!visited[*it])
		{
			dfs(graph,n,temp,visited,*it);
		}
	}
}

vector<vector<int>> connected_components(vector<int> *graph,int n)
{
	bool *visited=new bool[n]();
	vector<vector<int>> output;
	vector<int> temp;
	for(int i=0;i<n;i++)
	{
		temp.clear();
		if(!visited[i])
		{
			dfs(graph,n,temp,visited,i);
			output.eb(temp);
		}
	}
	return output;
}




int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> *graph=new vector<int>[n];
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].eb(y);
		graph[y].eb(x);
	}
	vector<vector<int>> ans=connected_components(graph,n);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
