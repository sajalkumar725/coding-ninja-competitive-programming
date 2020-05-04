/*
find solution of ax+by=gcd(a,b)
input: 
15 10
output:
gcd is : 5
 x is :1
y is -1
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//extended euclid algorithm
/*
if ax+by=gcd(a,b) then the x=y1 and y=x1-y1*floor(a/b) 
where x1 and y1 are bx1+(a%b)y1=gcd(b,a%b)
*/

typedef struct diophantine  // if ax+by=c and a,b=integers then the solution will exist if c % gcd(a,b)==0
{
	ll x;
	ll y;
	ll gcd;
}diophantine;

diophantine extended(ll a,ll b)
{
	if(b==0)
	{
		diophantine ans;
		ans.gcd=a;
		ans.x=1;
		ans.y=0;
		return ans;
	}
	diophantine small_ans=extended(b,a%b);
	diophantine ans;
	ans.gcd=small_ans.gcd;
	ans.x=small_ans.y;
	ans.y=small_ans.x-floor(a/b)*small_ans.y;
	return ans;
}

int main()
{
    fast;
    ll a,b;
    cin>>a>>b;
    diophantine triplet=extended(max(a,b),min(a,b));
    cout<<"gcd is : "<<triplet.gcd<<endl;
    cout<<" x is :"<<triplet.x<<endl;
    cout<<"y is "<<triplet.y<<endl;
}
