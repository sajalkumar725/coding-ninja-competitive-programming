/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2
*/
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

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

vector<int> bottom(vector<int> *graph,int n)
{
	vector<vector<int>> output=strongly_connected_components(graph,n);
    vector<int> result;
    bool check;
    for(int i=0;i<output.size();i++)
    {
        check=true;
        for(auto it : output[i])
        {
        	for(int j = 0; j < graph[it].size(); j++)
        	{
        		if(find(output[i].begin(),output[i].end(),graph[it][j])==output[i].end())
        		{
        			check=false;
        			break;
				}
			}
			if(!check)
			{
				break;
			}
		}
		if(check)
		{
			for(auto it : output[i])
			{
				result.eb(it);
			}
		}
    }
    return result;
}

int main()
{
    int n,e;
    while(true)
    {
        cin>>n;
        if(n==0)
        {
            break;
        }
        cin>>e;
        vector<int> *graph=new vector<int>[n];
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x-1].eb(y-1);
        }
        vector<int> result=bottom(graph,n);
        sort(result.begin(),result.end());
        for(auto it=result.begin();it!=result.end();it++)
        {
            cout<<(*it)+1<<" ";
        }
        cout<<endl;
        result.clear();
    }
	return 0;
}
