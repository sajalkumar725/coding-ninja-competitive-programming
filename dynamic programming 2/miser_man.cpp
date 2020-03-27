/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int min_fare(int **arr,int n,int m,int row,int col,int **dp)
{
    int option1=INT_MAX,option2=INT_MAX,option3=INT_MAX;
    if(row==n)
        return 0;
    if(dp[row][col]>-1)
        return dp[row][col];
    if(col-1>=0)
        option1=arr[row][col]+min_fare(arr,n,m,row+1,col-1,dp);
    option2=arr[row][col]+min_fare(arr,n,m,row+1,col,dp);
    if(col+1<m)
        option3=arr[row][col]+min_fare(arr,n,m,row+1,col+1,dp);
    int ans=min(option1,min(option2,option3));
    dp[row][col]=ans;
    return ans;
}

int main()
{
    int n,m,ans=INT_MAX;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                dp[j][k]=-1;
            }
        }
        ans=min(ans,min_fare(arr,n,m,0,i,dp));
    }
    cout<<ans<<endl;
    return 0;
}
