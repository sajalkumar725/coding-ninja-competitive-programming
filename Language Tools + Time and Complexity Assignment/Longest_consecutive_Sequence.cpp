/*
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 50000
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include<bits/stdc++.h>
using namespace std;

int index(int*arr,int x,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
   vector<int> v;
   int temp = arr[0];
    int *arr2 = new int[n];
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
   sort(arr, arr+n);
int start, end, len, prevStart, prevEnd, prevLen, i;
start = end = 0;
prevLen = 0;
len = 1;
for( i=0; i<n-1; i++ )
{
if( arr[i]+1 == arr[i+1] )
{
end++;
len++;
}
        else if( arr[i] == arr[i+1] )
{
end++;
}
else
{
if(prevLen < len)
{
prevStart = start;
prevEnd = end;
prevLen = len;
}
            if(prevLen == len && index(arr2,arr[prevStart],n)>index(arr2,arr[start],n))
{
prevStart = start;
prevEnd = end;
prevLen = len;
}
start = end = i+1;
len = 1;
}
}
if(prevLen <= len)
{
prevStart = start;
prevEnd = end;
prevLen = len;
}
    if(prevLen > 1){
   for( i=prevStart; i<=prevEnd; i++ )
   {
           
            if(!(i > prevStart && arr[i]==arr[i-1]))
       v.emplace_back(arr[i]);
   }
        return v;
    }
    else{
        cout << temp << endl;
    }
} 
