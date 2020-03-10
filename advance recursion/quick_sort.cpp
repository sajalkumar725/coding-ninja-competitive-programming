/*
Sort an array A using Quick Sort.
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
void swap(int *a,int *b)
{
    int temp;
    temp=(*a);
    *a=(*b);
    *b=temp;
}
int partition(int a[],int start,int end)
{
    int i=start,j=end+1,pivot;
    pivot=a[start];
    while(i<j)
    {
        do{
            i++;
        }while(a[i]<pivot && i<=end);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[start],&a[j]);
    return j;
}
void quick_sort(int input[],int start,int end)
{
    if(start>=end)
        return;
    else
    {
        int pi=partition(input,start,end);
        quick_sort(input,start,pi-1);
        quick_sort(input,pi+1,end);
    }
}
void quickSort(int input[], int size) {
    quick_sort(input,0,size-1);
}
