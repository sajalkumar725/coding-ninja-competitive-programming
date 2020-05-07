/*
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Input
First line of the test case will be the number of test case T (1 <= T <= 100000) . Then T lines follows. On each line you will find a integer number n (1 <= n <= 1000000).
Output
For each input line, print a line containing “Case I: ”, where I is the test case number. Then if it is not a cube free number then print “Not Cube Free”. Otherwise print its position among the cube free numbers.
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
Case 1: 1
Case 2: 2
Case 3: 3
Case 4: 4
Case 5: 5
Case 6: 6
Case 7: 7
Case 8: Not Cube Free
Case 9: 8
Case 10: 9
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define eb emplace_back
#define max_size 1000001

ll *fill_array()
{
    ll *arr=new ll[max_size]();
    for(ll i=2;i<=100;i++)
    {
        ll cube=i*i*i;
        for(ll j=cube;j<max_size;j+=cube)
        {
            if(arr[j]!=-1)
            {
                arr[j]=-1;
            }
        }
    }
    return arr;
}

ll *fill_position(ll *arr)
{
	ll *position=new ll[max_size]();
	position[0]=0;
	position[1]=1;
	for(ll  i=2;i<max_size;i++)
	{
		if(arr[i]!=-1)
		{
			position[i]=position[i-1]+1;
		}
		else
		{
			position[i]=position[i-1];
		}
	}
	return position;
}

int main()
{
    ll *arr=fill_array();
    ll *position=fill_position(arr);
    ll t;
    cin>>t;
    ll k=0;
    while(k!=t)
    {
    	ll n;
    	cin>>n;
    	if(arr[n]!=-1)
    	{
    		cout<<"Case "<<k+1<<": "<<position[n]<<endl;
		}
		else
		{
			cout<<"Case "<<k+1<<": "<<"Not Cube Free"<<endl;
		}
		k++;
	}
	delete [] arr;
	delete [] position;
	return 0;
}
