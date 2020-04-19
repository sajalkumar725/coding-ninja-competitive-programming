/*
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO 
YES
*/
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define f(i,n) for(int i=0;i<n;i++)

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


string permutation(vector<int> *graph,int *p,int *q,int n)
{
    set<int> temp1;
    set<int> temp2;
    vector<vector<int>> output=connected_components(graph,n);
    for(int i=0;i<output.size();i++)
    {
        temp1.clear();
        temp2.clear();
        for(int j=0;j<output[i].size();j++)
        {
            temp1.insert(p[output[i][j]]);
            temp2.insert(q[output[i][j]]);
        }
        int len1=temp1.size();
        int len2=temp2.size();
        if(len1!=len2)
        {
            return "NO";
        }
        else
        {
            set<int>::iterator it2;
            it2=temp2.begin();
            for(auto it1=temp1.begin();it1!=temp1.end();it1++)
            {
                if((*it1)!=(*it2))
                {
                    return "NO";
                }
                it2++;
            }
        }
    }
    return "YES";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int *p=new int[n];
        int *q=new int[n];
        f(i,n)
        {
            cin>>p[i];
        }
        f(i,n)
        {
            cin>>q[i];
        }
        vector<int> *graph=new vector<int>[n];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a-1].eb(b-1);
            graph[b-1].eb(a-1);
        }
        string ans=permutation(graph,p,q,n);
        cout<<ans<<endl;
        delete [] p;
        delete [] q;
    }
	return 0;
}

