/*
Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Constraints
1 =< N <= 10^5 
1 <= A[i] <= 10^9
Time Limit: 1 second
Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3 
Sample Input2:
3
2 2 4
Sample Output3:
-1 
Explaination
In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1.
*/

#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    int x=-1,y=-1,z=-1;
    int max_perimeter=INT_MIN;
    for(int i=2;i<n;i++)
    {
        //int max_perimeter=INT_MIN;
        int a=arr[i-2];
        int b=arr[i-1];
        int c=arr[i];
        //int x=-1,y=-1,z=-1;
        if(a+b>c && b+c>a && c+a>b)
        {
            int perimeter=a+b+c;
            if(perimeter>max_perimeter)
            {
                max_perimeter=perimeter;
                x=a;
                y=b;
                z=c;
                //continue;
            }
            if(perimeter==max_perimeter)
            {
                int long_side1=max(x,max(y,z));
                int long_side2=max(a,max(b,c));
                if(long_side2>long_side1)
                {
                    x=a;
                    y=b;
                    z=c;
                }
                else if(long_side1==long_side2)
                {
                    int min_side1=min(x,min(y,z));
                    int min_side2=min(a,min(b,c));
                    if(min_side2>min_side1)
                    {
                        x=a;
                        y=b;
                        z=c;
                    }
                }
            }
        }
    }
    if(x==-1 || y==-1 || z==-1)
        cout<<"-1"<<endl;
    else
        cout<<z<<" "<<y<<" "<<x<<endl;
}
