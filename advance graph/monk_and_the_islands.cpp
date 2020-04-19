/*
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

int  bfs(vector<int> graph[],int n,int src)
{
    bool *visited=new bool[n]();
    int *temp=new int[n];
    visited[src]=true;
    temp[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it=graph[u].begin();it!=graph[u].end();it++)
        {
            if(!visited[*it])
            {
                q.push(*it);
                temp[*it]=temp[u]+1;
                visited[*it]=true;
            }
        }
    }
    return temp[n-1];
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> graph[n];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x-1].eb(y-1);
            graph[y-1].eb(x-1);
        }
        int result=bfs(graph,n,0);
        cout<<result<<endl;
    }
}
