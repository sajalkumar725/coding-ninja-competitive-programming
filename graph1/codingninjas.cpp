/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/
#include<bits/stdc++.h>

void initialize(bool **visited,int N,int M)
{    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}

bool helper(char graph[][MAXN],bool **visited,int n,int m,int i,int j,char str[])
{
    bool ans;
    if(strlen(str)==0)
        return true;
    if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || graph[i][j]!=str[0])
        return false;
    visited[i][j]=true;
    bool ans1=helper(graph,visited,n,m,i-1,j,str+1);
    bool ans2=helper(graph,visited,n,m,i-1,j+1,str+1);
    bool ans3=helper(graph,visited,n,m,i,j+1,str+1);
    bool ans4=helper(graph,visited,n,m,i+1,j+1,str+1);
    bool ans5=helper(graph,visited,n,m,i+1,j,str+1);
    bool ans6=helper(graph,visited,n,m,i+1,j-1,str+1);
    bool ans7=helper(graph,visited,n,m,i,j-1,str+1);
    bool ans8=helper(graph,visited,n,m,i-1,j-1,str+1);
    if(ans1 || ans2 || ans3 || ans4 ||ans5 || ans6 || ans7 ||ans8)
    {
        return true;
    }
    visited[i][j]=false;
    return false;
}

int solve(char Graph[][MAXN],int N, int M)
{
    char str[]="CODINGNINJA";
    bool **visited=new bool*[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=new bool[M];
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
    for(int i=0;i<N;i++)
    {
        bool ans=false;
        for(int j=0;j<M;j++)
        {
            if(!visited[i][j] && Graph[i][j]=='C')
            {
                ans=helper(Graph,visited,N,M,i,j,str);
                if(ans==true)
                    return 1;
                initialize(visited,N,M);
            }
        }
    }
    return 0;
}
