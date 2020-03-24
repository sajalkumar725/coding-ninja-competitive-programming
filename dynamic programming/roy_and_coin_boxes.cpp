/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/


#include <bits/stdc++.h>
using namespace std;
/*int main()
{
    int n,m;
    cin>>n>>m;
    int* s = new int[n+1];
    int* e = new int[n+1];
    for(int i=0;i<=n;i++){
        s[i] = 0;
        e[i] = 0;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        s[l]++;
        e[r]++;
    }
    int* A = new int[n+1];
    A[0] = 0;
    A[1] = s[1];
    for(int i=2;i<=n;i++)
        A[i] = s[i] - e[i-1] + A[i-1];
    int* exact = new int[n+1];
    exact[0] = 0;
    for(int i=1;i<=n;i++)
        exact[A[i]]++;
    int* atleast = new int[n+1];
    atleast[0] = n;
    atleast[n] = exact[n];
    for(int i=n-1;i>0;i--)
        atleast[i] = atleast[i+1] + exact[i];
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<atleast[x]<<endl;
    }
    return 0;
}*/

int main()
{
    int n,i,m;
    cin>>n>>m;
    int *s=new int[n+1];
    int *e=new int[n+1];
    
    for(i=1;i<n+1;i++)
    {
        s[i]=0;
        e[i]=0;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        s[l]++;
        e[r]++;
    }
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=s[1];
    for(i=2;i<n+1;i++)
        dp[i]=dp[i-1]+s[i]-e[i-1];
    int *exact=new int[n+1];
    for(i=0;i<n+1;i++)
        exact[i]=0;
    for(i=1;i<n+1;i++)
        exact[dp[i]]++;
    int *atleast=new int[n+1];
    atleast[n]=exact[n];
    for(i=n-1;i>=1;i--)
    {
        atleast[i]=atleast[i+1]+exact[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<atleast[x]<<endl;
    }
    delete [] s;
    delete [] e;
    delete [] dp;
    delete [] exact;
    delete [] atleast;
}

