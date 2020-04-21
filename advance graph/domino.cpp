/*
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/
#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
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
    output.clear();
	bool *visited=new bool[n]();
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs1(graph,n,visited,stk,i);
		}
	}
	//vector<int> *graphT=find_transpose(graph,n);
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
			dfs2(graph,n,visited,v,temp);
			output.eb(temp);
		}
	}
	return output;
}

int main()
{
	int t;
    cin>>t;
    while(t--)
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
        /*for(int i=0;i<output.size();i++)
        {
            for(auto it=output[i].begin();it!=output[i].end();it++)
            {
                cout<<(*it)+1<<" ";
            }
            cout<<endl;
        }*/
        cout<<output.size()<<endl;
    }
    return 0;
}
