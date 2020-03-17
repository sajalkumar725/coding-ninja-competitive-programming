/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include<bits/stdc++.h>
typedef long long ll;
int m=(pow(10,9))+7;
int balancedBTs(int h) 
{
    if(h==0 || h==1)
        return 1;
    ll x=balancedBTs(h-1)%m;
    ll y=balancedBTs(h-2)%m;
    ll temp=((x%m)*(x%m))+(((2*x)%m)*(y%m));
    return temp%m;
    
}
