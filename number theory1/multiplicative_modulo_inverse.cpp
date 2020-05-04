/*
find multiplicative modulo inverse which is b in expression (a.b)%m=1
input:
(a and m)
5 17
output:
7
input:
5 12
output:
5
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

diophantine multiplicative_modulo_inverse(ll a,ll m)
{
	 diophantine triplet=extended(a,m);
	 return triplet;
}

int main()
{
    fast;
    ll a,m;
    cin>>a>>m;
    diophantine triplet=multiplicative_modulo_inverse(a,m);
    cout<<"Modulo inverse is : "<<triplet.x<<endl;
    
}
