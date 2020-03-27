/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

int subset_sum(int *arr,int n,int k,int **dp)
{
    if(n==0)
        return 0;
    if(k<0)
        return 0;
    if(n>0 && k==0)
        return 1;
    if(dp[n][k]>-1)
        return dp[n][k];
    if(arr[n-1]<=k)
    {
        int option1=subset_sum(arr,n-1,k,dp);
        int option2=subset_sum(arr,n-1,k-arr[n-1],dp);
        dp[n][k]=(option1 || option2);
        return dp[n][k];
    }
    dp[n][k]=subset_sum(arr,n-1,k,dp);
    return dp[n][k];
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=new int[k+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<k+1;j++)
            dp[i][j]=-1;
    int ans=subset_sum(arr,n,k,dp);
    if(ans==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
