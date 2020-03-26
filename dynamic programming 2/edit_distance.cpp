/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int helper(string s1,string s2,int m,int n,int **dp)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(dp[m][n]>-1)
        return dp[m][n];
    if(s1[m-1]==s2[n-1])
    {
        dp[m][n]=helper(s1,s2,m-1,n-1,dp);
        return dp[m][n];
    }
    int option1=1+helper(s1,s2,m-1,n-1,dp);
    int option2=1+helper(s1,s2,m,n-1,dp);
    int option3=1+helper(s1,s2,m-1,n,dp);
    dp[m][n]=min(option1,min(option2,option3));
    return dp[m][n];
}

int editDistance(string s1, string s2)
{
    int m=s1.length();
    int n=s2.length();
    int **dp=new int*[m+1];
    for(int i=0;i<m+1;i++)
        dp[i]=new int[n+1];
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            dp[i][j]=-1;
    int ans=helper(s1,s2,m,n,dp);
    for(int i=0;i<m+1;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
