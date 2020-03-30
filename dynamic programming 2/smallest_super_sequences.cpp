/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/
#include<bits/stdc++.h>

int helper(char s1[],char s2[],int m, int n,int **dp)
{
    int option1=INT_MAX,option2=INT_MAX,option3=INT_MAX;
    if(m<0)
        return n;
    if(n<0)
        return m;
    if(dp[m][n]>-1)
        return dp[m][n];
    if(s1[m-1]==s2[n-1])
    {
        option1=1+helper(s1,s2,m-1,n-1,dp);
    }
    else
    {
        option2=1+helper(s1,s2,m-1,n,dp);
        option3=1+helper(s1,s2,m,n-1,dp);
    }
    int ans=min(option1,min(option2,option3));
    dp[m][n]=ans;
    return ans;
}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{ 
    int **dp=new int*[len1+1];
    for(int i=0;i<len1+1;i++)
        dp[i]=new int[len2+1];
    for(int i=0;i<len1+1;i++)
        for(int j=0;j<len2+1;j++)
            dp[i][j]=-1;
    int ans=helper(str1,str2,len1,len2,dp);
    for(int i=0;i<len1+1;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
