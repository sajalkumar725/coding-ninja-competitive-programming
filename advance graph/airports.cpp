/*
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
#define mp make_pair

typedef struct node
{
    ll v1,v2,w;
}node;

bool compare(node a,node b)
{
	return a.w<b.w;
}

ll union_find_helper(ll *parent, ll x)
{
	if(parent[x]==x)
	{
		return x;
	}
	return union_find_helper(parent,parent[x]);
}

bool union_find(ll *parent,ll v1,ll v2)
{
	ll x=union_find_helper(parent,v1);
	ll y=union_find_helper(parent,v2);
	if(x!=y)
	{
		parent[x]=y;
		return 1;
	}
	return 0;
}

pair<ll,ll> airports(node *edges,ll n,ll e,ll airport_cost)
{
	pair<ll,ll> result;
	ll count=0;
	ll total_cost=0;
	ll j=0;
	ll *parent=new ll[n+1];
	for(ll i=0;i<n+1;i++)
	{
		parent[i]=i;
	}
	sort(edges,edges+e,compare);
	for(ll i=0;i<e;i++)
	{
		if(edges[i].w<airport_cost && union_find(parent,edges[i].v1,edges[i].v2))
		{
			total_cost=total_cost+edges[i].w;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(parent[i]==i)
            (count)++;
    }
	total_cost=total_cost+count*airport_cost;
	result.first=total_cost;
	result.second=count;
	delete [] parent;
	return result;
}

int main()
{
    ll t,k=1;
    cin>>t;
    while(t--)
    {
        ll n,m,a;
        cin>>n>>m>>a;
        node *edges=new node[m];
        for(ll i=0;i<m;i++)
        {
            cin>>edges[i].v1>>edges[i].v2>>edges[i].w;
        }
        pair<ll,ll> ans=airports(edges,n,m,a);
        cout<<"Case #"<<k<<": "<<ans.first<<" "<<ans.second<<endl;
        k++;
        delete [] edges;
    }
    return 0;
}
