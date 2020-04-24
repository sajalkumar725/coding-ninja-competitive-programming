/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/

#include<bits/stdc++.h>
int findString(char s[], char t[])
{
    int n=strlen(s);
    int m=strlen(t);
    int i=0,j=0;
    int index=-1;
    while(i!=n && j!=m)
    {
        if(s[i]==t[j])
        {
            if(j==0)
            {
                index=i;
            }
            i++;
            j++;
        }
        else if(s[i]!=t[j])
        {
            i++;
            j=0;
        }
    }
    if(j==m)
    {
        return index;
    }
    else if(i==n)
    {
        return -1;
    }
}
