/*
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

long long merge(int a[],int start,int mid,int end,int n)
{
    long long count=0,i=start,j=mid,k=0;
    long long temp[n];
    while(i<mid && j<=end)
    {
        if(a[i]>a[j])
        {
            count=count+mid-i;
            temp[k++]=a[j++];
        }
        else
        {
            temp[k++]=a[i++];
        }
    }
    while(i<mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=end)
    {
        temp[k++]=a[j++];
    }
    k=0;
    for(int i=start;i<=end;i++)
    {
        a[i]=temp[k];
        k++;
    }
    return count;
}
long long merge_sort(int a[],int start,int end,int n)
{
    long long count=0;
    if(start<end)
    {
        long long mid=start+(end-start)/2;
        long long count_left=merge_sort(a,start,mid,n);
        long long count_right=merge_sort(a,mid+1,end,n);
        long long mycount=merge(a,start,mid+1,end,n);
        return mycount+count_left+count_right;
    }
    return count;
}
long long solve(int A[], int n)
{
    long long count=merge_sort(A,0,n-1,n);
    return count;
}
