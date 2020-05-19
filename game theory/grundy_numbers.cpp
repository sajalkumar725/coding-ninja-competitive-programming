/*
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calculate_mex(set<ll> s)
{
    ll count=0;
    set<ll>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        if((*it)==count)
        {
            count++;
        }
        else
            break;
    }
    return count;
}

ll grundy(ll n)
{
    if(n==0)
        return 0;
    set<ll> s;
    s.insert(grundy(n/2));
    s.insert(grundy(n/3));
    s.insert(grundy(n/6));
	  ll ans=calculate_mex(s);
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    cout<<grundy(n);
}
