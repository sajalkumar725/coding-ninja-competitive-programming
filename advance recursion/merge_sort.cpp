/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
*/

#include<bits/stdc++.h>
void merge(int arr[],int start,int mid,int end,int size)
{
    int i=start,j=mid,k=0;
    int temp[size];
    while(i<mid && j<=end)
    {
        if(arr[i]>arr[j])
            temp[k++]=arr[j++];
        else
            temp[k++]=arr[i++];
    }
    while(i<mid)
        temp[k++]=arr[i++];
    while(j<=end)
        temp[k++]=arr[j++];
    k=0;
    for(i=start;i<=end;i++)
    {
        arr[i]=temp[k];
        k++;
    }
}
void merge_sort(int arr[], int start,int end,int size)
{
    if(start>=end)
        return;
    else
    {
        int mid=start+(end-start)/2;
        merge_sort(arr,start,mid,size);
        merge_sort(arr,mid+1,end,size);
        merge(arr,start,mid+1,end,size);
    }
}
void mergeSort(int input[], int size){
    merge_sort(input,0,size-1,size);
}
