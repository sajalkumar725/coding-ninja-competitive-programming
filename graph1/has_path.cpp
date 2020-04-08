/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll has_path(ll **graph,ll n,bool *visited,ll a,ll b)
{
    if(a==b)
    {
        return 1;
    }
    int ans=0;
    if(graph[a][b]==1 )
    {
        return 1;
    }
    for(ll i=0;i<n;i++)
    {
        if(!visited[i] && graph[a][i]==1)
        {
            visited[i]=true;
            ans=has_path(graph,n,visited,i,b);
            if(ans==1)
                return 1;
        }
    }
    return ans;
}

int main() {
    ll n,e;
    cin>>n>>e;
    ll a,b;
    ll **graph=new ll*[n];
    for(ll i=0;i<n;i++)
    {
        graph[i]=new ll[n];
        for(ll j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    for(ll i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    // SASTA DFS
    bool *visited=new bool[n];
    for(ll i=0;i<n;i++)
    {
        visited[i]=false;
    }
    cin>>a>>b;
    ll ans=has_path(graph,n,visited,a,b);
    if(ans==1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
  return 0;
}
