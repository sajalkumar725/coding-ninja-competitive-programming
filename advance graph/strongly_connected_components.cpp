#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
/*
sample test case1
5 5
1 0
0 3
3 4
2 1
0 2
sample test case2
11 13
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
7 8
8 9
9 10
10 8
10 11
*/
vector<int> *find_transpose(vector<int> *graph,int n)
{
	vector<int> *graphT=new vector<int>[n];
	for(int i=0;i<n;i++)
	{
		for(auto it=graph[i].begin();it!=graph[i].end();it++)
		{
			graphT[*it].eb(i);
		}
	}
	return graphT;
}

void dfs1(vector<int> *graph,int n,bool *visited,stack<int> &stk,int src)
{
	visited[src]=true;
	for(auto it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(!visited[*it])
		{
			dfs1(graph,n,visited,stk,*it);
		}
	}
	stk.push(src);
}

void dfs2(vector<int> *graph,int n,bool *visited,int src,vector<int> &temp)
{
	visited[src]=true;
	temp.eb(src);
	for(auto it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(!visited[*it])
			dfs2(graph,n,visited,*it,temp);
	}
}

vector<vector<int>> strongly_connected_components(vector<int> *graph,int n)
{
	vector<vector<int>> output;
	vector<int> temp;
	stack<int> stk;
	bool *visited=new bool[n]();
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs1(graph,n,visited,stk,i);
		}
	}
	vector<int> *graphT=find_transpose(graph,n);
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	while(!stk.empty())
	{
		int v=stk.top();
		stk.pop();
		temp.clear();
		if(!visited[v])
		{
			dfs2(graphT,n,visited,v,temp);
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
		graph[x-1].eb(y-1);
	}
	vector<vector<int>> output=strongly_connected_components(graph,n);
	for(int i=0;i<output.size();i++)
	{
		for(auto it=output[i].begin();it!=output[i].end();it++)
		{
			cout<<(*it)+1<<" ";
		}
		cout<<endl;
	}
}
