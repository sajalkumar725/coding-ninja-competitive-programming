/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/
int helper(string s,string v,int m,int n,int **dp)
{
    if(m==0)
        return 1001;
    if(n==0)
        return 0;
    if(dp[m][n]>-1)
        return dp[m][n];
    int option1=helper(s.substr(1),v,m-1,n,dp);
    int k=v.find(s[0]);
    if(k<0)
        return 1;
    int option2=1+helper(s.substr(1),v.substr(k+1),m-1,n-k-1,dp);
    dp[m][n]=min(option1,option2);
    return dp[m][n];
    
}

int solve(string s,string v)
{
	int m=s.length();
    int n=v.length();
    int **dp=new int*[m+1];
    for(int i=0;i<m+1;i++)
        dp[i]=new int[n+1];
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            dp[i][j]=-1;
    int ans= helper(s,v,m,n,dp);
    for(int i=0;i<m+1;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
