/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct wjs
{
    ll start;
    ll finish;
    ll profit;
}wjs;

bool compare(wjs a,wjs b)
{
    return a.finish<b.finish;
}

ll search(wjs *job,ll element,ll first,ll last)
{
    if(first>last)
        return -1;
    if(first==last)
    {
        if(job[first].finish<=element)
            return first;
        else
            return -1;
    }
    ll mid=(first+last)/2;
    if(job[mid].finish<=element)
    {
        ll ans=search(job,element,mid+1,last);
        if(ans==-1)
            return mid;
        else
            return ans;
    }
    else
        return search(job,element,first,mid-1);
}

ll max_profit(wjs *job,int n)
{
    sort(job,job+n,compare);
    ll *dp=new ll[n];
    dp[0]=job[0].profit;
    for(ll i=1;i<n;i++)
    {
        ll including=job[i].profit;
        ll ncindex=-1;
        ncindex=search(job,job[i].start,0,i-1);
        /*for(int j=i-1;j>=0;j--)
        {
            if(job[j].finish<=job[i].start)
            {
                ncindex=j;
                break;
            }
        }*/
        if(ncindex!=-1)
            including+=dp[ncindex];
        dp[i]=max(dp[i-1],including);
    }
    return dp[n-1];
}

int main()
{
    ll n;
    cin>>n;
    wjs *job=new wjs[n];
    for(ll i=0;i<n;i++)
        cin>>job[i].start>>job[i].finish>>job[i].profit;
    cout<<max_profit(job,n)<<endl;
    return 0;
}
