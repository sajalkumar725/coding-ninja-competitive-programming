/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/
#include<bits/stdc++.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int getMaxMoney(int arr[], int n)
{
    // int i,ev_sum=0,od_sum=0;
    // for(i=0;i<n;i=i+2)
    //     ev_sum=ev_sum+arr[i];
    // for(i=1;i<n;i=i+2)
    //     od_sum=od_sum+arr[i];
    // if(ev_sum>od_sum)
    //     return ev_sum;
    // return od_sum;
    int i;
    int *dp=new int[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(i=2;i<n;i++)
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    return dp[n-1];
}
