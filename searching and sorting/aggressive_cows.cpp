/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
typedef long long ll;
bool check(ll cows,ll arr[],ll n,ll d)
{
    ll count=1,i;
    ll last=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]-last>=d)
        {
            count++;
            last=arr[i];
        }
        if(count==cows)
            return true;
    }
    return false;
}
int main() {
    ll t,i,n,cows,ans=-1,d,mid;
    cin>>t;
    while(t--)
    {
        cin>>n>>cows;
        ll arr[n];
        f(i,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll start=arr[0];
        ll end = arr[n-1]-arr[0];
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(check(cows,arr,n,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
