/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct activity
{
    int start;
    int finish;
}activity;

bool compare(activity a,activity b)
{
    return a.finish<b.finish;
}

int activity_selection(activity *arr,int n)
{
    sort(arr,arr+n,compare);
    int count=1,j=0;
    for(int i=1;i<n;i++)
    {
        if(arr[j].finish<=arr[i].start)
        {
            j=i;
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    activity *arr=new activity[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start>>arr[i].finish;
    }
    int ans=activity_selection(arr,n);
    cout<<ans;
    return 0;
}
