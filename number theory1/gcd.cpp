/*
Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
x and y (separated by space)
Output format :
GCD of x and y
Sample Input 1:
20 
5
Sample Output 1:
5
Sample Input 2:
96 
14
Sample Output 2:
2
*/
#include<bits/stdc++.h>
//gcd using __gcd library
/*
int gcd(int a,int b)
{
	return __gcd(a,b);
}*/



//using euclid algorithm (time complexity = log(max(a,b)))
int helper(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return helper(b,a%b);
}

int gcd(int a,int b)
{
    return helper(max(a,b),min(a,b));
}
