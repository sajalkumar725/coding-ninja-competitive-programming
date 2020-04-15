#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

void dfs(vector<int> arr[],int n,bool *visited,int src)
{
	visited[src]=true;
	cout<<src<<" ";
	for(int i=0;i<arr[src].size();i++)
	{
		if(!visited[arr[src][i]])
			dfs(arr,n,visited,arr[src][i]);
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> arr[n];
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[x].eb(y);
		arr[y].eb(x);
	}
	bool *visited=new bool[n]();
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			dfs(arr,n,visited,i);
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<arr[i].size();j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
}
