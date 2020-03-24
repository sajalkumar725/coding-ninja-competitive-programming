/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/

int mod=1000000007;
long staircase(int n)
{
    long *arr=new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    long output=arr[n];
    delete [] arr;
    return output;
}

