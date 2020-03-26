/*
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/

#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;


int lcs2helper(string s1,string s2,int m,int n,int **dp)
{
    if(m==0 || n==0)
        return 0;
    if(dp[m][n]>-1)
        return dp[m][n];
    if(s1[m-1]==s2[n-1])
    {
        dp[m][n]=1+lcs2helper(s1,s2,m-1,n-1,dp);
        return dp[m][n];
    }
    else
    {
        int option1=lcs2helper(s1,s2,m-1,n,dp);
        int option2=lcs2helper(s1,s2,m,n-1,dp);
        int ans=max(option1,option2);
        dp[m][n]=ans;
        return ans;
    }
}


int lcs(string s1, string s2)
{
    int m=s1.length();
    int n=s2.length();
    int **dp=new int*[m+1];
    int i,j;
    for(i=0;i<m+1;i++)
        dp[i]=new int[n+1];
    for(i=0;i<m+1;i++)
        for(j=0;j<n+1;j++)
            dp[i][j]=-1;
    int ans=lcs2helper(s1,s2,m,n,dp);
    for(i=0;i<m+1;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
