/*

A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(n).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/


#include<bits/stdc++.h>


// RECURSION
/*
int helper(int *w,int *values,int n,int W,int **dp)
{
    if(n<=0)
        return 0;
    if(W<=0)
        return 0;
    if(dp[n][W]>-1)
        return dp[n][W];
    if(w[n-1]>W)
        dp[n][W]=helper(w,values,n-1,W,dp);
    else
    {
        int option1=helper(w,values,n-1,W-w[n-1],dp)+values[n-1];
        int option2=helper(w,values,n-1,W,dp);
        dp[n][W]=max(option1,option2);
    }
    return dp[n][W];
}


int knapsack(int* weights, int* values, int n, int maxWeight)
{
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=new int[maxWeight+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<maxWeight+1;j++)
            dp[i][j]=-1;
    int ans=helper(weights,values,n,maxWeight,dp);
    for(int i=0;i<n+1;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
*/


// ITERATIVE(SPACE OPTIMIZED)
int knapsack(int* weights, int* values, int n, int W)
{
    int **dp=new int*[2];
    for(int i=0;i<2;i++)
        dp[i]=new int[W+1];
    for(int i=0;i<W+1;i++)
        dp[0][i]=0;
    dp[1][0]=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            dp[flag][j]=dp[flag^1][j];
            if(weights[i-1]<=j)
                dp[flag][j]=max(values[i-1]+dp[flag^1][j-weights[i-1]],dp[flag][j]);
        }
        flag=flag^1;
    }
    int ans=dp[flag^1][W];
    for(int i=0;i<2;i++)
         delete [] dp[i];
    delete [] dp;
    return ans;
}
