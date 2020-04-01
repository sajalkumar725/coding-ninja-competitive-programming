/*
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/
#include<bits/stdc++.h>
using namespace std;

string lottery(int s, int d)
{
    int sum=s,n=d;
    int *arr=new int[d];
    //arr[0]=1;
    sum=sum-1;
    for(int i=n-1;i>=1;i--)
    {
        if(sum>9)
        {
            arr[i]=9;
            sum=sum-9;
        }
        else
        {
            arr[i]=sum;
            sum=0;
        }
    }
    arr[0]=sum+1;
    string str;
    for(int i=0;i<n;i++)
    {
        str.push_back(arr[i]+'0');
    }
    return str;
}


int main() 
{
    int s,d;
    cin>>s>>d;
    string ans=lottery(s,d);
    cout<<ans<<endl;
}
