
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define pb push
#define mp make_pair
typedef pair<int,int> ipair;

void prims(vector<pair<int,int>> arr[],bool *visited,int *parent,int *weight,int n,int src)
{
	weight[src]=0;
	parent[src]=-1;
	priority_queue<ipair,vector <ipair>,greater<ipair>> pq;
	pq.pb(mp(weight[src],src));
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		visited[u]=true;
		for(auto i=arr[u].begin();i<arr[u].end();i++)
		{
			int v=(*i).first;
			int key=(*i).second;
			if(!visited[v] && key<weight[v])
			{
				weight[v]=key;
				parent[v]=u;
				pq.pb(mp(weight[v],v));
			}
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	vector<pair<int,int>> arr[n];
	for(int i=0;i<e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		arr[x].eb(mp(y,w));
		arr[y].eb(mp(x,w));
	}
	bool *visited=new bool[n]();
	int *parent=new int[n];
	int *weight=new int[n];
	for(int i=0;i<n;i++)
	{
		weight[i]=INT_MAX;
	}
	prims(arr,visited,parent,weight,n,0);
	for(int i=1;i<n;i++)
	{
		if(i<parent[i])
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		else
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
	}
}
