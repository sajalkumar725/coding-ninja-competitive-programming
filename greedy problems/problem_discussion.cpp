/*
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Constraints
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
*/
#include<bits/stdc++.h>
using namespace std;

int problem(int *arr,int n,int k)
{
    sort(arr,arr+n);
    for(int i=0;i<n/2;i++)
    {
        arr[i]=arr[i]+k;
    }
    for(int i=n/2;i<n;i++)
    {
        arr[i]=arr[i]-k;
    }
    int a=(*max_element(arr,arr+n));
    int b=(*min_element(arr,arr+n));
    return a-b;
}

int main() 
{
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=problem(arr,n,k);
    cout<<ans<<endl;
}
