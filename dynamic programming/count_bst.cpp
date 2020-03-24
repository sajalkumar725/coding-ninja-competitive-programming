/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/
typedef long long ll;
ll m = pow(10,9)+7;
int countBST(int n){
    ll* dp = new ll[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
   for(int j=0;j<i;j++){
            dp[i] = (dp[i]%m+(dp[j]*dp[i-j-1])%m)%m;
        }
    }
    ll output = dp[n]%m;
    delete [] dp;
    return output;
}


