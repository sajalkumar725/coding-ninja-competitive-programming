/*
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.
Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.
Output Format:
For each test case, print the answer in a separate line.
Constraints:
1 ≤T≤ 10^5

1 ≤ a < b ≤ 10^9

0≤d≤10^9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.
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

// diaphantine : if ax+by=c and a,b=integers then the solution will exist if c % gcd(a,b)==0
typedef struct triplet
{
    ll x;
    ll y;
    ll gcd;
}triplet;

triplet extended_euclid_algo(ll a,ll b)
{
    if(b==0)
    {
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet small=extended_euclid_algo(b,a%b);
    triplet ans;
    ans.gcd=small.gcd;
    ans.x=small.y;
    ans.y=(small.x-(a/b)*(small.y));
    return ans;
}


ll multiplicative_modulo_inverse(ll a,ll m)
{
    triplet temp=extended_euclid_algo(a,m);
    ll ans=temp.x;
    return (ans%m+m)%m;  //if ans is negative
}


ll sachin_varun(ll a,ll b, ll d)
{
    ll x=__gcd(max(a,b),min(a,b));
    if(d%x!=0)
    {
        return 0;
    }
    if(d==0)
    {
        return 1;
    }
    a=a/x;
    b=b/x;
    d=d/x;
    ll y1=((d%a)*(multiplicative_modulo_inverse(b,a)))%a;
    if(d<y1*b)
    {
        return 0;
    }
    ll n=((d/b)-y1)/a;
    return n+1;
}

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        cout<<sachin_varun(a,b,d)<<endl;
    }
    return 0;
}
