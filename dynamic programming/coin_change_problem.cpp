/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

int temp(int d[],int len,int n,int **output)
{
    if(len==0)
        return 0;
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(output[n][len]>0)
        return output[n][len];
    int first=temp(d,len,n-d[0],output);
    int second=temp(d+1,len-1,n,output);
    output[n][len]=first+second;
    return first+second;
}

int countWaysToMakeChange(int d[], int len, int n)
{
    int **output=new int*[n+1];
    for(int i=0;i<n+1;i++)
        output[i]=new int[len+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<len+1;j++)
            output[i][j]=(-1);
    return temp(d,len,n,output);
}
