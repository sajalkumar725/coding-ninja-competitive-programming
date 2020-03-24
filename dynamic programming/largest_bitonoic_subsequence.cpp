/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

int longestBitonicSubarray(int *input, int n) 
{
    int lis[n];
    int lds[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
        lds[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(input[j]<input[i])
            {
                int inc=lis[j]+1;
                if(inc>lis[i])
                    lis[i]=inc;
            }
        }
    }
     for (i = n-2; i >= 0; i--) 
      for (j = n-1; j > i; j--) 
         if (input[i] > input[j] && lds[i] < lds[j] + 1) 
            lds[i] = lds[j] + 1;
    int max=lis[0]+lds[0]-1;
    for(i=0;i<n;i++)
    {
        if(max<lis[i]+lds[i]-1)
            max=lis[i]+lds[i]-1;
    }
    return max;
}

